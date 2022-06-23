# include <stdlib.h>
# include <stdio.h>
# include "mystring.h"

int mystrlen(char *s){
  int i=0;
  while(*s){
    i++;
    s++;
  }
  return i;
}

char *mystrcpy(char *dest, char *source){
  char *tmp = dest;
  while(*source){
    *dest = *source;
    dest++;
    source++;
  }
  dest = tmp;
  return dest;
}


char *mystrncat(char *dest, char *source, int n){
  char *tmp = dest;
  while(*dest){
    dest++;
  }
  while(n>0 && *source){
    dest = source;
    dest++;
    source++;
    n--;
  }
  dest = tmp;
  return dest;
}

int mystrcmp(char *s1, char *s2){
  while(*s1 || *s2){
    if(!*s1 || *s1 < *s2){
      return -1;
    }
    else if(!*s2 || *s2 > *s1){
      return 1;
    }
    s1++;
    s2++;
  }
  return 0;
}


char *mystrchr(char *s, char c){
  while(*s){
    if(*s == c){
      return s;
    }
    s++;
  }
  if(*s == c)
    return s;
  return '\0';
}

