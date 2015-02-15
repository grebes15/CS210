#Demonstartion of arrays
		.data
		.align	2
a:		.space	16
		.text
		.globl	main
main:	la		$t0,a
		li		$t1,7
		sw		$t1,0($t0)
		li		$t1,42
		sw		$t1,4($t0)
		li		$t1,7
		sw		$t1,8($t0)
		li		$t1,17
		sw		$t1,12($t0)
		li		$v0,10
		syscall		