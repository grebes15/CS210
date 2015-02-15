#include <stdio.h>
#include <time.h>

/* Function prototypes (see below for definitions): */
void fill(int a[], int size);  /* fill an array a */
void print(int a[], int size); /* print an array a */


main()
{
    int a[5], b[10], c[15]; /* three arrays of varying size */
    time_t now;

    time(&now);

    printf("Bob Roos\n%s\n",ctime(&now));

    /* Fill arrays and print them: */
    fill(a,5);
    fill(b,10);
    fill(c,15);

    printf("a = ");
    print(a,5);

    printf("b = ");
    print(b,10);

    printf("c = ");
    print(c,15);
}

/*
 * Fills an array a of given size with consecutive integers 1, 2, ...
 */
void fill(int a[], int size)
{
    int i;
    for (i = 1; i <= size; i++)
        a[i-1] = i;
}

/*
 * Prints an array a of given size
 */
void print(int a[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ",a[i]);
    printf("\n");
}
