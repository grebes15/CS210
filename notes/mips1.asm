# Bob Roos
# This computes f = (g+h) - (i+j)
# See pages 79-80 in Patterson & Hennessy
	.data
	.align 	2	# make sure we're on a word boundary
f:	.word 	0	# f = final result
g:	.word	15	# initial values of g, h, i, j defined here
h:	.word	30
i:	.word	7
j:	.word	3

	.text
	.globl	main    	# identifies program entry point
main:	lw	$s1,g		# save variable values in registers s1-s4
	lw	$s2,h
	lw	$s3,i
	lw	$s4,j
	add	$t0,$s1,$s2	# temp result: temp0 = g+h
	add	$t1,$s3,$s4	# temp result: temp1 = i+j
	sub	$s0,$t0,$t1	# final result: temp0 - temp1
	sw	$s0,f      	# save result in f
	li	$v0,10     	# 10 = system call code meaning "exit program"
	syscall            	# exit program
