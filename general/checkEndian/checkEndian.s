	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 10
	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp0:
	.cfi_def_cfa_offset 16
Ltmp1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp2:
	.cfi_def_cfa_register %rbp
	pushq	%rbx
	pushq	%rax
Ltmp3:
	.cfi_offset %rbx, -24
	leaq	L_.str(%rip), %rbx
	movl	$16777216, %esi         ## imm = 0x1000000
	xorl	%eax, %eax
	movq	%rbx, %rdi
	callq	_printf
	leaq	L_.str2(%rip), %rdi
	xorl	%eax, %eax
	callq	_printf
	movl	$1, %esi
	xorl	%eax, %eax
	movq	%rbx, %rdi
	callq	_printf
	xorl	%eax, %eax
	addq	$8, %rsp
	popq	%rbx
	popq	%rbp
	retq
	.cfi_endproc

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%lu\n"

L_.str2:                                ## @.str2
	.asciz	"You're using Little Endian format."


.subsections_via_symbols
