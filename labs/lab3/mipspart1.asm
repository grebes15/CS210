	.data
	.align	2
x:	.space	4 #byte depth
y:	.space	4 # byte depth
z:	.space	4 # byte depth
p1:	.asciiz	"Enter 1st value to be entered: "
p2:	.asciiz	"Enter 2nd value to be entered: "
sum:	.asciiz	"The sum of the two values is: "
nl:	.asciiz	"\n"

	.align	2
	.text
	.globl	main
main:	li	$v0, 4 #load the string
	la	$a0, p1 #load the string into p1
	syscall #system call 
	
	li	$v0,5 #read an interger
	syscall
	sw	$v0,x #store the integer into x
	
	li	$v0,4 #load a string
	la	$a0,p2 #load the address of a string into p2
	syscall
	
	li	$v0,5 # load an interger
	syscall
	sw	$v0,y #store the word into y

	lw	$s0,x #load the integer of x
	lw	$s1,y #load the interger of y
	add	$t0, $s0, $s1 # add x and y and store into $t0
	sw	$t0,z #store the result into z
	li	$v0,4 #load a string
	la	$a0,sum #load the address into sum
	syscall
	li	$v0,1 #print the interger
	lw	$a0,z #load and print the integer that is in z
	syscall
	li	$v0,4 #load a string
	la	$a0,nl # load the new line
	syscall
	
	li	$v0,10 #terminate the program	
	syscall		

