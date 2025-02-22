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

int main() {
    printf("the MSB is : %d", IsMSBSet(429496729));
    return 0;
}
=======
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

int main() {
    printf("the MSB is : %d", IsMSBSet(429496729));
    return 0;
}
