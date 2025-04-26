.data
prompt: .asciiz "Please enter a number: "

.text
main:
    li $t0, 0
	li $t1, 1
	li $v0, 4
	la $a0, prompt
	syscall
	li $v0, 5
	syscall
	move $t3, $v0

fib:
    beq $t3, $0, finish
	add $t2,$t1,$t0
	move $t0, $t1
	move $t1, $t2
	addi $t3, $t3, -1
	j fib

finish:
    move $a0, $t0
	li $v0, 1
	syscall
	li $v0, 10
	syscall
