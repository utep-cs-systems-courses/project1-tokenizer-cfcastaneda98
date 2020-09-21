#include <stdio.h>
#include <stdlib.h>
#include "history.h"

List* init_history()
{
  List *list = (List*)malloc(sizeof(List));
  list->root = (Item*)malloc(sizeof(Item));

  return list;
}

void add_history(List *list, char*str)
{
  Item *current = list->root;
  int id = 1;
  while(current->next != 0)
    {
      current = current->next;
      id++;
    }
  current->next = malloc(sizeof(Item));
  current->next->str = str;
  current->next->id = id;
}

char *get_history(List *list, int id)
{
  Item *current = list->root;

  while(current != 0)
    {
      if (current->id == id)
	{
	  return current->str;
	}
      current = current->next;
    }
  return "ERROR: ID not found!";
}

void print_history(List *list)
{
  Item *current = list->root->next;
  while(current != 0)
    {
      printf("%d. %s\n",current->id,current->str);
      current = current->next;
    }
}

void free_history(List *list)
{
  Item *current = list->root;
  while(current->next != 0)
    {
      Item *previous = current;
      current = current->next;
      free(previous->str);
      free(previous);
    }
  free(current->str);
  free(current);
  free(list);
}
