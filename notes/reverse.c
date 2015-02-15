/* Reverses a line of input typed by the user.
 * Demonstration of character-by-character line input using an array.
 *
 * Function "readline" is based upon function "getline" on page 29 of 
 * Kernighan & Ritchie.
 *
 * Usage:
 *        gcc reverse.c -o reverse
 *        ./reverse
 */

#include <stdio.h>
#define MAXLINE 81

/* Function prototype: (based on p29, K&R). See below for definition. */
int readline(char *line, int lim);

int main()
{
    char line[MAXLINE]; /* a line of input; add one extra for null character */
    int i;         /* loop index */
    int len;       /* length of input line */

    printf("Enter a line of text: ");
    len = readline(line,MAXLINE);
    printf("Length = %d\n",len);

    /* Print out line in reverse: */
    for (i = len-1; i>= 0; i--)
    {
        printf("%c",line[i]);
    }
    printf("\n");
}

/* Reads in a line of up to "lim-1" characters, storing them in array "line";
 * terminates the line with a null character '\0'. Assume array has size
 * at least lim.
 * 
 * User input is terminated by either an end-of-file or a newline character.
 * The "\n" character is treated as part of the line and is stored in the array.
 *
 * Returns the number of characters read (not including the terminating null char).
 */

int readline(char *line, int lim)
{
    int i;  /* loop counter and array index */
    char c; /* current character read in */

    /* Loop while under the length limit and while input is not EOF or newline: */
    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        line[i] = c;
    }

    /* If input ended with \n, include that: */
    if (c == '\n') {
        line[i] = c;
        ++i;
    }

    /* Put a null character in last position: */
    line[i] = '\0';

    return i; /* i contains length of string (not including \0) */
}
