#include <stdio.h>

#define IN 1
#define OUT 0

int main() {
  int c, nl, nw, nc, state;

  
  state = OUT;
  nl = nw = nc = 0;
  while((c = getchar()) != EOF) {
    ++nc;
    if(c == '\n') {
      ++nl;
    }
    if(c == ' ' || c == '\n' || c == '\t') {
      state = OUT;
    }
    if(c == '`') {
      printf("Exiting...");
      printf("Lines: %d, Words: %d, Chars: %d", nl, nw, nc);
      return 0;
    }
    else if (state == OUT) {
      state = IN;
      ++nw;
      putchar('\n');
    }
    putchar(c);
  }
  return 0;
}