/*
 * 
 * .pos 0
 * 	irmovq stack, %rsp
 * 	call main
 * 	halt
 *
 * # Array of 4 elements
 * .align 8
 * data:
 *   .quad 0x0000000000000004
 *   .quad 0x0000000000000003
 *   .quad 0x0000000000000002
 * data_end:
 *   .quad 0x0000000000000001
 *
 * main:
 *   irmovq data,%rdi
 * 	irmovq data_end,%rsi
 * 	call ysBubbleP
 * 	ret
 *
 * # long ys_bubble_p(long *data, long *end)
 * # data in %rdi, end in %rsi
 * ysBubbleP:
 *   jmp L2
 * L4:
 *   mrmovq 8(%rax), %r9
 *   mrmovq (%rax), %r10
 *   rrmovq %r9, %r8
 *   subq %r10, %r8
 *   cmovl %r9, %r11
 *   cmovl %r10, %r9
 *   cmovl %r11, %r10
 *   rmmovq %r9, 8(%rax)
 *   rmmovq %r10, (%rax)
 *   jmp L5
 * L6:
 *   rrmovq %rdi, %rax
 * L5:
 *   rrmovq %rsi, %r8
 *   subq %rax, %r8
 *   jg L4
 *   irmovq $8, %r8
 *   subq %r8, %rsi
 * L2:
 *   rrmovq %rsi, %r8
 *   subq %rdi, %r8
 *   jg L6
 * 	ret
 *
 * .pos 0x200
 * stack:
 * 
 */