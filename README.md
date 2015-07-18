# bithacking
Compiling a set of bithacking problems for reference.  

Some useful info:  

0110 + 0110 is equivalent to 0110 * 2 which is 0110 << 1.  

0100 * 0011 is equivalent to left shift by 2. Multiplying with a power of 2 is the same as left shifting by the power.  

To clear out the last n bits: x & (~0 << n)  
  
x ^ 0s = x  
x & 0s = 0  
x | 0s = x  
x ^ 1s = ~x  
x & 1s = x  
x | 1s = 1s  
x ^ x = 0  
x & x = x  
x | x = x  
  
get bit: (1 << i) & n  
set bit: (1 << i) | n  
clear bit: ~(1 << i) & n  
clear MS bits: ((1 << i) -1) & n  
clear LS bits:  (~((1 << i) -1)) & n 

Problem Set:  

1. You are given 2 32 bit numbers M and N and 2 bit positions i and j (j>i and j-i = number of bits in M). We need to replace bits i through j in N with M.  

2. Print the binary representation of a real number between 0 and 1. If the number is outside this range print error. If the binary representation is more than 32 bits, print error.  

3. Find the next biggest number with the same number of 1 bits.  

4. What does this do: ((n & (n-1)) == 0) ? Solution: If this condition is true, n is a power of 2.
  
5. How many bits need to be changed to go from int M to int N?

6. How many 1s are in a given int M?

7. Swap even and odd bits in an int M.  

8. Create a bitmap API.
