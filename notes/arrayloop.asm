# Demonstration of looping through an array.
#
# At location x there is an array of 100 words, initially uninitialized.
# This program fills that array by setting x[i] = 4*i-10 (thus, x[0] = -10,
# x[1] = -6, x[2] = -2, x[3] = 2, etc.)

###########
# DATA:
###########
        .data
        .align  2       # get to a word boundary
x:      .space  400     # a 100-element array

###########
# PROGRAM:
###########
        .text
        .globl  main

# Register map:
#       $t0:  holds the loop counter and array index "i"
#       $t1:  holds the address of the current array value, addr(x[i])
#       $t2:  constant, size of array (in this case, 100)
#       $t3:  holds result of the loop termination test
#       $t4:  holds the calculated value of x[i], namely, 4*x[i]-10

main:   li      $t0,0           # t0 = 0, 1, 2, ..., 99 ("i": array index)
        la      $t1,x           # t1 = addr(x[0]), addr(x[1]), ..., addr(x[99])
        li      $t2,100         # t2 = n, the array size (in this case, 100)

loop:   slt     $t3,$t0,$t2     # if t0 < t2, t3=1 ("if i < n, set t3")
        beq     $t3,$zero,done  # if i >= n, drop out of loop
        addi    $t4,$t0,0       # t4 = i
        sll     $t4,$t4,2       # t4 = 4*i [NOTE: left shift by 2 bits!]
        addi    $t4,$t4,-10     # t4 = 4*i - 10
        sw      $t4,0($t1)      # save: x[i] = t4
        addi    $t0,$t0,1       # i = i+1
        addi    $t1,$t1,4       # addr = addr + 4
        b       loop            # ... and do it all over again

done:   li      $v0,10          # program exit code
        syscall                 # end program
