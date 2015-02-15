#Andreas Landgrebe
#CS210 final project part 2
#This mips program will have four opeations of move, rmoveto,
#lineto, and rlineto
#The moveto function will move to a location leaving no track
#The rmove to function will move a distance will no track.
#The lineto function will draw a line to a location
#The rlineto function will draw for a distance which will leave a track.
#The r means relative which signifies that the argument
#show points to the starting position. These are not absolute coordinates.

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
	li $a1,0 # $a1: y-position
	jal moveto #jump and link to the moveto function to set up the return address
	
	li $a0,200 #set the x position to 200
	li $a1,100 #set the y position to 100
	jal lineto #jump and link to the lineto function to set up the return address
	
	li $a0, 100 #set the x position to 100
	li $a1, 200 #set the y position to 200
	jal lineto #jump and link to the lineto function to set up the return address
	
	li $a0,0 #set the x position to 0
	li $a1, 100 #set the y position to 100
	jal lineto #jump and link to the lineto function to set up the return address
	
	li $a0,100 #set the x position to 100
	li $a1, 0 #set the y position to 0
	jal lineto #jump and link to the lineto function to set up the return address
	
	#starting from here, it the going to draw a new figure where it is going to be triangle where one of the sides
	#is not drawn to properly show the function written are performing correctly.
	
	li $a0, 300 #set the x position to 300
	li $a1, 300 #set the y position to 300
	jal moveto #jump and link to the moveto function to set up the return address
	
	li $a0, 50 #set the x postion to 50
	li $a1, 100 #set the y position to 100
	jal rlineto #jump and link to the rlineto function to set up the retrun address
	
	li $a0, -50 #set the x position to -50. It is going to be negative to subtract the x-position to be in a relative postion
	li $a1, 0 #set the y position to be 0
	jal rmoveto #jump and link to the rmoveto function to set up the return address
	
	li $a0,0 #set the x position to be 0 
	li $a1, -100
#set the y postion to be -100. It is going to be negative to draw the line while decreasing the x-position to be in a relative postion
	jal rlineto #jump and link to the rlinto function to set up the return address
	

	
	
	
	

endloop:
        	
	li    $v0,10 #exit the program
        syscall
      
moveto: #this will move to a location that will leave no track
	addi $sp,$sp, -12 #allocate memory to the stack
	sw $a0,0($sp) #store register $a0 onto positon 0 on the stack
	sw $a1,4($sp) #store register $a1 onto postion 4 on the stack
	sw $ra,8($sp) #store the return address onto postion 8 on the stack
	
	addi $t0,$zero,0 #set up the t0 register to not leave a track
	lw $t1, LEAVETRK #load the LEAVETRK onto t1
	sw $t0, 0($t1)  #save what is in t1 onto t0 so it does not leave a track
	
	jal justmove #jump and link to the just move function to set up the return address
	
	lw $a0,0($sp) #load what is in register a0 onto postion 0 on the stack
	lw $a1,4($sp) #load what is in register a1 onto postion 4 on the stack
	lw $ra,8($sp) #load the return address in postion 8 on the stack
	addi $sp,$sp,12 #add back the memory used for the stack

       jr $ra #jump to the return address
       
rmoveto: #this will to a relatve location that will leave no track

	addi $sp,$sp, -12 #allocate memory to the stack
	sw $a0,0($sp) # store register a0 onto the stack at postion 0
	sw $a1,4($sp) # store register a1 onto the stack at postion 4
	sw $ra,8($sp) # store the return address onto the stack at position 8.
	
	lw $t0,WHEREX #load where is x  in t0
	lw $t2,0($t0) #load what is in t0 into t2
	lw $t1,WHEREY #load where is y in t3
	lw $t3,0($t1) #load what is in t1 into t2 
		
	add $a0,$a0,$t2 #add what is in t2 into a0 
	add $a1,$a1,$t3 #add what is in t3 into a1
	

	jal moveto #jump and link to the moveto function to set up the return address	
	
	lw $a0,0($sp) #load the a0 register onto the stack at postion 0
	lw $a1,4($sp) #load the a1 register onto the stack at postion 4
	lw $ra,8($sp) #load the return address onto the stack at postion 8
	addi $sp,$sp,12 #add back the meory used for the stack
 	jr $ra #jump to the return address
 	
lineto: #this will draw a line to a location

	addi $sp,$sp, -12 #add memory to the stack
	sw $a0,0($sp) #store the a0 register onto the stack at postion 0
	sw $a1,4($sp) #store the a1 register onto the stack at postion 4
	sw $ra,8($sp) # store the return address onto the stack at postion 8

	addi $t0,$zero,1 #add 1 onto to t0 so it is able to leave to track to draw a line
	lw $t1,LEAVETRK #load LEAVETRK to the t1 register
	sw $t0,0($t1) #load what is in t1 into t0 so it is able to draw a line
	
	jal justmove #jump and link to the justmove function to set up a return address

	addi $t0,$zero,0 #add 0 onto t0 so it can terminate to draw a line
	lw $t1,LEAVETRK #load LEAVETRK into the t1 register 
	sw $t0,0($t1) #store what is in the t1 register and put it in the t0 register 
		
	lw $a0,0($sp) #load the a0 register onto the stack at postion 0
	lw $a1,4($sp) #load the a1 register onto the stack at postion 4
	lw $ra,8($sp) #load the return address onto the stack at position 8
	addi $sp,$sp,12 #add back the memory used for the stack
 	jr $ra #jump for the return address
 	
rlineto: #draw for a distacne relative to leave a track

	addi $sp,$sp, -12 #add memory to the stack
	sw $a0,0($sp) #store register a0 onto the stack at position 0
	sw $a1,4($sp) #store register a1 onto the stack at positon 4
	sw $ra,8($sp) #store the return address onto the stack at postion 8
	
	lw $t0,WHEREX #load where is x into register t0
	lw $t2,0($t0) #load what is in t0 into t2
	lw $t1,WHEREY #load where is y into register t1
	lw $t3,0($t1) #load what is in t1 into t3
		 
	add $a0,$a0,$t2 #add what is in t2 into a0
	add $a1,$a1,$t3 #add what is in t3 into a1
	
	jal lineto #jump and link to the lineto function to set up the return address
	
	
	
	lw $a0,0($sp) #load the a0 register onto the stack at position 0
	lw $a1,4($sp) #load the a1 register onto the stack at position 4
	lw $ra,8($sp) #load the return address onton the stack at position 8
	addi $sp,$sp,12 #add back the memory used for the stack
 	jr $ra #jump to the return address

 justmove:
 	addi $sp,$sp, -12 #allocate memory to the stack
 	sw $a0,0($sp)#a0 is the x address
	sw $a1,4($sp)#a1 is the y address
	sw $ra,8($sp) #set the return address onto postion 8 on the stack
	
	lw $t0, LEAVETRK
	lw $a1, 0($t0) 
	jal horiz #jump and link to the horiz to set up the return address
	
	lw $a0, 4($sp) 
	lw $t0, LEAVETRK
	lw $a1, 0($t0) 
	jal vert #jump and link to the vert function to set up the return address
		
	           
  	lw $a0,0($sp) #load register a0 onto position 0 on the stack
	lw $a1,4($sp) #load register a1 onto postion 4 on the stack
	lw $ra,8($sp) #load the return address onto postion 8 on the stack
	addi $sp,$sp,12 #add back teh meory used for the stack
 	jr $ra #jump to the return address
          


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
