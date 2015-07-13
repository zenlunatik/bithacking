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


