# Demonstration of recursion
#
# In C:
#         int f(int i, int j)
#         {
#             if (j <= 0)
#                 return 1;
#             else if (i <= 0)
#                 return 0;
#             else
#                 return i + j + f(i-1,j/2);
#         }
#
# EXAMPLE:  f(3,8) = 3 + 8 + f(2,4)
#                            f(2,4) = 2 + 4 + f(1,2)
#                                             f(1,2) = 1 + 2 + f(0,1)
#                                                              f(0,1) = 0
#                                             f(1,2) = 3
#                            f(2,4) = 9
#           f(3,8) = 20

        .data
        .align  2
result: .word   0	# value of f(i,j)

        .text
        .globl  main
        		# Getting ready to call f:
main:   li      $a0,3	# first argument i=3 in a0
        li      $a1,8	# second argument j=8 in a0
        jal     f	# call f(i,j)
        
        sw      $v0,result	# result is in v0; save it:
        
        li      $v0,10	# exit program
        syscall

###########################
f:      			
        bgt     $a1,$zero,f1	# If j >= 0 keep going...
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
        jal     f		# call f(i-1,j/2)
        
        lw      $a0,4($sp)	# restore old value of i
        lw      $a1,8($sp)	# restore old value of j
        add     $v0,$v0,$a0	# add i to f(i-1,j/2)
        add     $v0,$v0,$a1	# add j to f(i-1,j/2) + i
        lw      $ra,0($sp)	# restore return address
        addi    $sp,$sp,12	# reduce stack size by 3 words
        jr      $ra		# and return (result is in v0)