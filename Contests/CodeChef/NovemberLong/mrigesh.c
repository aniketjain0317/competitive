#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next; // Pointer to next node in DLL
    struct Node* prev; // Pointer to previous node in DLL
};

void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    new_node->prev = NULL;
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;
    (*head_ref) = new_node;
}

void deleteNode(struct Node** head_ref, struct Node* del)
{
    if (*head_ref == NULL)
        return;
    if (*head_ref == del)
        *head_ref = del->next;
    if (del->next != NULL)
        del->next->prev = del->prev;
    if (del->prev != NULL)
        del->prev->next = del->next;
    struct Node* curr = del ->next;
    free(del);
}

void deleteAllK(struct Node** head_ref, int k)
{
  struct Node* curr = *head_ref;
  while(curr!=NULL)
  {
    if(curr->data==k)
    {
      struct Node* del = curr;
      curr = curr->next;
      deleteNode(head_ref, del);
    }
    else curr = curr->next;
  }
}

void printList(struct Node* node)
{
    while (node != NULL)
    {
        printf("%d ",node->data);
        node = node->next;
    }
}

int main()
{
    struct Node* head = NULL;
    push(&head, 2);
    push(&head, 4);
    push(&head, 2);
    push(&head, 6);
    push(&head, 2);

    printList(head); printf("\n");
    deleteAllK(&head, 2);
    printList(head); printf("\n");

}
