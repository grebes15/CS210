/*Andreas Landgrebe
Computer Science 210
Fall Semseter 2013

*/

#include <stdio.h>


void resetarray(int x[],int size) {//this function will reset the array so after the rotation is made, it will reset to its original form
  int i;
  for (i=0;i<size;i++) x[i]=i;
}


void printarray(int x[],int size){//will print the array in the proper way 
  int i;
  for (i=0;i<size;i++) printf("%d ",x[i]);
  printf("\n");

}


//function to rotate the array for 1 position. Since suggested that we were not supposed to create a temporary array, this function will rotate one time and then will be called multiple times to rotate a certain amount of times 
void rotate1position(int x[], int size)
{
  int i,temp;
  temp = x[0];
  for (i=1;i<size;i++ ){
    x[i-1]=x[i];
  }

  x[size-1]=temp;

}

//function will detect if rotate1position is called in multiple times, then rotate function will detect to only rotate a certain amount of times depending on the size of the array. For example, if the array size is 5 and is told to rotate 25 times, this function will only rotate it 5 times and get the same result.
void rotate( int x[], int size, int amount)
{
int shift;
int i;
shift = amount % size;

  for (i=0;i<shift;i++) rotate1position(x,size);
}

int main () //main method to execute the functions listed above
{

  int a[10],b[15],c[20]; 
  int sizea,sizeb,sizec;
  sizea=10; //declaring the sizes of the array
  sizeb=15;
  sizec=20;

  resetarray(a,sizea);
  rotate(a,sizea,4);
  printf("After rotating by 4, array a =\n");
  printarray(a,sizea);

  resetarray(a,sizea); //reset the array to its original
  rotate(a,sizea,-30);
  printf("After rotating by -30, array a =\n");
  printarray(a,sizea); 

  resetarray(a,sizea);
  rotate(a,sizea,17);
  printf("After rotating by 17, array a =\n");
  printarray(a,sizea);

  resetarray(b,sizeb);
  rotate(b,sizeb,4);
  printf("After rotating by 4, array b =\n");
  printarray(b,sizeb);

  resetarray(b,sizeb);
  rotate(b,sizeb,-30);
  printf("After rotating by -30, array b =\n");
  printarray(b,sizeb);


  resetarray(b,sizeb);
  rotate(b,sizeb,17);
  printf("After rotating by 17, array b =\n");
  printarray(b,sizeb);

  resetarray(c,sizec);
  rotate(c,sizec,4);
  printf("After rotating by 4, array c =\n");
  printarray(c,sizec);

  resetarray(c,sizec);
  rotate(c,sizec,-30);
  printf("After rotating by -30, array c =\n");
  printarray(c,sizec);

  resetarray(c,sizec);
  rotate(c,sizec,17);
  printf("After rotating by 17, array c =\n");
  printarray(c,sizec);


}
