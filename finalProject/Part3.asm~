#Andreas Landgrebe
#Part 3 of the Final Project for Computer Science 210
#This mips program will draw a diamond by set the positions of where the line should point to instead of just writing x and y values to go to a particular line. This program will have angle degrees to be set and the diamond shape will be set that way. 
            .data
HEADING:    .word   0xffff8010  # set by program
LEAVETRK:   .word   0xffff8020  # set by program
WHEREX:     .word   0xffff8030  # read by program
WHEREY:     .word   0xffff8040  # read by program
MOVE:       .word   0xffff8050  # set by program

            .text
            .globl  main
main:	

	li $a0,100 # $a0: x-position
	li $a1,0 # $a1: no line
	jal horiz
	
            lw      $s0,HEADING     # MMIO address for heading
            lw      $s1,WHEREX      # MMIO address for x-value
            lw      $s2,MOVE        # MMIO address for move command
            lw      $s3,LEAVETRK    # MMIO address for leave track
            
            li $a1,1 #load 1 into the a1 register to be able to draw a line
            sw $a1, 0($s3) #store what is in s3 regsiter which is the LEAVETRK into a1 so it will draw a line
            li $a0,200 #this is the x position to go to
            li $t0,135 #this is the angle degrees bieng used to draw first part of the diamond
            sw $t0, 0($s0) #store what is in s0 where is the heading into the t0 register.
            li $t0,1 #load 1 into the t1 register
            sw $t0, 0($s2) #store the MOVE register into the t0
 busy1:	    
            lw $t0, 0($s1) #load the HEADING register into t0
 	    blt $t0, $a0, busy1 #branch to busy1 if t0 is greater than a0
  	    li $a1,0 #load 0 into a0 to end the drawing 
 	    sw $a1, 0($s3) #load LEAVETRK register into a1 to stop drawing
 	    sw $zero,0($s2)    # stop moving
 	    


	
	    li $a1,1 #load 1 into the a1 register to be able to draw a line
            sw $a1, 0($s3) #store what is in s3 regsiter which is the LEAVETRK into a1 so it will draw a line
            li $a0,100 #this is the x position to go to
            li $t0,225 #this is the angle degrees being used to draw second part of the diamond
            sw $t0, 0($s0) #store what is in s0 where is the heading into the t0 register.
            li $t0,1 #load 1 into the t1 register
            sw $t0, 0($s2) #store the MOVE register into the t0
 busy2:	   
            lw $t0, 0($s1) #load the HEADING register into t0
 	    bgt $t0, $a0, busy2 #branch to busy2 if t0 is greater than a0
 	    li $a1,0 #load 0 into a0 to end the drawing 
 	    sw $a1, 0($s3) #load LEAVETRK register into a1 to stop drawing
 	    sw $zero,0($s2)    # stop moving
	
	        

	    li $a1,1 #load 1 into the a1 register to be able to draw a line
            sw $a1, 0($s3) #store what is in s3 register which is the LEAVETRK into a1 so it will draw a line
            li $a0,0 #this is the x position to go to
            li $t0,315 #this is the angle degrees being used to draw third part of the diamond
            sw $t0, 0($s0) #store what is in s0 where is the heading into the t0 register.
            li $t0,1 #load 1 into the t1 register
            sw $t0, 0($s2) #store the MOVE register into the t0
 busy3:	   
            lw $t0, 0($s1) #load the HEADING register into t0
 	    bgt $t0, $a0, busy3 #branch to busy3 if t0 is greater than a0
 	    li $a1,0 #load 0 into a0 to end the drawing 
 	    sw $a1, 0($s3) #load LEAVETRK register into a1 to stop drawing
 	    sw $zero,0($s2)    # stop moving
	
	

	    li $a1,1 #load 1 into the a1 register to be able to draw a line
            sw $a1, 0($s3) #store what is in s3 register which is the LEAVETRK into a1 so it will draw a line
            li $a0,100 #this is the x position to go to
            li $t0,45 #this is the angle degrees being used to draw last part of the diamond
            sw $t0, 0($s0) #store what is in s0 where is the heading into the t0 register.
            li $t0,1 #load 1 into the t1 register
            sw $t0, 0($s2) #store the MOVE register into the t0
 busy4:	
            lw $t0, 0($s1) #load the HEADING register into t0
 	    blt $t0, $a0, busy4 #branch to busy4 if t0 is greater than a0
 	    li $a1,0 #load 0 into a0 to end the drawing 
 	    sw $a1, 0($s3) #load LEAVETRK register into a1 to stop drawing
 	    sw $zero,0($s2)    # stop moving
	
	
	
	
	

endloop:
        	
	li    $v0,10 #exit the program
        syscall
      
          


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
