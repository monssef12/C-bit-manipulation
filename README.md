C-bit-manipulation
This repository contains implementations of bit manipulation functions in C, often asked in embedded software position interviews.
The repository walks through a set of common problems and explains the proposed solutions.

🧠 IsLsbSet
This problem is for checking whether the LSB (Least Significant Bit — the bit on the right) is 1 or not.
In many bit manipulation problems, we use the number 1 to isolate specific bits. To check the LSB, we perform an AND operation between the number and 1.

If the result is 1, then the LSB is set (i.e., it's 1). If it's 0, the LSB is not set.

🔍 Example 1
markdown
Copy
Edit
01011011
00000001
--------
00000001  -> LSB is 1
🔍 Example 2
markdown
Copy
Edit
01101110
00000001
--------
00000000  -> LSB is 0
✅ Simply check if the result of the AND operation is 1, and return the result accordingly.

🧠 IsMSBSet
This function checks whether the MSB (Most Significant Bit — the bit on the left) is set (i.e., is 1).

In a signed integer, the MSB is used for the sign (1 for negative).
To check the MSB, we shift 1 left by (sizeof(int) * 8 - 1) bits and then AND it with the number.

🔍 Example (32-bit)
bash
Copy
Edit
x = 0b10000000_00000000_00000000_00000000
1 << 31 = 0b10000000_00000000_00000000_00000000
x & (1 << 31) = 0b10000000_00000000_00000000_00000000  (non-zero → MSB is set)
✅ Returns 1 if the MSB is set, otherwise 0.

🧠 get_nth_number
This function checks whether the i-th bit in a number x is set (1) or not.

To do this, we shift 1 to the left by i bits, then perform an AND with x.

🔍 Example
bash
Copy
Edit
x = 0b00001010
i = 3

1 << 3 = 0b00001000
x & (1 << 3) = 0b00001000  → bit is set
✅ Returns 1 if the i-th bit is set, otherwise 0.

🧠 set_nth
This function sets the i-th bit of a number x (i.e., forces it to be 1).

It uses the OR operation with 1 << i.

🔍 Example
bash
Copy
Edit
x = 0b00000000
i = 2

1 << 2 = 0b00000100
x | (1 << 2) = 0b00000100
✅ Returns the new value of x with the i-th bit set.

🧠 toggle_nth_bit
This function toggles (flips) the i-th bit of a number x.

It uses XOR with 1 << i.

🔍 Example
bash
Copy
Edit
x = 0b00000100
i = 2

1 << 2 = 0b00000100
x ^ (1 << 2) = 0b00000000  (bit flipped from 1 to 0)
✅ Returns the new value of x with the i-th bit toggled.