# Demonstration of input and output in MIPS.
#
# Register $v0 is used to hold a "system call code". For a full listing, see
# appendix B, page B-44 in your text. The following are illustrated in 
# this program:
#
#        Code      Meaning
#        ----      -------
#          1      print_int
#          4      print_string
#          5      read_int
#          8      read_string
#         10      exit
#
# Register $a0  (and also $a1, in the case of read_string) contains an appropriate
# argument, depending on the code; register $v0 receives the integer value for code 5.

	.data
	.align	2	# get to a word boundary
a:	.space	4	# receives an input value
len:	.word	20	# length of input string buffer
s:	.space	20	# input string buffer (can hold up to 19 characters)

p1:	.asciiz	"Enter an int: "	# prompt for user input
p2:	.asciiz	"Enter a string (<= 19 chars): " # prompt for user input
l1:	.asciiz	"Value entered: "	# label for integer
l2:	.asciiz	"String entered: "	# label for string
nl:	.asciiz	"\n"			# newline character

	.text
	.globl 	main
main:	li	$v0,4	# load call code for "print_string"
        la 	$a0,p1	# load address of string (p1 = prompt 1)
	syscall

	li	$v0,5	# load call code for "read_int"
	syscall
	sw	$v0,a	# move the int from $v0 into memory

	li	$v0,4	# load call code for "print_string"
	la	$a0,p2	# load address of string (p2 = prompt 2)
	syscall

	li	$v0,8	# load call code for "read_string"
	la	$a0,s	# first argument: memory address of string buffer
	lw	$a1,len	# second argument: max. number of bytes in string buffer
	syscall

	li	$v0,4	# load call code for "print_string"
	la	$a0,l1	# load address of string (l1 = label 1)
	syscall

	li	$v0,1	# load call code for "print_int"
	lw	$a0,a	# load the int to be printed
	syscall

	li	$v0,4	# load call code for "print_string"
	la	$a0,nl	# load address of string (nl = "new line")
	syscall

	li	$v0,4	# load call code for "print_string"
	la	$a0,l2	# load address of string (l2 = label 2)
        syscall

	li	$v0,4	# load call code for "print_string"
	la	$a0,s	# load address of string (s = the sting input by the user)
	syscall

	li	$v0,4	# load call code for "print_string"
	la	$a0,nl	# load address of string (nl = "new line")
	syscall

	li	$v0,10	# load call code for "exit"
	syscall		# program terminates