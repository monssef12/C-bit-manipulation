#include <stdio.h>
#include <math.h>

int IsLsbSet(int x){
    return 1&x;
}

int IsMSBSet(int x){
    return (x & (1 << (sizeof(int) * 8 - 1))) != 0;
}

int get_nth_number(int x, int i){
    return (x & (1 << i)) != 0;
}

int set_nth(int x, int i){
    return x | (1 << i);
}

int toggle_nth_bit(int x, int i){
    return x ^ ( 1<< i);
}

int Get_High_SetBit(int x){ // in 8-bit system the 0x01000 has the highest set bit in the position 3 
    int order;
    if(x == 0){return -1;}
    else{
        for (int i = 0; i < sizeof(int)*8; i++)
        {
            if ((x>>i) & 1){order = i;}
        }
        return order;
        } 
}

int Get_Lowest_SetBit(int x){ // in 8 bit; the number0x00101010 has the lowest set bit in the position 1
    int i = 0;
    if (x == 0){return -1;}
    else{
    while (((x >> i) & 1) == 0)
    {
        i = i + 1;
    }
    return i;
    }
}

int Get_Trailing_Zeros(int x){
    int i = 0;
    if(x == 0){return sizeof(int)*8;}
    while(((x >> i) & 1) == 0){
        i++;
    }
    return i;
}

int Get_Leading_Zeros(int x){
    int count = 0;
    for (int i = sizeof(int)*8 -1 ; i >= 0 ; i--)
    {
        if ((x & (1<<i))==0){
            count ++;
        }else{
            break;
        }
    }
    return count;
}


int Clear_Nth_bit(int x, int n){
    return x &=~(1 << n);
}

int Toggle_Nth_bit(int x, int n){
    return x ^= (1<<n);
}

int IsPowerOfTwo(int x){
    if (x == 0){return 0;}
    return (x & (x-1)) == 0;
}

int NumOf1Bit(int x){
    int count = 0;
    while (x != 0)
    {
        if((x&1) == 1)
        {
            count = count + 1;
        }
        x = (x>>1);
    }
    return count;
}

int SwapEndians(int x){
    // ex: 0b 0100 0110 1111 0000 0101 0111 1001 1000 ---> 0b 1001 1000 0101 0111 1111 0000 0100 0110
    int result = 0;
    int first_byte, second_byte, third_byte, forth_byte; // the first byte here is the leftmost byte 

    first_byte = (x & 0xff000000) >> 24; // get the leftmost byte and shift it by 24 bits to put it in the right most
    second_byte = (x & 0x00ff0000) >> 8; // get the second byte and shift it by 8 bits to be the third one in the output 
    third_byte = (x & 0x0000ff00) << 8;  // get the third byte and shift it by 8 bits to the left to be the second byte in the output
    forth_byte = (x & 0x000000ff) << 24; // ....

    result = first_byte | second_byte | third_byte | forth_byte;
    return result;

}


int ReverseBits(int x){ //ex: 0b01011 -> 0b11010
    int result = 0;
    int current ;

    for (int i = sizeof(int)*8 - 1; i >= 0; i--)
    {
        current = (1 & x); 
        x = x >> 1;
        result = result | (current << i);
        /* code */
    }
    return result;
}

int SwapBits(int x, int i, int j){
    x ^= (1 << i);
    x ^= (1 << j);
    return x;

}

int SwapOddEven(int x){   // 0110101 --> 00111010 
    int i = 0;
    int j = 1;
    while (i <= sizeof(int)*8-1)
    {
        if ((1 & (x>>i)) != (1 & (x>>j))){
        
        x ^= (1 << i);
        x ^= (1 << j);
        }
        i+=2;
        j+=2;
    }
    return x;
}

void PrintBinary(int num) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
        if (i % 4 == 0) printf(" ");  // Add spaces for readability
    }
}
int main() {

    // manualy test functions 
    PrintBinary(SwapOddEven(0b10010011001101000101011001111001));
    return 0;
}
