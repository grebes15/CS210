#       /* ASSUME a[] is an array of size n. Find sum of elements in a. */
#
#        int count;
#        int sum = 0;
#        for (count = 0; count < n; count++) {
#           sum = sum + a[count];
#        }

		.data
		.align	2	# get to a word boundary
n:		.word	10	# size of array in words
a:		.word	7,-13,25,42,6,-19,4,22,81,-50	# the array
sum:		.word	0	# the sum

# Register usage:
#       $t0:   holds value of n
#       $t1:   loop counter (0, 1, ..., n-1)
#       $t2:   sum of array values
#       $t3:   address of next element in the array
#       $t4:   temp used for comparing counter to n

		.text
		.globl	main
		
main:		lw	$t0,n		# put n in a register; needed for loop termination testing
		add	$t1,$zero,$zero	# set counter to 0
		add	$t2,$zero,$zero # set sum to 0
		la	$t3,a		# load base address of array a
		
loop:		slt	$t4,$t1,$t0	# check to see if count < n
		beq	$t4,$zero,done	# exit loop if count >= n
		lw	$t5,0($t3)
		add	$t2,$t2,$t5	# add next array element
		addi	$t3,$t3,4	# advance to next address in array
		addi	$t1,$t1,1	# increment the counter
		j	loop		# go back to top of loop
		
done:		sw	$t2,sum		# save the sum in memory
		li	$v0,10		# code for "exit"
		syscall
		
		
		
