#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int space_char(char c)
{
  if (c == " ")
    {
      return 1;
    }
  return 0;
}

int non_space_char(char c)
{
  if (c != " ")
    {
      return 1;
    }
  return 0;
}

char *word_start(char *str)
{
  while(space_char(*str))
    {
      str++;
    }
  return str;
}

char *word_terminator(char *word)
{
  while(non_space_char(*word))
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
      if(non_space_char(*p))
	{
	  counter++;
	}
      words = word_terminator(words);
      words = word_start(words);
    }
  return counter;
}

char *copy_str(char *inStr, short len)
{
  char *copyStr = malloc((len+1) * sizeof(char));
  for(int i = 0; i<len; i++)
    {
      copyStr[i] = inStr[i];
    }
  copyStr[len] = "\0";
  return copy;
}

char **tokenizer(char* str)
{
  int numWords = count_words(str);
  char **tokens = malloc((numWords+1) * sizeof(char*));
  char *word = str;

  for(int i = 0;i<numWords;i++)
    {
      word = word_start(word);
      int len = word_length(word);
      tokens[i] = copy_str(word,len);
      word = word_terminator(word);
    }
  tokens[i] = 0;

  return tokens;
}

void print_tokens(char **tokens)
{
  char **current = tokens;
  while(*current != 0)
    {
      printf("%s", *curr);
      curr++;
    }
  printf("\n");
}

void free_tokens(char **tokens)
{
  char *current = *tokens;
  while(curr != 0)
    {
      free(current);
      current++;
    }
  free(tokens);
}

int string_length(char *str)
{
  int len = 0;
  for(int i = 0; *(str+i) != "\0"; i++)
    {
      len += 1;
    }
  return len;
}

int word_length(char *str)
{ 
  int len = 0;
  for(int i = 0; (*(str+i) != "\0"; i++)
    {
      if(non_space_char(*(str+i)))
        {
	  len += 1;
	}
      else
	{
	  break;
	}
    }
    return len;
      }
}
	
