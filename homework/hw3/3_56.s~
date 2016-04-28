	.file	"3_56.c"
	.text
.globl loop
	.type	loop, @function
loop:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%esi
	pushl	%ebx
	movl	8(%ebp), %ebx
	movl	12(%ebp), %ecx
	movl	$1, %edx
	movl	$-1, %eax
.L2:
	movl	%edx, %esi
	andl	%ebx, %esi
	xorl	%esi, %eax
	sall	%cl, %edx
	testl	%edx, %edx
	jne	.L2
	popl	%ebx
	popl	%esi
	popl	%ebp
	ret
	.size	loop, .-loop
	.ident	"GCC: (GNU) 4.4.7 20120313 (Red Hat 4.4.7-3)"
	.section	.note.GNU-stack,"",@progbits
