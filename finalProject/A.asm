#Andreas Landgrebe
#Part 1 of the CS210 Final Project
#I will have this program to write A in the mars bot to be 5 x 5
#I will make sure that this A's being drawn are disconnected and it is a repated pattern. 
            .data
HEADING:    .word   0xffff8010  # set by program
LEAVETRK:   .word   0xffff8020  # set by program
WHEREX:     .word   0xffff8030  # read by program
WHEREY:     .word   0xffff8040  # read by program
MOVE:       .word   0xffff8050  # set by program

            .text
            .globl  main
main:	

	li $a0,0 # $a0: x-position
	li $a1,0 # $a1: y-position
	
branch:	
        bge $a1,500,branch2 #if a1 is greater than or equal to 300, then exit the progran. Else, continue the program to the branch2 function.
	jal a #jump the link to the a function to be able to call a return address
	addi $a1,$a1,100 #add 100 to the a1 register 
	j branch #jump the branch function
	
branch2:
	li $a1,0 # load 0 onto the A1 register the set up that next column can be drawn. 
	bge $a0,400,endloop # branch to exit the program if a0 is 400
	addi $a0,$a0,110 #add 100 so after A's are drawn, it will go the next column and continue drawing these A's. 
	j branch #jump to the branch function	
endloop:
        	
	li    $v0,10 #exit the program
        syscall
      
a: 

	addi $sp,$sp,-12 #alloate memory to the stack pointer
        sw $a0,0($sp) #save position 0 onto the stack with the a0 register
        sw $a1,4($sp) #save position 4 onto the stack with the a1 register
        sw $ra,8($sp) #save position 8 onto the stack with the return address
	    
	lw $a0,0($sp) #load position 0 from the stack
	addi $a0,$a0,0 #add 0 onto the a0 register, I don't need this line but I just still write it for consistency
	    
        li $a1,0 #dont draw the line but go to the point
        jal horiz #jump and link to the horizontal method written below      

	lw $a0,4($sp) #load postion 4 from the stack
	addi $a0,$a0,100 #add 100 onto the a0 register
     
        li $a1,0 #dont draw the line but go to the point being called      
        jal vert #jump and link to the vertical function to be able to set up a return address. 
            
        lw $t0,LEAVETRK # turn off drawing to set endpoint
        sw $zero,0($t0)
            
        lw $a0,0($sp) #load position 0 from the stack      
        addi $a0,$a0,50 #add 50 onto the a0 register     
 
        li $a1,1 #draw the line from the horizntal parameter set above
        jal horiz #jump and link to the horizontal function to be able to set up a return address.
            
        lw $a0,4($sp) #load position 4 from the stack
        addi $a0,$a0,0 #add 0 onto the a0 register, this is not necessary but I am still adding 0 to have consistency in this program.
            
        li $a1,1 #draw the line from the vertiical paramter set above
        jal vert #jump and link to the veritical function to be able to the set up a return address.       

        lw $t0,LEAVETRK # turn off drawing to set endpoint
        sw $zero,0($t0)
            
        lw $a0,0($sp) #load position 0 from the stack 
        addi $a0, $a0, 100 #add 100 onto the a0 register
            
        li $a1,1 #draw the line from the horizontal postion being assigned above
        jal horiz #jumnp and link to the horizontal function written below.
            
        lw $a0,4($sp) #load postion 4 from the stack
        addi $a0,$a0,100 #add 100 onto a0 to be later have the line to be drawn
            
        li $a1,1 #draw the line
        jal vert #jump and link to the veritical function written below
            
        lw $t0,LEAVETRK #turn off drawing to set endpoint
        sw $zero,0($t0)
            
        lw $a0,0($sp) #load from postion 0 of the stack
        addi $a0,$a0,75 #add 75 to the a0 register
            
        li $a1,0 #don't draw the line, but go to the point
        jal horiz #jump and link to the horizonal function written below
            
        lw $a0, 4($sp) #load from postion 4 of the stack
        addi $a0,$a0,50 #add 50 to the a0 register to be able to go to this specific postion
            
        li $a1,0 #dont draw the line but go to the point
        jal vert #jump and link to the veritical function wrttien below
            
        lw $t0,LEAVETRK #turn off drawing to set endpoint
        sw $zero,0($t0)
            
        lw $a0, 0($sp) #load from position 0 of the stack pointer
        addi $a0,$a0,25 #add 25 onto a0 to be able to go to this point
            
        li $a1,1 # draw the line to where a0 is being set to
        jal horiz #jump and link the horiz function wirrten
            
        lw $t0, LEAVETRK #turn off drawing to set endpoint
        sw $zero,0($t0)
            
        lw $a0,0($sp) #load what is in position 0 from the stack
        lw $a1,4($sp) #load what is in position 4 from the stack
        lw $ra,8($sp) #load what is in position 8 from the stack
        addi $sp,$sp,12 #add the allocated memory back from the stack pointer
        jr $ra #jump register to the return address
            
            


