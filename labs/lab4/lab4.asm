	.data
	.align	2
x:	.word	1,2,3,4,5,6,7,8,9,10 #this is the first array	
y:	.word	5,10,8,7,1,15,5,3,6,9 #this is the second array
c:	.word	0 #counter
s:	.word	10 #size of the array
sum:	.word	0,0,0,0,0,0,0,0,0,0
a1:	.asciiz	"Array a: 1,2,3,4,5,6,7,8,9,10"
b1:	.asciiz	"Array b: 5,10,8,7,1,15,5,3,6,9"
sum1:	.asciiz	"Sum of the two arrays are: "
nl:	.asciiz	"\n" #crates a new line
space:	.asciiz	" "

	.text
	.globl	main
main:	li	$v0,4 # loads a string in memory 
	la	$a0,a1 #wil load the new string at a1 and display into output
	syscall
	
	li	$v0,4 #loads a string in memory	
	la	$a0,nl #creates a new line in output
	syscall
	
	li	$v0,4 #loads a string in memory
	la	$a0,b1 #will loads the new string at b12 and display what is in b1
	syscall
	
	li	$v0,4 #loads a string in memory
	la	$a0,nl # loads a new line in output
	syscall
	
	li	$v0,4 #loads a string in memory
	la	$a0,sum1 #loads what is in sum1 and dispalys it in output
	syscall
	la	$t0, x #loads the address of x into $s1
	la	$t1, y # loads the address of y into $s2
	la	$t2, sum #loads the address of sum into $s3
	addi	$t6, $zero, 0 #t6 is the counter for the loop
	lw	$t7, s #loads the size of the array into a temporary array $t2	
	
		

	
	looparray:
	slt	$t3, $t6, $t7 #checks to see if the counter is less than the size of the array 
	beq	$t3, $zero,done #the loop will exit if the counter is greater or equal to the size of the array
	
	lw $t3, 0($t0) # $t3 is the element of the first array
	lw $t4, 0($t1) # $t4 is the element of the second array
	add $t5, $t3, $t4 #t5 is their sum
	sw $t5, 0($t2) #store the result in the element of sum
	
	addi	$t0, $t0, 4  #go to next array element from the first array
	addi $t1, $t1, 4 #go to next array element from the second array
	addi $t2, $t2, 4 #go to the next array element fron the sum  
	addi $t6, $t6, 1 # incrase the counter by 1
	j	looparray # go back to top of the loop
	
	done:
	addi	$t6, $zero, 0 #t6 is the counter for the loop
	la	$t2, sum #loads the address of sum into $t2
	loop2:
	slt $t3, $t6, $t7 #set the counter if it is less than the size of the array
	beq	$t3, $zero, end #
	lw 	$a0, 0($t2) #word the sum into $a0 register
	li	$v0,1 #load the immediate and print out the interger
	addi	$t6, $t6, 1 #increase the array index of the sum by 1
	addi	$t2, $t2, 4#increment the counter by 4
	syscall
	li	$v0,4 #load the string
	la	$a0,space #load the string so there will be space betwen the numbers of tghe sum,=
	syscall
	j	loop2
	

	end:
	li	$v0,10 # exit the program
	syscall

	

