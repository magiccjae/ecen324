	.file	"3_59.c"
	.text
.globl switch_prob
	.type	switch_prob, @function
switch_prob:
	pushl	%ebp
	movl	%esp, %ebp
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	subl	$50, %edx
	cmpl	$5, %edx
	ja	.L8
	jmp	*.L7(,%edx,4)
	.section	.rodata
	.align 4
	.align 4
.L7:
	.long	.L3 case 50
	.long	.L8 case 51
	.long	.L3 case 52
	.long	.L4 case 53
	.long	.L5 case 54
	.long	.L9 case 55
	.text
.L3:
	sall	$2, %eax
	jmp	.L10
.L4:
	sarl	$2, %eax
	.p2align 4,,5
	jmp	.L10
.L5:
	leal	(%eax,%eax,2), %eax
.L9:
	imull	%eax, %eax
.L8:
	addl	$10, %eax
.L10:
	popl	%ebp
	ret
	.size	switch_prob, .-switch_prob
	.ident	"GCC: (GNU) 4.4.7 20120313 (Red Hat 4.4.7-3)"
	.section	.note.GNU-stack,"",@progbits
