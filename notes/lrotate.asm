# EXAMPLE OF A FUNCTION:
#
#     l_rotate(int a[], int size)  rotates an array "a" of size "size" one place to the left
#
# This program uses a sample array and calls l_rotate twice; the final result in memory should be
# rotated two places to the left. There is no output--examine memory to see results.

# DATA AREA:
		.data
		.align	2	# make sure we're on a word boundary
x:		.word	10,20,30,40,50,60,70,80	# sample array

# PROGRAM AREA:
		.text
		.globl	main
main:	
		la		$a0,x	# arg1: address of array
		li		$a1,8	# arg2: size of array
		jal		l_rotate	# rotate it
		
		# Do it one more time!
		la		$a0,x	# arg1: address of array
		li		$a1,8	# arg2: size of array
		jal		l_rotate	# rotate it
		
		li		$v0,10	# Exit program
		syscall
		
# Function l_rotate assumes that register $a0 contains the address of an array to be rotated 
# (which we will call "a" from now on) and that register $a1 contains the size of "a" (measured in 
# words, not bytes).
# When the function is finished, the array will be rotated one place to the left.
# There is no return value for this function.
#
# Register map:
#         $t0: used to save the first array element, a[0], until it can be moved to the end
#         $a0: advances through the addresses of the array elements
#         $a1: used as a loop index i, counting down from size-1 to 1
#         $t1: used as a temporary holding location while shifting a[i+1] into a[i]

l_rotate:	lw		$t0,0($a0)		# temp0 = a[0]: save first array element
		subi		$a1,$a1,1		# i = size-1
loop:		beq		$a1,$zero,done	# if i == 0, loop is done
		lw		$t1,4($a0)		# temp1 = a[i+1]
		sw		$t1,0($a0)		# a[i] = a[i+1]: shift an element over one place to the left
		addi		$a0,$a0,4		# advance to the next element in a
		subi		$a1,$a1,1		# i = i-1
		j		loop			# ... and repeat
		
done:		sw		$t0,0($a0)		# a[size-1] = temp0 (old a[0])
		jr		$ra
