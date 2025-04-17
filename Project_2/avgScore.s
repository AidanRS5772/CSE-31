.data

orig: .space 100	# In terms of bytes (25 elements * 4 bytes each)
sorted: .space 100

str0: .asciiz "Enter the number of assignments (between 1 and 25): "
str1: .asciiz "Enter score: "
str2: .asciiz "Original scores: "
str3: .asciiz "Sorted scores (in descending order): "
str4: .asciiz "Enter the number of (lowest) scores to drop: "
str5: .asciiz "Average (rounded down) with dropped scores removed: "
str6: .asciiz "All scores dropped!"

.text

# This is the main program.
# It first asks user to enter the number of assignments.
# It then asks user to input the scores, one at a time.
# It then calls selSort to perform selection sort.
# It then calls printArray twice to print out contents of the original and sorted scores.
# It then asks user to enter the number of (lowest) scores to drop.
# It then calls calcSum on the sorted array with the adjusted length (to account for dropped scores).
# It then prints out average score with the specified number of (lowest) scores dropped from the calculation.
main:
    #save return
	addi $sp, $sp -4
	sw $ra, 0($sp)

	#print prompt
	input_length_loop:
    	la $a0, str0
    	li $v0, 4
    	syscall
    	li $v0, 5	# Read the number of scores from user
    	syscall
        blt $v0, 1, input_length_loop
        bgt $v0, 25, input_length_loop

	move $s0, $v0	# $s0 = numScores
	move $t0, $0
	la $s1, orig	# $s1 = orig
	la $s2, sorted	# $s2 = sorted
    loop_in:
    	li $v0, 4
    	la $a0, str1
    	syscall
    	sll $t1, $t0, 2
    	add $t1, $t1, $s1
    	li $v0, 5	# Read elements from user
    	syscall
    	sw $v0, 0($t1)
    	addi $t0, $t0, 1
    	bne $t0, $s0, loop_in

	move $a0, $s0
	jal selSort	# Call selSort to perform selection sort in original array

	li $v0, 4
	la $a0, str2
	syscall
	move $a0, $s1	# More efficient than la $a0, orig
	move $a1, $s0
	jal printArray	# Print original scores
	li $v0, 4
	la $a0, str3
	syscall
	move $a0, $s2	# More efficient than la $a0, sorted
	jal printArray	# Print sorted scores

	input_drop_loop:
    	li $v0, 4
    	la $a0, str4
    	syscall
    	li $v0, 5	# Read the number of (lowest) scores to drop
    	syscall
        blt $v0, $zero, input_drop_loop
        bgt $v0, $s0, input_drop_loop

    beq $v0, $s0, drop_else # if number to drop != number of scroes

	move $a1, $v0
	sub $a1, $s0, $a1	# numScores - drop
	move $a0, $s2
	jal calcSum	# Call calcSum to RECURSIVELY compute the sum of scores that are not dropped

	div $t0, $v0, $v1
	li $v0, 4
	la $a0, str5
	syscall
	li $v0, 1
	move $a0, $t0
	syscall
	j end

	drop_else:
	li $v0, 4
	la $a0, str6
	syscall


end:
    li $v0, 11
	li $a0, '\n'
	syscall
    lw $ra, 0($sp)
	addi $sp, $sp 4
	li $v0, 10
	syscall


# printList takes in an array and its size as arguments.
# It prints all the elements in one line with a newline at the end.
# $a0 array adress
# $a1 array size
printArray:
    move $t0, $a0 #save adress
	li $t1, 0 #i
	printArray_loop:
	    #get adress
		sll $t2, $t1, 2
		add $t2, $t2, $t0

		#print value
		lw $t2, 0($t2)
		li $v0, 1
		move $a0, $t2
		syscall

		#print space
		li $v0, 11
		li $a0, ' '
		syscall

		addi $t1, $t1, 1 #i++
		blt $t1, $a1, printArray_loop #loop if i < len

	li $v0, 11
	li $a0, '\n'
	syscall

	jr $ra


# selSort takes in the number of scores as argument.
# It performs SELECTION sort in descending order and populates the sorted array
selSort:
	la $t0, orig
	la $t1, sorted
	li $t2, 0

	selSort_copy_loop:
	    #get adresses
	    sll $t3, $t2, 2
		add $t4, $t3, $t0
		add $t5, $t3, $t1

		#sorted[i] = orig[i]
		lw $t4, 0($t4)
		sw $t4, 0($t5)

		addi $t2, $t2, 1 #i++
		blt $t2, $a0, selSort_copy_loop #loop if i < len

	addi $t9, $a0, -1 #outer lim
	li $t2, 0 #i
	selSort_outer_loop:
	    move $t8, $t2 #max index
		add $t3, $t2, 1 #j
		selSort_inner_loop:
		    #get adresses
		    sll $t4, $t3, 2
			sll $t5, $t8, 2
			add $t4, $t4, $t1
			add $t5, $t5, $t1

			#load values
			lw $t4, 0($t4)
			lw $t5, 0($t5)

			ble $t4, $t5, selSort_inner_loop_else #sorted[j] > sorted[maxIndex]
			move $t8, $t3 #update max index

			selSort_inner_loop_else:
			addi $t3, $t3, 1 #j++
			blt $t3, $a0, selSort_inner_loop #loop if j < length

		#get adresses
		sll $t4, $t8, 2
		sll $t5, $t2, 2
		add $t4, $t4, $t1
		add $t5, $t5, $t1

		#swap
		lw $t6, 0($t4)
		lw $t7, 0($t5)
		sw $t7, 0($t4)
		sw $t6, 0($t5)

	    addi $t2, $t2, 1 #i++
		blt $t2, $t9, selSort_outer_loop #loop if i < len - 1
	jr $ra


# calcSum takes in an array and its size as arguments.
# It RECURSIVELY computes and returns the sum of elements in the array.
# Note: you MUST NOT use iterative approach in this function.
# $a0 base adress of array
# $a1 iterator
# $v0 return value
# $v1 counter
calcSum:
    #save return adress
    addi $sp, $sp, -4
    sw $ra, 0($sp)

    beq $a1, $zero, calcSum_else #if a0 != 0

    #save iterator
    addi $sp, $sp, -4
    sw $a1, 0($sp)

    addi $a1, $a1, -1 #decrement iterator
    jal calcSum #recursive call

    #restore iterator
    lw $a1, 0($sp)
    addi $sp, $sp, 4

    #get arr[len-1]
    addi $t0, $a1, -1
    sll $t0, $t0, 2
    add $t0, $t0, $a0
    lw $t0, 0($t0)
    add $v0, $v0, $t0 #sum
    addi $v1, $v1, 1 #increment counter
    j calcSum_return
    calcSum_else:
    #set base cases for return values
    li $v0, 0
    li $v1, 0
    calcSum_return:
    lw $ra, 0($sp)
    addi $sp, $sp, 4
    jr $ra
