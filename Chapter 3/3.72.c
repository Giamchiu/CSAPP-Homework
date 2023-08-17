/*
 * 
 * A.
 * 
 * if n = Odd
 * 8n + 30 mod 16 = 8n + 24
 * if n = Even
 * 8n + 30 mod 16 = 8n + 16
 * 
 * B.
 * 
 * p = (s2 + 0xF) & 0xFFFFFFF0  
 * 
 * C.
 * 
 * if n = Even  e2 = 15  e1 = 1   s1%16 = 1 
 * if n = Odd   e2 = 0   e1 = 24  s1%16 = 0
 * 
 * D.
 * p is aligned by 16.
 * s2 is the least multiple of 16 that preserve 8*n size space.
 * 
 */ 