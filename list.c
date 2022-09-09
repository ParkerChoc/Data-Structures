 /*
 * Name: Parker Choc
 * Email: chocp@oregonstate.edu
 */

#include <stdlib.h>
#include<stdio.h>
#include <assert.h>
#include "list.h"

struct link
{
  void* val;
  struct link* next;
};

struct list
{
  struct link* head;
};

struct list* list_create()
{
  struct list* a = malloc(sizeof(struct list));
  a->head = NULL;
  return a;
}

void list_free(struct list* list)
{
  struct link* a = list->head;
  struct link* b;
  while (a != NULL)
  {
    b = a->next;
    free(a);
    a = b;
  }
  free(list);
}

void list_insert(struct list* list, void* val)
{
  struct link* a = list->head;
  list->head = malloc(sizeof(struct link));
  list->head->val = val;
  list->head->next = a;
}
/*
void list_print(struct list* list)
{
  struct link* a = list->head;
  struct link* b;
  while (a != NULL)
  {
    b = a->next;
    printf("Data: %d\n", *((int *)a->val));
    a = b;
  }
}
*/
void list_remove(struct list* list, void* val, int (*cmp)(void* a, void* b))
{
  struct link* current_link = list->head;
  struct link* next_link;
  while (current_link != NULL)
  {
    next_link = current_link->next;
    if (cmp(val, next_link->val) == 0) 
    {
      current_link->next = next_link->next;
      free(next_link);
      return;
    }
    current_link = current_link->next;
  }
}

int list_position(struct list* list, void* val, int (*cmp)(void* a, void* b))
{
  struct link* location = list->head;
  int counter = 0;
  while (location != NULL)
  {
    if (cmp(val, location->val) == 0) 
    {
      return counter;
    }
    location = location->next;
    counter++;
  }
  return -1;
}

void list_reverse(struct list* list)
{
  struct link* previous_link = NULL;
  struct link* current_link = list->head;
  struct link* next_link;
  while (current_link != NULL) 
  {
    //Move through the list, making the pointers point backwards
    next_link = current_link->next;
    current_link->next = previous_link;
    previous_link = current_link;
    current_link = next_link;
  }
  list->head = previous_link; //Finally fix head
}