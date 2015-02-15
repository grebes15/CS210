				.data
		.align	2
f:		.word	0
g:		.word	15
h:		.word	30
i:		.word	7
j:		.word	3
		.text
		.globl	main
main:	lw		$s1,g
		lw		$s2,h
		lw		$s3,i
		lw		$s4,j
		add		$t0, $s1, $s2
		add		$t1, $s3, $s4
		sub		$s0, $t0, $t4
		sw		$s0,f
