# bithacking
Compiling a set of bithacking problems for reference.

Some useful info:

0110 + 0110 is equivalent to 0110 * 2 which is 0110 << 1.

0100 * 0011 is equivalent to left shift by 2. Multiplying with a power of 2 is the same as left shifting by the power.

To clear out the last n bits: x & (~0 << n)
