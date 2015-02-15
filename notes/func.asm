# Calling functions in MIPS
# See program "func.c" for the equivalent C code

        .data
        .align  2
a:      .word   10
b:      .word   20
lab1:   .asciiz "proc2("
lab2:   .asciiz ","
lab3:   .asciiz ") = "
nl:     .asciiz "\n"

        .text
        .globl  main
main:   lw      $a0,a   # First we call "proc2"; first parameter goes in a0
        lw      $a1,b   # Second parameter goes in a1
        jal     proc2   # Call the function
        move    $s0,$v0 # Result is saved in v0; copy it into s0 for now

        # Next bunch of syscalls just prints out the values of a, b, and
        # proc2(a,b,), with appropriate labels, spacing, commas, etc.
        li      $v0,4
        la      $a0,lab1
        syscall         # prints "proc2("

        li      $v0,1
        lw      $a0,a
        syscall         # prints a

        li      $v0,4
        la      $a0,lab2
        syscall         # prints ","

        li      $v0,1
        lw      $a0,b
        syscall         # prints b

        li      $v0,4
        la      $a0,lab3
        syscall         # prints ") = "

        li      $v0,1
        move    $a0,$s0
        syscall         # prints value of proc2(a,b), which we saved in s0

        li      $v0,4
        la      $a0,nl
        syscall         # terminates line

        li      $v0,10
        syscall         # program completion--exit


# Function proc 1 simply subtracts its two arguments, returning the 
# difference in register v0:

proc1:  sub     $v0,$a0,$a1     # a0, a1 are the argument registers
        jr      $ra             # return


# Function proc 2 calls proc1, adds 1 to its value, and returns the
# result in register v0:

proc2:                          # Registers a0, a1 already contain the arguments,
                                # but before we can call "proc1, we must
        addi    $sp,$sp,-4      # make extra space on the stack...
        sw      $ra,0($sp)      # ... so we can preserve the return address...
        jal     proc1           # ... which is wiped out by the "jal" instruction

        addi    $v0,$v0,1       # result of proc1 is in v0; add 1 to it
        lw      $ra,0($sp)      # restore the saved value of the return address
        addi    $sp,$sp,4       # free up the space on the stack
                                # register v0 already contains the result, so ...
        jr      $ra             # ...return
