/*
 * 
 * 1.
 * 
 * No
 * If REG is set to %rsp , it should store %rsp on the stack , but the current value is %rsp - 8. 
 * 
 * 2.
 * 
 * movq REG, -8(%rsp)
 * sub %8, %rsp
 * 
 */