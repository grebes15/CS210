	.data
	.align	2
i:	.space	4
j:	.space	4
max:	.space	4
pr:	.asciiz	"Enter two integers: "
lab:	.asciiz	"max = "
nl:	.asciiz	"\n"

	.text
	.globl	main
main:	li	$v0,4	# code for print string
	la	$a0,pr	# the prompt
	syscall		# print the prompt
	
	li	$v0,5	# code for read int
	syscall		# read it into $v0
	sw	$v0,i

	li	$v0,5	# code for read int
	syscall		# read it into $v0
	sw	$v0,j
	
	lw	$s0,i
	lw	$s1,j
	slt	$t0,$s0,$s1	# if i < j, t0 = 1, else t0 = 0
	bne	$t0,$zero,else
	sw	$s0,max
	j	done
else:	sw	$s1,max
done:	li	$v0,4	# code for print string
	la	$a0,lab	# output label
	syscall		# print the label
	
	li	$v0,1	# code for print int
	lw	$a0,max	# the computed maximum
	syscall		# print the maximum value
	
	li	$v0,4	# code for print string
	la	$a0,nl	# newline character
	syscall		# print the newline
	
	li	$v0,10	# code for exit
	syscall		# exit

