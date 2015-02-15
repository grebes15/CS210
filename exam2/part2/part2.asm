#Andreas Landgrebe
#November 19, 2013
#Part 2 of the Take Home Exam
# In this mips program, load a hexidecimal constant into a register.
#Extract 8 bits in postions 30-23 and shift them to the right
#Subtract 127 from the result and then print out the result.
	
	.data
	.align 2

	.text
	.globl main
main:	li $s0, 0x9F500000 #this is the hexadecimal number being called in
	li $s1, 0x7F800000 
	#this is the hexadecimal number being used to extract 8 bits from 30-23.
	#This hexidecimal is where from bits 30-23, each bit will have a 1 in it.
	and $s2, $s0, $s1 #perform boolean algebra between what is in $s0 and $s1 and put the result in register $s2
	srl $s2, $s2, 23 #shift right 23 spaces and save it in $s2
	subi $a0, $s2, 127 #subtract 127 from $s2 and put the result in $a0.
	li $v0, 1 #print out the integer
	syscall
	
	li $v0,10 #exit the program
	syscall 
