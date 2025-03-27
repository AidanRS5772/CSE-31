.data
szMsg: .asciiz "Enter Size: "
inputMsg: .asciiz "Enter Elements:\n"

.text
.globl main
main:
    la $a0, szMsg
    li $v0, 4
    syscall

    #get size from terminal
    li $v0, 5
    syscall
    move $s0, $v0

    #allocate space on stack
    sll $t0, $s0, 2
    sub $sp, $sp, $t0

    li $v0, 4
    la $a0, inputMsg
    syscall

    li $t0, 0 #index
    input_loop:
        beq $t0, $s0, input_end
        li $v0, 5
        syscall

        #insert element into array
        sll $t1, $t0, 2
        add $t1, $t1, $sp
        sw $v0, 0($t1)

        addi $t0, $t0, 1 #increment
        j input_loop #loop
    input_end:
    #print array
    move $a0, $s0
    move $a1, $sp
    jal printArray

    move $a0, $sp
    li $a1, 0
    addi $a2, $s0, -1
    jal quickSort

    move $a0, $s0
    move $a1, $sp
    jal printArray

    #exit
    li $v0, 10
    syscall

#Sub-Routines

# a0 size of array
# a1 array adress
printArray:
    move $t2, $a0
    li $t0, 0 #index
    print_loop:
        bge $t0, $t2, print_end

        #get value
        sll $t1, $t0, 2
        add $t1, $t1, $a1
        lw $a0, 0($t1)

        #print value
        li $v0, 1
        syscall

        #print space
        li $v0, 11
        li $a0, ' '
        syscall

        addi $t0, $t0, 1 #increment
        j print_loop #loop
    print_end:
    li $a0, '\n'
    syscall

    jr $ra

#a0 array pointer
#a1 low index
#a2 high index
quickSort:
    addi $sp, $sp, -4
    sw $ra, 0($sp)

    blt $a2, $a1, exit

    #get pivot
    sll $t0, $a2, 2
    add $t0, $t0, $a0
    lw $t9, 0($t0)

    move $t1, $a1 #i
    addi $t2, $a2, -1
    main_loop:
        blt $t2, $t1, main_end
        i_loop:
            #get memory adress
            sll $t3, $t1, 2
            add $t3, $t3, $a0
            lw $t4, 0($t3)

            bgt $t4, $t9, j_loop
            addi $t1, $t1, 1 #increment
            j i_loop #loop
        j_loop:
            #get memory adress
            sll $t3, $t2, 2
            add $t3, $t3, $a0
            lw $t4, 0($t3)

            blt $t4, $t9, end_loops
            addi $t2, $t2, -1 #decrement
            j j_loop #loop
        end_loops:
        bge $t1, $t2, main_loop

        #swap memory values
        sll $t3, $t1, 2
        sll $t4, $t2, 2
        add $t3, $t3, $a0
        add $t4, $t4, $a0
        lw $t5, 0($t3)
        lw $t6, 0($t4)
        sw $t6, 0($t3)
        sw $t5, 0($t4)

        addi $t1, $t1, 1 #increment
        addi $t2, $t2, -1 #decrement
        j main_loop #loop
    main_end:

    move $t2, $a2
    #swap memory values
    sll $t3, $t1, 2
    sll $t4, $t2, 2
    add $t3, $t3, $a0
    add $t4, $t4, $a0
    lw $t5, 0($t3)
    lw $t6, 0($t4)
    sw $t6, 0($t3)
    sw $t5, 0($t4)

    #recusive call next quickSort
    move $t0, $a2
    addi $a2, $t1, -1
    jal quickSort
    addi $a1, $t1, 1
    move $a2, $t0
    jal quickSort

    exit:
    lw $ra, 0($sp)
    addi $sp, $sp, 4
    jr $ra
