/**
 * Determine English bigram frequencies for consonant-vowel combinations.
 *
 * In other words, for a given English text, figure out how often
 * each letter pair of the form "consonant vowel" appears. For instance,
 * we would expect that "ca" and "qu" are much more frequent than
 * "xa" or "qa".
 *
 * Usage:
 *       gcc bigram.c -o bigram
 *       ./bigram < textfile
 *
 * The text of "War and Peace" is provided as a test data file.
 */

#include <stdio.h>
#include <ctype.h>

/* Function prototypes. Actual function definitions are at end of file. */
int isvowel(char c);
int isconsonant(char c);

main()
{
     /* For purposes of keeping track of row and column numbers, */
     /* the following array lists the row or column index for    */
     /* each letter. For vowels, the entry is a column number,   */
     /* for consonants the entry is a row number.                */   
    int lookup[] = {0,0,1,2,1,3,4,5,2,6,7,8,9,10,3,
                 /* a b c d e f g h i j k l m  n o */
                   11,12,13,14,15,4,16,17,18,19,20};
                 /* p  q  r  s  t u  v  w  x  y  z */

     /* We also need to be able to do the reverse for rows, since */
     /* we wish to print out the consonant corresponding to each  */
     /* row. Here is a "reverse lookup table" for consonants.     */
    int conslabel[] = {'B','C','D','F','G','H','J','K','L','M','N',
                       'P','Q','R','S','T','V','W','X','Y','Z'};

    int table[21][5]; /* bigram frequencies; rows = consonants, cols = vowels*/
    char c;       /* the current input character */
    int cons, vow; /* index (in the alphabet) of current consonant or vowel */
    int needvowel; /* boolean flag--set to 1 when we've just seen a consonant */
    int i, j;      /* loop indices for accessing table */

    for (i = 0; i < 21; i++)    /* initialize all frequencies to zero */
        for (j = 0; j < 5; j++)
            table[i][j] = 0;

    /* Loop over input, character by character. Initially, we haven't */
    /* seen any consonants, so needvowel is initially false:          */
    needvowel = 0;
    while ((c = getchar()) != EOF)
    {
        c = toupper(c);    /* so we don't have to worry about case */
        if (isconsonant(c))
        {
            cons = c-'A';   /* location in alphabet */
            needvowel = 1;  /* see if next char is a vowel */
        }
        else if (isvowel(c) && needvowel) /* c = vowel; previous = consonant */
        {
            vow = c-'A';  /* location in alphabet */
            table[lookup[cons]][lookup[vow]]++; /* find, update table entry */
            needvowel = 0; /* wait until we see another consonant */
        }
        else /* c is neither a vowel nor a consonant: */
        {
            needvowel = 0;
        }
    }

    /* Print out the frequency table: */

    printf("   Consonant-Vowel Bigram Frequencies\n\n");
    printf("      A      E      I      O      U\n");
    for (i = 0; i < 21; i++) {
        printf("   +------+------+------+------+------+\n");
        printf("%2c |",conslabel[i]);   /* label row with consonant */
        for (j = 0; j < 5; j++) {
            printf("%6d|",table[i][j]); /* for each vowel, print entry */
        }
        printf("\n");
    }
    printf("   +------+------+------+------+------+\n");
}

/**************************************************************************/

/**
 * isvowel returns true if c is a vowel. Only uppercase letters are
 * considered.
 */
int isvowel(char c)
{
    if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        return 1;
    return 0;
}

/**************************************************************************/

/**
 * isconsonant returns true if c is a consonant. Only uppercase letters are
 * considered.
 */
int isconsonant(char c)
{
    if ((c >= 'B' && c <= 'D') || 
        (c >= 'F' && c <= 'H') || 
        (c >= 'J' && c <= 'N') ||
        (c >= 'P' && c <= 'T') ||
        (c >= 'V' && c <= 'Z'))
        return 1;
    return 0;
}
