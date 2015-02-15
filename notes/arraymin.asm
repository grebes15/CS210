# Find the minimum value in an array a of size n
#
#         int min = 0x7FFFFFFF;  /* largest possible positive integer */
#         int i;      /* loop counter */
#         for (i = 0; i < n; i++) {
#             if (a[i] < min) {
#                  min = a[i];
#             }
#         }
#         printf("Minimum value is %d\n",min);

		.data
		.align	2	# get to a word boundary
n:		.word	15	# size of the array
a:		.word	5,4,3,2,1,6,7,8,9,10,0,-1,11,-2,12   # the array
min:		.space	4	# space to hold the minimum
label:		.asciiz	"Minimum value is "	# for labeling output
endline:	.asciiz	"\n"			# newline character

# Register usage:
#	$t0:  holds value of n, the array size (for loop termination testing)
#	$t1:  loop counter i = 0,1,...,n-1
#	$t2:  minimum so far
#	$t3:  address of current array element
#	$t4:  temp used for comparison testing
#	$t5:  holds current array element

		.text
		.globl	main			# identify entry point of program
main:		lw	$t0,n			# array size (needed for loop termination test)
		add	$t1,$zero,$zero		# i = 0
		li	$t2,0x7fffffff		# min = MAX POSSIBLE INTEGER
		la	$t3,a			# base address of the array
		
loop:		slt	$t4,$t1,$t0		# see if i < n
		beq	$t4,$zero,done		# if not, loop is finished
		lw	$t5,0($t3)		# get current array element a[i]
		slt	$t4,$t5,$t2		# see if a[i] is less than min
		beq	$t4,$zero,skip		# if not, skip around next statement
		add	$t2,$zero,$t5		# found a new min: set min = a[i]
skip:		addi	$t1,$t1,1		# i = i+1
		addi	$t3,$t3,4		# advance to next array element
		j	loop			# repeat
		
done:		sw	$t2,min			# save min in memory
		li	$v0,4			# code for printing a string
		la	$a0,label		# address of string to be printed
		syscall				# print the string
		
		li	$v0,1			# code for printing an int
		lw	$a0,min			# the int to be printed
		syscall				# print the int
		
		li	$v0,4			# code for printing a string
		la	$a0,endline		# address of string to be printed
		syscall				# print the string
		
		li	$v0,10			# exit code
		syscall				# terminate program
		