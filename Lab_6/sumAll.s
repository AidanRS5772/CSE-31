.data
prompt: .asciiz "Please enter a number: "
even: .asciiz "Sum of even numbers is: "
odd: .asciiz "Sum of odd numbers is: "
nl: .asciiz "\n"

.text
main:
    li $s0, 0 #even sum
    li $s1, 0 #odd sum
    loop:
        # print prompt
        li $v0, 4
        la $a0, prompt
        syscall
        # read number
        li $v0, 5
        syscall
        move $t0, $v0

        beq $t0, $zero, after #break

        #check odd/even and sum
        srl $t1, $t0, 1
        sll $t1, $t1, 1
        bne $t1, $t0, else # if t1 == t0
        add $s0, $s0, $t0 # add to even sum
        j loop
        else:
        add $s1, $s1, $t0 # add to odd sum
        j loop
    after:
    li $v0, 4
    la $a0, nl
    syscall

    #print even sum
    la $a0, even
    syscall
    li $v0, 1
    move $a0, $s0
    syscall
    li $v0, 4
    la $a0, nl
    syscall

    #print odd sum
    li $v0, 4
    la $a0, odd
    syscall
    li $v0, 1
    move $a0, $s1
    syscall
    li $v0, 4
    la $a0, nl
    syscall

    li $v0, 10
    syscall
