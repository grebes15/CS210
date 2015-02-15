#import <stdio.h>

int proc1(int i, int j) 
{
    return i - j;
}

int proc2(int i, int j) 
{
    return proc1(i,j) + 1;
}

main() 
{
    int a = 10, b = 20;
    printf("proc2(%d,%d) = %d\n",a,b,proc2(a,b));
}
