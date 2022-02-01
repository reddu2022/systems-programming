#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct key_words
{
  char *key_word;
  int count=0;
};

int main (int argc,char *argv[])
{
  struct key_words *str,key;
  int i, n;
  char *ww;
  const char s[2] = " ";
  //printf ("Enter the number of keywords: ");
  //scanf ("%d", &n);
  n = argc -1;
  printf ("Enter the number of keywords:%d\n ",n);
  str = (struct key_words *) malloc (n * sizeof ( key)); // allocating memory for n numbers 
  for (i = 1; i <= n; i++)
    {
       str[i-1].key_word = argv[i];
    }

 
  char *strline = NULL;
  size_t max = 0;
  ssize_t t;

  while ((t = getline (&strline, &max, stdin)) >= 1)
  {

	  ww = strtok (strline, " ,\n.");
	  while (ww != NULL)
	  {
		  for (i = 0; i < n; i++)
		  {

			  if (strcmp (ww, (str + i)->key_word) == 0)
			  {
				  (str + i)->count++;
			  }
		  }
		  ww = strtok (NULL, " \n,.");
	  }

  }
  for (i = 0; i < n; i++)
	  printf ("String: %s\t count:%d\n", (str + i)->key_word, (str + i)->count);
  return 0;
}
