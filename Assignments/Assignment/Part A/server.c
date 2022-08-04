// PLEASE CHECK BUILD INSTRUCTIONS
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <net/if.h>
#include <ifaddrs.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/epoll.h>
#include <errno.h>
#include <signal.h>
#include <string.h>
#include "server.h"
#include "database.h"

#define BUFF_SIZE 256


void error(const char* msg)
{
	perror(msg);
	exit(1);
}

static int make_socket_non_blocking(int sfd)
{
  int flags, s;
  flags = fcntl(sfd, F_GETFL, 0);
  if (flags == -1) error("FCNTL ERROR");
  flags |= O_NONBLOCK;
  s = fcntl (sfd, F_SETFL, flags);
  if (s == -1) error("FCNTL ERROR");
  return 0;
}

static int create_and_bind (char *port)
{
  struct addrinfo hints;
  struct addrinfo *result, *rp;
  int s, sfd;

  memset (&hints, 0, sizeof (struct addrinfo));
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = AI_PASSIVE;

  s = getaddrinfo (NULL, port, &hints, &result);
  if (s != 0)
  {
    fprintf (stderr, "getaddrinfo: %s\n", gai_strerror (s));
    return -1;
  }

  for (rp = result; rp != NULL; rp = rp->ai_next)
  {
    sfd = socket (rp->ai_family, rp->ai_socktype, rp->ai_protocol);
    if (sfd == -1)
      continue;
    s = bind (sfd, rp->ai_addr, rp->ai_addrlen);
    if (s == 0) break;
    close (sfd);
  }
  if (rp == NULL) error("COULD NOT BIND");
  freeaddrinfo (result);
  return sfd;
}




int main()
{
	int sfd,s;
	int efd;
	struct epoll_event event;
	struct epoll_event *events;


  char PORT[20] = "16000";
	sfd=create_and_bind(PORT);
	if (sfd==-1) abort();

	s=make_socket_non_blocking(sfd);
	if(s==-1)
		abort();

	s=listen(sfd,SOMAXCONN);
	if(s==-1)
		error("listen");

	efd=epoll_create1(0);
	if(efd==-1)
		error("epoll_create");

	event.data.fd=sfd;
	event.events=EPOLLIN | EPOLLET;
	s=epoll_ctl(efd, EPOLL_CTL_ADD, sfd, &event);
	if(s==-1)
		error("epoll_ctl");

	events= (struct epoll_event * ) calloc(MAX_NO_OF_EVENTS, sizeof event);

	while(1)
	{
		int n,i;

		n=epoll_wait(efd, events, MAX_NO_OF_EVENTS, -1);
		for(i=0;i<n;i++)
		{
			if((events[i].events & EPOLLERR) || (events[i].events & EPOLLHUP) || (!(events[i].events & EPOLLIN)))
			{
				// An error has occured on this fd, or the socket is not ready
				fprintf(stderr, "epoll error\n");
				close(events[i].data.fd);
				continue;
			}
			else if(sfd ==events[i].data.fd)
			{
				// One or more incoming connections
				while(1)
				{
					struct sockaddr in_addr;
					socklen_t in_len;
					int infd;
					char hbuf[NI_MAXHOST], sbuf[NI_MAXSERV];
					in_len=sizeof(in_addr);
					infd=accept(sfd, &in_addr, &in_len);
					if(infd ==-1)
					{
						if((errno==EAGAIN) || (errno ==EWOULDBLOCK))
							break;
						else
							error("accept");
					}

					s=getnameinfo(&in_addr, in_len, hbuf, sizeof(hbuf),sbuf,sizeof(sbuf), NI_NUMERICHOST | NI_NUMERICSERV);

					if(s==0)
						printf("Accepted connection on client \n");

					s=make_socket_non_blocking(infd);
					if(s==-1)
						abort();

					event.data.fd=infd;
					event.events= EPOLLIN | EPOLLET;
					s=epoll_ctl(efd, EPOLL_CTL_ADD, infd, &event);
					if(s==-1)
						error("epoll_ctl");

				}
				continue;
			}

			else
			{
				int done=0;

				while(1)
				{
					size_t count;
					char buffer[512];

					count=read(events[i].data.fd, buffer, sizeof(buffer));
					if(count==-1)
					{
						if(errno!= EAGAIN)  error("READ ERROR");
						break;
					}
					else if (!count)
					{
						done=1;
						break;
					}

          // PUT
					if(buffer[0]=='p')
					{
            int key;
            char command[20], value[BUFF_SIZE];
            sscanf(buffer, "%s %d %s", command, &key, value);
            printf("%s %d %s", command, key, value);
            int ch = insertKey(key, value);
						if(ch) s=send(events[i].data.fd, "Key already exists", 18,0);
						else s=send(events[i].data.fd, "OK",2,0);
					}
          // GET
					else if(buffer[0]=='g')
					{
            int key;
            char command[20], value[BUFF_SIZE];
            sscanf(buffer, "%s %d", command, &key);
            int ch = getValue(key, value);
						if(!ch) s=send(events[i].data.fd, value, BUFF_SIZE,0);
						else s=send(events[i].data.fd, "Key not found", 13,0);
					}
					else if(buffer[0]== 'd')
					{
            int key;
            char command[20];
            sscanf(buffer, "%s %d", command, &key);
            int ch = deleteKey(key);
						if(ch==0) s=send(events[i].data.fd,"OK",2,0);
						else s=send(events[i].data.fd, "Key not found", 13,0);
					}
					else if(buffer[0]= 'B') s=send(events[i].data.fd, "Goodbye",7,0);
					if(s<0) error("Error writing to socket");
					if(done)
					{
						printf("Closed connection on client\n");
						close(events[i].data.fd);
					}
				}
			}
		}
	}
	free(events);
	close(sfd);
  return EXIT_SUCCESS;
}
