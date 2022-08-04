#include "clientDef.h"

void error(const char* msg);
static int make_socket_non_blocking(int sfd);
static int create_and_bind (char *port);
