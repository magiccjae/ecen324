	.file	"3_54.c"
	.text
.globl decode2
	.type	decode2, @function
decode2:
	pushl	%ebp
	movl	%esp, %ebp
	movl	12(%ebp), %edx
	subl	16(%ebp), %edx
	movl	%edx, %eax
	sall	$31, %eax
	sarl	$31, %eax
	imull	8(%ebp), %edx
	xorl	%edx, %eax
	popl	%ebp
	ret
	.size	decode2, .-decode2
	.ident	"GCC: (GNU) 4.4.7 20120313 (Red Hat 4.4.7-3)"
	.section	.note.GNU-stack,"",@progbits
