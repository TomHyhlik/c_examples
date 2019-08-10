#include <stdio.h>
#define IN 1
#define OUT 0
/* inside a word */
/* outside a word */
/* count lines, words, and characters in input */
main(){
	int c, nl, nw, nc, state;
	state = OUT;
	nl = nw = nc = 0;
	while ((c = getchar()) != EOF) {
		++nc;
		if (c == '0')	// it ends by typing "0"
			break;
		if (c == '\n')
			++nl;
		if (c == ' ' || c == '\n' || c == '\t')
			state = OUT;
		else if (state == OUT) {
		state = IN;
		++nw;
		}
	}
	printf("lines: %d\n words: %d\n characters: %d\n", nl, nw, nc);
}