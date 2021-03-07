	.file	"2.c"
	.section	.rodata
.LC0:
	.string	"%d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$16, %esp
.L2:
	movl	a.1826, %eax
	leal	1(%eax), %edx
	movl	%edx, a.1826
	movl	%eax, 4(%esp)
	movl	$.LC0, (%esp)
	call	printf
	movl	$1, (%esp)
	call	sleep
	jmp	.L2
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.data
	.align 4
	.type	a.1826, @object
	.size	a.1826, 4
a.1826:
	.long	5
	.ident	"GCC: (Ubuntu 4.8.2-19ubuntu1) 4.8.2"
	.section	.note.GNU-stack,"",@progbits
