.data
prompt: .asciiz "Please enter a number: "

.text
main:
    li $v0, 4
    la $a0, prompt
    syscall

    li $v0, 5
    syscall
    move $a0, $v0

    jal recursion

    move $a0, $v0
    li $v0, 1
    syscall
    li $v0, 11
    li $a0, '\n'
    syscall

    li $v0, 10
    syscall



recursion:
    addi $sp, $sp, -12
    sw $ra, 8($sp)

    bne $a0, -1, elif #if $a0 == -1
    li $v0, 3
    j return
    elif:
        bgt $a0, -2, else #if $a0 <= -2
        bne $a0, -2, elif_else #if $a0 == -2
        li $v0, 1
        j return
        elif_else:
            li $v0, 2
            j return
    else:
        sw $a0, 4($sp)
        addi $a0, $a0, -3
        jal recursion
        sw $v0, 0($sp)
        lw $a0, 4($sp)

        addi $a0, $a0, -2
        jal recursion
        lw $a0, 4($sp)

        lw $t0, 0($sp)
        add $v0, $v0, $t0
        add $v0, $v0, $a0

        j return
    return:
    lw $ra, 8($sp)
    addi $sp, $sp, 12
    jr $ra
