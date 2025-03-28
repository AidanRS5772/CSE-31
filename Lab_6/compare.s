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

    li $v0, 4

    # bge $t0, $t1, else
    # la $a0, str1
    # syscall
    # j exit

    ble $t0, $t1, else
    la $a0, str3
    syscall
    j exit

    else:
        # la $a0, str4
        # syscall

        la $a0, str2
        syscall

exit:
    li $v0, 10
    syscall
