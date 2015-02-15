# Andreas Landgrebe
# Novmeber 18, 2013
# Part 4 of the Take Home Exam
# This mips program will take two functions of f and g and read two integer arguments
# this will pass thrgough the $a0 and $a1 registers. After this, the functiosn will return an int result.
# this int result has to be returned to the $v0 register.
# this program will compute the following:
# f(a,b): 3a + b
# g(a,b) = 2f(b-1,a-1) +a + b.
# load the first integers into a0 and a1, call function g and print out the result.

	.data
	.align 2
	
	.text
	.globl	main
main:	li $a0, 15 #loads a value into $a0
	li $a1, 8 #loads a value into $a1
	jal g #jump and link to g
	addi $a0, $v0, 0 # converts what is in register $v0 into $a0.
	li $v0, 1 #print out the result as a integer.
	syscall 
	
	li $v0,10 #exit the program
	syscall
	


f:	add $v0,$a0,$a0 #computes 2a
	add $v0,$v0,$a0 #computes 3a
	add $v0,$v0,$a1 #computers 3a +b
	jr  $ra #jump the register to the return address.
	
g:	addiu $sp,$sp,-12 # allocate memory to the stack points
	sw $a0,0($sp) #save what is in #a0 into the stack poiner
	sw $a1,4($sp) #save what is in #a1 into the stack pointer
	sw $ra,8($sp) #save ther return address into the stack pointer
	
	subi $a1,$a0,1 #a1 = a - 1
	lw $a0,4($sp) #a0 = b
	subi $a0,$a0,1 #a0 = b - 1
	jal f #jump and link to f
	
	add $v0,$v0,$v0 #v0 = 2 * f(b-1,a-1)
	lw $a0,0($sp) # loading a from the stack
	add $v0,$v0,$a0 #add 2f(b-1,a-1) + a
	lw $a1,4($sp) # loading b from the stack
	add $v0,$v0,$a1 #add 2f(b - 1, a -1) + a + b
			
	lw $a0,0($sp) #load a0  in the stack pointer
	lw $a1,4($sp) #load a1 in the stack pointer
	lw $ra,8($sp) #load the return address in the stack pointer
	addiu $sp,$sp,12 #add memory to the stack pointer.
	jr $ra #jump the register to the return adress.
	

