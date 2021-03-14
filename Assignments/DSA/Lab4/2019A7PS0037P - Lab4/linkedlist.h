#include <stdio.h>
#include <stdlib.h>

struct node {
    int element;
    struct node * next;
};

/*structure of a linked list / head. It stores the count of number of elements in the list and also a pointer link to the first node of the list. */
struct linkedList {
    int count;
    struct node * first;
};

// function declarations
extern void insertFirst(struct linkedList * head, int ele);
/* inserts a given element at the beginning of the list*/

extern struct node * deleteFirst(struct linkedList * head);
/*deletes the first element of the listand returns pointer to the deleted node.*/

extern void printList (struct linkedList * head);
/* prints all the elements in the list*/

extern int search (struct linkedList * head, int ele);
/*searches  for  a  given elementin  the  linked  list.  Returns  1  if  found,  0 otherwise.*/

extern struct node * delete (struct linkedList * head, int ele);
/*deletes  the first  nodeinthe  list  that  contains  the  element  = eleand retuns  it.If  the  element  is  not  found  it  returns anerror  message  saying element not found.*/
