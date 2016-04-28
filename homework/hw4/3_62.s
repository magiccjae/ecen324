	.file	"3_62.c"
	.text
	.p2align 4,,15
.globl transpose_optimized
	.type	transpose_optimized, @function
transpose_optimized:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	movl	$52, %edi
	pushl	%esi
	pushl	%ebx
	subl	$4, %esp
	movl	8(%ebp), %ecx
	movl	$0, -16(%ebp)
	addl	$1, -16(%ebp)
	addl	$4, %ecx
	cmpl	$13, -16(%ebp)
	je	.L8
	.p2align 4,,7
	.p2align 3
.L4:
	movl	8(%ebp), %edx
	xorl	%eax, %eax
	addl	%edi, %edx
	.p2align 4,,7
	.p2align 3
.L3:
	movl	(%edx), %ebx
	movl	(%ecx,%eax), %esi
	movl	%esi, (%edx)
	addl	$4, %edx
	movl	%ebx, (%ecx,%eax)
	addl	$52, %eax
	cmpl	%eax, %edi
	jne	.L3
	addl	$1, -16(%ebp)
	addl	$4, %ecx
	addl	$52, %edi
	cmpl	$13, -16(%ebp)
	jne	.L4
.L8:
	addl	$4, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.size	transpose_optimized, .-transpose_optimized
	.ident	"GCC: (GNU) 4.4.7 20120313 (Red Hat 4.4.7-3)"
	.section	.note.GNU-stack,"",@progbits
