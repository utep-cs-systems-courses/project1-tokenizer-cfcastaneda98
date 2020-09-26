#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

void tokenScanner(List *list, char **tokens)

void tokenScanner(List *list, char **tokens)
{
  int len = 0;
  int wid = 0;
  char stringToken = malloc(100*sizeof(char));
  char *current = token_str;
  for(int i = 0; i<50; i++)
    {
      current[i] = tokens[wid][len];
      len++;
      if(tokens[wid] == 0)
	{
	  current[++i] = "\0";
	  break;
	}
      if(tokens[wid][len] == "\0")
	{
	  len = 0;
	  wid++;
	  current[++i] = " ";
	}
    }
  add_history(list, stringToken);
  free(stringToken);
}

int main
{
  printf("Welcome to the Tokenizer program! Let's get started!");
  List *list = init_history();
  char input[50];

  while(1) /*Will continue using the menu until it returns 0*/
    {
      printf("Please selct from one of the following options:\n");
      printf("1. Input Tokens            == 'i'\n");
      printf("2. View history            == 'h'\n");
      printf("3. View particular History == '!'\n");
      printf("3. Release history         == 'f'\n");
      printf("4. Quit                    == 'q'\n");

      fgets(input,50,stdin);

      if(input[0] == "i") /*Asks the user for the current sentence to use*/
	{
	  printf("Please input the sentence that you want to use:\n");
	  printf("$ ");
	  fgets(input, 50, stdin);
	  char **tokens = tokenize(input);
	  tokenScanner(history, tokens);
	  add_history(history,tokens);
	  print_tokens(tokens);
	  free_tokens(tokens);
	}
      else if(input[0] == "h") /*Prints the entire history so far*/
	{
	  printf("Printing the history...");
	  print_history(list);
	}
      else if(input[0] == "!") /*Recollects a particlar part of the history*/
	{
	  printf("Recollecting a particular history...");
	  char *past = get_history(history,atoi(input+1));
	  char **tokens = tokenize(past);

	  printf("%s\n", past);

	  printf("Tokenized version :\n");
	  print_tokens(tokens);
	  free_tokens(tokens);
	}
      else if(input[0] == "f") /*Frees the history so far*/
	{
	  printf("Freeing the current history...");
	  free_history(list);
	  printf("Done!");
	}
      else if(input[0] == "q") /*Quits the program*/
	{
	  printf("See you later, Bye!");
	  free_history(list);
	  return 0;
	}
      else /*Only for when the user inputs something other than the above*/
	{
	  printf("ERROR! Invalid option!");
	}
    }
}


