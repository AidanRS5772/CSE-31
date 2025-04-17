.data
x:  .word 5
y:  .word 10
m:  .word 15
n:  .word 2

.text
main:
    la $t0, x
	lw $s0, 0($t0)		# s0 = x
	la $t0, y
	lw $s1, 0($t0)		# s1 = y

	# Prepare to call sum(x)
	addu $a0, $zero, $s0	# Set a0 as input argument for SUM
	jal SUM
	addu $t0, $s1, $s0
	addu $s1, $t0, $v0
	addiu $a0, $s1, 0
	li $v0, 1
	syscall
	j END

SUM:
    addiu $sp, $sp -4
    sw $ra, 0($sp)

    la $t0, m
	lw $t0, 0($t0)		# t0 = m
	move $t1, $a0
	addu $a0, $t0, $a0	# Update a0 as new argument for SUB
	jal SUB
	move $a0, $t1
	addu $v0, $a0, $v0

	lw $ra, 0($sp)
	addiu $sp, $sp 4
	jr $ra

SUB:
    la $t0, n
	lw $t0, 0($t0)		# Backup s0 from SUM
	subu $v0, $a0, $t0
	jr $ra

END:
    li $v0, 10
    syscall
