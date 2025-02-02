#include <stdio.h>
#include <string.h>
#define MAXLINE 1000



int getlength(char s[], int lim) {
  int c, i;

  for(i=0; i<lim-1 && (c=getchar()) != EOF && c!='\n'; ++i) {
    s[i] = c;
  }
  if(c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

void copy(char to[], char from[]) {
  int i;

  i = 0;
  while((to[i] = from[i]) != '\0') {
    ++i;
  }
}

void exitProgram(char longstring[]) {
    printf("%s", longstring);
}

int main() {
  int len;
  int max;
  char line[MAXLINE];
  char longest[MAXLINE];

  max = 0;
  while((len = getlength(line, MAXLINE)) > 0) {
    if (len > max) {
      max = len;
      copy(longest, line); 
      for (int i = 0; i < strlen(longest); ++i) {
        char c = longest[i];
        if (c == '`') {
          exitProgram(longest);
        }
      }
    }
  }
  if(max > 0) {
    exitProgram(longest);
  }
  return 0;
}
