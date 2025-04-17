.data
n: .word 25
str1: .asciiz "Less than\n"
str2: .asciiz "Less than or equal to\n"
str3: .asciiz "Greater than\n"
str4: .asciiz "Greater than or equal to\n"

.text
main:
    li $v0, 5
    syscall
    move $t0, $v0

    la $t1, n
    lw $t1, 0($t1)

    ble $t0, $t1, else
    li $v0, 4
    la $a0, str3
    syscall
    j exit

    else:
    li $v0, 4
    la $a0, str2
    syscall

exit:
    li $v0, 10
    syscall
