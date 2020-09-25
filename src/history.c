#include <stdio.h>
#include <stdlib.h>
#include "history.h"

List* init_history()
{
  List *list = (List*)malloc(sizeof(List)); /*Assigns a memory slot for the list*/
  list->root = (Item*)malloc(sizeof(Item)); /*Assigns a memory slot for each item in the list*/

  return list;
}

void add_history(List *list, char*str)
{
  Item *current = list->root;
  int id = 1;
  while(current->next != 0) /* Will check each item from the list*/
    {
      current = current->next;
      id++;
    }
  current->next = malloc(sizeof(Item)); /*Assigns a memory slot while adding the string*/
  current->next->str = str;
  current->next->id = id;
}

char *get_history(List *list, int id)
{
  Item *current = list->root;

  while(current != 0) /*Will check through the entire list to look for current*/
    {
      if (current->id == id)
	{
	  return current->str;
	}
      current = current->next;
    }
  return "ERROR: ID not found!"; /*This will print only if the item is not on the list*/
}

void print_history(List *list)
{
  Item *current = list->root->next; /*Bypasses the inital empty node*/
  while(current != 0) /*Will check through the entire list to look for current*/
    {
      printf("%d. %s\n",current->id,current->str); /*Prints items on the list along the way*/
      current = current->next;
    }
}

void free_history(List *list)
{
  Item *current = list->root;
  while(current->next != 0) /*Proceeds to free almost all the items until the last one*/
    {
      Item *previous = current;  
      current = current->next;
      free(previous->str);
      free(previous);
    }
  free(current->str); /*Will proceed to free the rest of the list, as well as the list itself*/
  free(current);
  free(list);
}
