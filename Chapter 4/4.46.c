/*
 * 
 * 1.
 * 
 * No
 * If REG is set to %rsp , (movq (%rsp), REG) pop right value into %rsp , but (addq $8, %rsp) modify it.  
 * 
 * 2.
 * 
 * addq $8, %rsp
 * movq -8(%rsp), REG
 * 
 */