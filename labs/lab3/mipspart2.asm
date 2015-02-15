		.data
		.align	2
len:		.word	20	
s1:		.space	20
len2:	 	.word	20
s2:		.space	20

p1:		.asciiz	"First name: "
p2:		.asciiz	"Last name: "
l1:		.asciiz	"Hello, "
l2:		.asciiz	"!"
nl:		.asciiz	"\n"

	.text
	.globl	main
main:	li	$v0,4 # print a string
	la	$a0,p1 # load the address into p1
	syscall
	
	li	$v0,8 #read a string
	la	$a0,s1 #load the address into s1
	lw	$a1,len #sload the string into len
	syscall
	
	li	$v0,4 # print a string 
	la	$a0,p2 # load the address into p2
	syscall	
	
 	li	$v0,8 # load a string 
 	la	$a0,s2 # load the address of the printer string into s2
 	lw	$a1,len2 #load the string into len2
 	syscall
 	
 	li	$v0,4 # print a string 
 	la	$a0,l1 # load the address into l1
 	syscall
 	
 	li	$v0,4 # print a string
 	la	$a0,s1 #load the string into s1
 	syscall
 	
 	li	$v0,4 #print a string
 	la	$a0,s2 #load the string address into s2
 	syscall
 	 
	li	$v0,4 #print a string
	la	$a0,nl  #print out so it starts a new line	
 	
 	li	$v0,10
 	syscall # terminate the program
