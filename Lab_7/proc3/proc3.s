.data
msg: .asciiz "p + q: "
x: .word 2
y: .word 4
z: .word 6

.text
main:
    la $t0, x
    lw $s0, 0($t0)
    la $t0, y
    lw $s1, 0($t0)
    la $t0, z
    lw $s2, 0($t0)

    move $a0, $s0
    move $a1, $s1
    move $a2, $s2
    jal foo
    move $t0, $v0

    add $t0, $t0, $s0
    add $t0, $t0, $s1
    add $t0, $t0, $s2

    li $v0, 1
    move $a0, $t0
    syscall
    li $v0, 11
    li $a0, '\n'
    syscall

    li $v0, 10
    syscall

foo:
    addiu $sp, $sp, -20
    sw $ra, 0($sp)
    sw $s0, 4($sp)
    sw $s1, 8($sp)
    sw $s2, 12($sp)
    sw $s3, 16($sp)

    move $s0, $a0
    move $s1, $a1
    move $s2, $a2

    add $a0, $s0, $s2
    add $a1, $s1, $s2
    add $a2, $s0, $s1
    jal bar
    move $s3, $v0

    sub $a0, $s0, $s2
    sub $a1, $s1, $s0
    add $a2, $s1, $s1
    jal bar
    move $t0, $v0

    add $t1, $t0, $s3

    li $v0, 4
    la $a0, msg
    syscall
    li $v0, 1
    move $a0, $t1
    syscall
    li $v0, 11
    li $a0, '\n'
    syscall

    move $v0, $t1
    lw $ra, 0($sp)
    lw $s0, 4($sp)
    lw $s1, 8($sp)
    lw $s2, 12($sp)
    lw $s3, 16($sp)
    addiu $sp, $sp, 20
    jr $ra

bar:
    sub $t0, $a1, $a0
    sll $v0, $t0, $a2
    jr $ra