##################################################
# horiz -- move horizontally to given x-value
# $a0 = goal x-value
# $a1 = true if we should leave a track, false otherwise
##################################################
horiz:      # Preserve registers (in case they're being used elsewhere!)
            addi    $sp,$sp,-16

            sw      $s0,0($sp)
            sw      $s1,4($sp)
            sw      $s2,8($sp)
            sw      $s3,12($sp)

            lw      $s0,HEADING     # MMIO address for heading
            lw      $s1,WHEREX      # MMIO address for x-value
            lw      $s2,MOVE        # MMIO address for move command
            lw      $s3,LEAVETRK    # MMIO address for leave track

            # Loop until we reach goal value
xloop:      lw      $t0,0($s1)      # t0 = current x location
            beq     $t0,$a0,donex   # "Are we there yet?"...

            # ... No. See if we have to move left or right:
            sw      $a1,0($s3)      # set "leave track" as specified
            blt     $t0,$a0,h90     # if current < goal, move right (heading 90)

h270:       # We have to move left (heading 270):
            li      $t0,270         # store the heading (270)...
            sw      $t0,0($s0)      # ... in the appropriate MMIO address
            li      $t0,1           # t0 = "true"
            sw      $t0,0($s2)      # start moving
busyX1:     lw      $t0,0($s1)      # Get current location
            ble     $t0,$a0,donex   # "Are we there yet?"
            j       busyX1

h90:        # We have to move right (heading 90):
            li      $t0,90          # store the heading (90)...
            sw      $t0,0($s0)      # ... in the appropriate MMIO address
            li      $t0,1           # t0 = "true"
            sw      $t0,0($s2)      # start moving
busyX2:     lw      $t0,0($s1)      # Get current location
            bge     $t0,$a0,donex   # "Are we there yet?"
            j       busyX2

donex:      sw      $zero,0($s2)    # stop moving

            lw      $s0,0($sp)      # restore registers
            lw      $s1,4($sp)
            lw      $s2,8($sp)
            lw      $s3,12($sp)
            addi    $sp,$sp,16
            jr      $ra

##################################################
# vert -- move vertically to given x-value
# $a0 = goal y-value
# $a1 = true if we should leave a track, false otherwise
##################################################
vert:      # Preserve registers (in case they are being used)
            addi    $sp,$sp,-16

            sw      $s0,0($sp)
            sw      $s1,4($sp)
            sw      $s2,8($sp)
            sw      $s3,12($sp)

            lw      $s0,HEADING     # MMIO address for heading
            lw      $s1,WHEREY      # MMIO address for y-value
            lw      $s2,MOVE        # MMIO address for move command
            lw      $s3,LEAVETRK    # MMIO address for leave track

yloop:      lw      $t0,0($s1)      # t0 = current y location
            beq     $t0,$a0,doney   # "Are we there yet?"...

            # ... No. See if we have to move up or down:
            sw      $a1,0($s3)      # set "leave track" as specified
            blt     $t0,$a0,h180    # if current < goal, move down (heading 180)
h0:       # We have to move up (heading 0):
            li      $t0,0           # store the heading (0)...
            sw      $t0,0($s0)      # ... in the appropriate MMIO address
            li      $t0,1           # t0 = "true"
            sw      $t0,0($s2)      # start moving
busyY1:     lw      $t0,0($s1)      # Get current location
            ble     $t0,$a0,doney   # "Are we there yet?"
            j       busyY1
h180:       # We have to move down (heading 180):
            li      $t0,180         # store the heading (180)...
            sw      $t0,0($s0)      # ... in the appropriate MMIO address
            li      $t0,1           # t0 = "true"
            sw      $t0,0($s2)      # start moving
busyY2:     lw      $t0,0($s1)      # Get current location
            bge     $t0,$a0,doney   # "Are we there yet?"
            j       busyY2
doney:      sw      $zero,0($s2)    # stop moving

            lw      $s0,0($sp)      # restore registers
            lw      $s1,4($sp)
            lw      $s2,8($sp)
            lw      $s3,12($sp)
            addi    $sp,$sp,16
            jr      $ra
