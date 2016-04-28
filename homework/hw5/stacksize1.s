	.file	"stacksize1.c"
	.text
.globl max_recursion
	.type	max_recursion, @function
max_recursion:
.LFB11:
	.cfi_startproc
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	%edi, %ebx
	cmpl	$1, %edi
	jg	.L2
	movsd	.LC0(%rip), %xmm0
	jmp	.L3
.L2:
	leal	-1(%rbx), %edi
	call	max_recursion
	cvtsi2sd	%ebx, %xmm1
	addsd	%xmm1, %xmm0
.L3:
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE11:
	.size	max_recursion, .-max_recursion
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC1:
	.string	"Result returned by max_recursion() is %e\n"
	.text
.globl main
	.type	main, @function
main:
.LFB12:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	movl	$524288, %edi
	call	max_recursion
	movl	$.LC1, %edi
	movl	$1, %eax
	call	printf
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE12:
	.size	main, .-main
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC0:
	.long	0
	.long	1072693248
	.ident	"GCC: (GNU) 4.4.7 20120313 (Red Hat 4.4.7-3)"
	.section	.note.GNU-stack,"",@progbits
