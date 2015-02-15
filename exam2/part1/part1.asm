#Andreas Landgrebe
#November 16, 2013
#Take-Home Exam
#Part 1 of the Exam where I will
#Place an integer n into the $a0 register, if it is even, compute n/2 and display the result.
#if it is odd, compute 3n + 1 and display the retult.
	.data
	.align 2
inp:	.asciiz "Please enter an integer: "

	.text
	.globl	main
main:	la $a0, inp #load the address of the string int into $a0
	li $v0, 4 #print out the string
	syscall
	
	li $v0, 5 #read in an integer
	syscall
	
	add $a0, $v0, $zero #load what is in $v0 and load it in $a0
	andi $a2, $a0, 1 # uisng boolean algebra, performing the task $a0 AND 1, and put the result into $a2
# a2 1 ueven  a2 0 even
	beqz $a2, even  #if the last bit number in $a2 is 0, then jump to even. If it is odd, then perform continue down in the program.
   
	add $a1,$a0,$a0 #add $a0 and $a0 together and put the result in $a1.
	add $a1, $a1, $a0 #add $ a0 to %a1 and store it into $a1, this is the process to do instead of multiply numbers together to compute 3 * n.
	addi $a0,$a1,1 #add 1 to $a1 into $a0, this process will cimpute 3n + 1 when the integer read in is odd.
	j result
	  	 
even:	srl $a0,$a0,1 #to divide a number by 2, all one needs to do is to shift all of the bits to the right once. This will compute n / 2.
		

result: li $v0,1 #display the result of whether the intefer read in is even or odd. 
	syscall
	
	li $v0,10 #exut the program.
	syscall
