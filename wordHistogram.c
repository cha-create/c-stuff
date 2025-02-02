#include <stdio.h>

#define IN 1
#define OUT 0

int main() {
    int c, nl, nw, nc, cw, state;
    int wordListLength[10];

    state = OUT;
    nl = nw = nc = cw = 0;

    for (int i = 0; i < 10; i++) {
        wordListLength[i] = 0; // Properly initialize the array
    }

    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == '\n') {
            ++nl;
        }
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state == IN) {
                // Save word length before exiting a word
                if (cw < 10) {
                    ++wordListLength[cw];
                }
                cw = 0; // Reset word length
            }
            state = OUT;
        } else if (state == OUT) {
            state = IN;
            ++nw; // Start a new word
        }
        if (state == IN) {
            ++cw; // Increment word length
        }
        if (c == '`') { // Exit condition
            printf("Exiting...\n");
            printf("Lines: %d, Words: %d, Chars: %d\n", nl, nw, nc);
            for (int i = 1; i < 10; i++) { // Print histogram for words of length 1-9
                printf("%d |", i);
                for (int j = 0; j < wordListLength[i]; j++) {
                    putchar('#');
                }
                putchar('\n');
            }
            return 0;
        }
    }
    return 0;
}
