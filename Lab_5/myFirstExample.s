.data
newline: .asciiz "\n"
reg0: .asciiz "$t0: "
reg1: .asciiz "$t1: "
reg2: .asciiz "$t2: "
reg3: .asciiz "$t3: "
reg4: .asciiz "$t4: "
reg5: .asciiz "$t5: "
reg6: .asciiz "$t6: "
reg7: .asciiz "$t7: "


.text
main:
    li $s0, 7
    add $t0, $s0, $zero
    addi $t1, $t0, -7
    add $t2, $t1, $t0
    addi $t3, $t2, 2
    add $t4, $t3, $t2
    addi $t5, $t4, -28
    sub $t6, $t4, $t5
    addi $t7, $t6, 12

    #print registers
    #print $t0
    li $v0, 4
    la $a0, reg0
    syscall
    li $v0, 1
    add $a0, $t0, $zero
    syscall
    li $v0, 4
    la $a0, newline
    syscall
    #print $t1
    li $v0, 4
    la $a0, reg1
    syscall
    li $v0, 1
    add $a0, $t1, $zero
    syscall
    li $v0, 4
    la $a0, newline
    syscall
    #print $t2
    li $v0, 4
    la $a0, reg2
    syscall
    li $v0, 1
    add $a0, $t2, $zero
    syscall
    li $v0, 4
    la $a0, newline
    syscall
    #print $t3
    li $v0, 4
    la $a0, reg3
    syscall
    li $v0, 1
    add $a0, $t3, $zero
    syscall
    li $v0, 4
    la $a0, newline
    syscall
    #print $t4
    li $v0, 4
    la $a0, reg4
    syscall
    li $v0, 1
    add $a0, $t4, $zero
    syscall
    li $v0, 4
    la $a0, newline
    syscall
    #print $t5
    li $v0, 4
    la $a0, reg5
    syscall
    li $v0, 1
    add $a0, $t5, $zero
    syscall
    li $v0, 4
    la $a0, newline
    syscall
    #print $t6
    li $v0, 4
    la $a0, reg6
    syscall
    li $v0, 1
    add $a0, $t6, $zero
    syscall
    li $v0, 4
    la $a0, newline
    syscall
    #print $t7
    li $v0, 4
    la $a0, reg7
    syscall
    li $v0, 1
    add $a0, $t7, $zero
    syscall
    li $v0, 4
    la $a0, newline
    syscall


    li $v0, 10
    syscall
