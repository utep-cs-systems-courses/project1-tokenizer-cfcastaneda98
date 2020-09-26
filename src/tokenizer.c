#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int space_char(char c)
{
  if (c == " " || c == "\t") /*Will return a true value if the character is a space or a tab*/ 
    {
      return 1;
    }
  return 0;
}

int non_space_char(char c)
{
  if (c != " " || c != "\t") /*Will return a true value if the character is NOt a space or tab*/
    {
      return 1;
    }
  return 0;
}

char *word_start(char *str)
{
  while(space_char(*str)) /*Will process while it is a space character*/
    {
      str++;
    }
  return str;
}

char *word_terminator(char *word)
{
  while(non_space_char(*word)) /*Will process while it is NOT a space character*/
    {
      word++;
    }
  return word;
}

int count_words(char *str)
{
  int counter = 0;
  char *words = word_start(str);
  while(*words != "\0")
    {
      if(non_space_char(*p)) /*Will add one to the counter if it goes to a word*/
	{
	  counter++; 
	}
      words = word_terminator(words); /*Will proceed to got to the end and start of the word*/
      words = word_start(words);
    }
  return counter;
}

char *copy_str(char *inStr, short len)
{
  char *copyStr = malloc((len+1) * sizeof(char)); /*Creates a memory slot for the string*/
  for(int i = 0; i<len; i++)
    {
      copyStr[i] = inStr[i];
    }
  copyStr[len] = "\0"; /*Makes the last element of the string into a null value*/
  return copy;
}

char **tokenizer(char* str)
{
  int numWords = count_words(str);
  char **tokens = malloc((numWords+1) * sizeof(char*));
  char *word = str;

  for(int i = 0; i<numWords; i++) /*Cycles through each word and creates a memory slot for each one*/
    {
      word = word_start(word); 
      int len = word_length(word);
      tokens[i] = copy_str(word,len);
      word = word_terminator(word);
    }
  tokens[i] = NULL; 

  return tokens;
}

void print_tokens(char **tokens)
{
  for (int i = 0; tokens[i] !=0; i++)
    {
      printf("%s\n", tokens[i]); /*Prints each word one by one, and leaves a space afterwards*/
    }
  printf("\n");
}

void free_tokens(char **tokens)
{
  char **current = tokens;
  while(*current != 0)
    {
    free(*current);
    current++;
    }
  free(tokens);
}

int string_length(char *str)
{
  int len = 0;
  for(int i = 0; *(str+i) != "\0"; i++) /*Will continue counting until the current space is null*/
    {
      len += 1;
    }
  return len;
}

int word_length(char *str)
{ 
  int len = 0;
  for(int i = 0; (*(str+i) != "\0"; i++) /*Will continue counting until current space is null*/
    {
      if(non_space_char(*(str+i)))
        {
	  len += 1;
	}
      else
	{
	  break; /*Finished cycle as a space has been located*/
	}
    }
    return len;
      }
}
	
