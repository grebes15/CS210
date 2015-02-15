	.data
	.align	2
result:	.word	0
x:	.word	0
y:	.word	0
nl:	.asciiz	"\n"
s1:	.asciiz	"When multiplying: "
s2:	.asciiz	"And "
s3:	.asciiz	"The result is: "

	.text
	.globl	main
main:	li	$v0,4 #print a string
	la	$a0,s1 #store in what is in s1
	syscall
	li	$v0,5 #read in an int
	syscall
	sw	$v0,x #storen the int into x
	
	li	$v0,4 #print a string
	la	$a0,s2 #load the string in what is in s2
	syscall
	
	li	$v0,5 #read in an int
	syscall
	sw	$v0,y #store the int in y
	
	li	$v0,4 #read in a new string
	la	$a0, nl # create a new line 
	syscall
	
	li	$v0,4 # read in a string 
	la	$a0,s3 #store the string in what is in s3
	syscall
	
	li	$a0, 5
	li	$a1, 3
	jal	mult
	sw	$v0,result
	
	li	$v0, 1
	la	$a0, result
	
	
	
	
mult:		bgt     $a1,$zero,f1	# If j >= 0 keep going...
        addi    $v0,$zero,1	# ... but if j < 0, return 1
        jr      $ra		# result 1 is in v0
        
f1:     bgt     $a0,$zero,f2	# If i >= 0 keep going...
        li      $v0,0		# ... but if i < 0, return 0
        jr      $ra		# result 0 is in v0
        
f2:     addi    $sp,$sp,-12	# grow the stack by three words
 	sw      $ra,0($sp)	# preserve value of return address on stack
        sw      $a0,4($sp)	# preserve parameter i on stack
        sw      $a1,8($sp)	# preserve parameter j on stack
       
       				# Getting ready to recursively call f
        subi    $a0,$a0,1	# first argument: i-1
        sra     $a1,$a1,1	# second argument: j/2
        jal     mult		# call f(i-1,j/2)
        
        lw      $a0,4($sp)	# restore old value of i
        lw      $a1,8($sp)	# restore old value of j
        add     $v0,$v0,$a0	# add i to f(i-1,j/2)
        add     $v0,$v0,$a1	# add j to f(i-1,j/2) + i
        lw      $ra,0($sp)	# restore return address
        addi    $sp,$sp,12	# reduce stack size by 3 words
        jr      $ra		# and return (result is in v0)
	
	li	$v0,10
	syscall
	
	
	
	
	
	
	
	
	
	
	
	