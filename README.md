# C-bit-manipulation
this repository containes implementation of bit manipulation functions in C usually asked in embedded software position interviews, like bitwise operation related question, in this repo we will go through those problems and we will try to solve them with a given explication for each problem and the proposed solution.
## IsLSBSet
this problem is for checking wether the LSB (the bit in the right) is 1 or not. 
In many bit manipulation problem we use the number 1, to either get a certain bit with the number that we work with, for example in this problem we have to get the last significant bit, which is the top left bit, if you think about doing the and operation with the number 1 the result of the operation will give you exactly that bit ex: 
01011011 
00000001
--------
00000001 which is the LSB 
another example: 
01101110 (has 0 as LSB)
00000001
--------
00000000 which is exactly the lsb that we are looking for, since now we can acess that bit then a simple condition to see wether the LSB is set or not and return the result. 