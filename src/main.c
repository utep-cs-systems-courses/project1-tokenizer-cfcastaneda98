#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

void tokenScanner(List *list, char **tokens);

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

  while(1)
    {
      printf("Please selct from one of the following options:\n");
      printf("1. Input Token             == 't'\n");
      printf("2. View history            == 'h'\n");
      printf("3. View particular History == '!'\n");
      printf("3. Release history         == 'f'\n");
      printf("4. Quit                    == 'q'\n");

      fgets(input,50,stdin);

      if(input[0] == 't')
	{
	  printf("Please input the sentence that you want to use:\n");
	  fgets(input, 50, stdin);
	  char **tokens = tokenize(input);
	  tokenScanner(history, tokens);
	  print_tokens(tokens);
	  free_tokens(tokens);
	}
      else if(input[0] == 'h')
	{
	  printf("Printing the history...");
	  print_history(list);
	}
      else if(input[0] == '!')
	{
	  printf("Recollecting a particular history...");
	  printf("%s\n", get_history(list, input[1]-48));
	}
      else if(input[0] == 'f')
	{
	  printf("Freeing the current history...");
	  free_history(list);
	}
      else if(input[0] == 'q')
	{
	  printf("See you later, Bye!");
	  free_history(list);
	  return 0;
	}
      else
	{
	  printf("ERROR! Invalid option!");
	}
    }
}


