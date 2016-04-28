	.file	"examples.c"
	.text
	.p2align 4,,15
.globl sum_list
	.type	sum_list, @function
sum_list:
	pushl	%ebp
	xorl	%eax, %eax
	movl	%esp, %ebp
	movl	8(%ebp), %edx
	testl	%edx, %edx
	je	.L3
	.p2align 4,,7
	.p2align 3
.L6:
	addl	(%edx), %eax
	movl	4(%edx), %edx
	testl	%edx, %edx
	jne	.L6
.L3:
	popl	%ebp
	ret
	.size	sum_list, .-sum_list
	.p2align 4,,15
.globl rsum_list
	.type	rsum_list, @function
rsum_list:
	pushl	%ebp
	xorl	%eax, %eax
	movl	%esp, %ebp
	movl	8(%ebp), %edx
	testl	%edx, %edx
	je	.L11
	.p2align 4,,7
	.p2align 3
.L14:
	movl	(%edx), %ecx
	movl	4(%edx), %edx
	addl	%ecx, %eax
	testl	%edx, %edx
	jne	.L14
.L11:
	popl	%ebp
	ret
	.size	rsum_list, .-rsum_list
	.p2align 4,,15
.globl copy_block
	.type	copy_block, @function
copy_block:
	pushl	%ebp
	xorl	%edx, %edx
	movl	%esp, %ebp
	xorl	%eax, %eax
	movl	16(%ebp), %ecx
	pushl	%edi
	movl	8(%ebp), %edi
	pushl	%esi
	movl	12(%ebp), %esi
	pushl	%ebx
	testl	%ecx, %ecx
	jle	.L18
	.p2align 4,,7
	.p2align 3
.L21:
	movl	(%edi,%edx), %ebx
	movl	%ebx, (%esi,%edx)
	xorl	%ebx, %eax
	addl	$4, %edx
	subl	$1, %ecx
	jne	.L21
.L18:
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.size	copy_block, .-copy_block
	.ident	"GCC: (GNU) 4.4.7 20120313 (Red Hat 4.4.7-3)"
	.section	.note.GNU-stack,"",@progbits
