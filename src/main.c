#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

#define Max_Size 100

int length(char *str) /*Method that finds and returns the length of a string*/
{
  char *copy = str;

  while(*copy){
    copy++;
  }

  int value = copy - str;   

  return value;
}

int main()
{
  printf("Welcome to the Tokenizer program! Let's get started!");
  List *list = init_history();
  char input[Max_Size];
  int active = 1;

  while(active) /*Will continue using the menu until it returns 0*/
    {
      printf("Please selct from one of the following options:\n");
      printf("1. Input Tokens            == 'i'\n");
      printf("2. View history            == 'h'\n");
      printf("3. View particular History == '!'\n");
      printf("3. Release history         == 'f'\n");
      printf("4. Quit                    == 'q'\n");
      printf("$");

      fgets(input,Max_Size,stdin);
      int stringLen = length(input);

      if(input[0] == 'i') /*Asks the user for the current sentence to use*/
	{
	  printf("Please input the sentence that you want to use:\n");
	  printf("$ ");
	  fgets(input, Max_Size, stdin);
	  char **tokens = tokenize(input);
	  add_history(list,input);
	  print_tokens(tokens);
	  free_tokens(tokens);
	}
      else if(input[0] == 'h') /*Prints the entire history so far*/
	{
	  printf("Printing the history...");
	  print_history(list);
	}
      else if(input[0] == '!' && stringLen == 2 && (input[1] > '0') ) /*Recollects a particlar part of the history*/
	{
	  printf("Recollecting a particular history...");
	  int h = input[1]-'0';
	  char *past = get_history(list,h);
	  char **tokens = tokenize(past);

	  printf("%s\n", past);

	  printf("Tokenized version :\n");
	  print_tokens(tokens);
	  free_tokens(tokens);
	}
      else if(input[0] == 'f') /*Frees the history so far*/
	{
	  printf("Freeing the current history...");
	  free_history(list);
	  printf("Done!");
	}
      else if(input[0] == 'q') /*Quits the program*/
	{
	  printf("See you later, Bye!");
	  free_history(list);
	  active = 0;
	}
      else /*Only for when the user inputs something other than the above*/
	{
	  printf("ERROR! Invalid option!");
	}
    }
}
