//
//  BitManipulation.cpp
//  Tricks
//
//  Created by Dat Nguyen on 27/10/2013.
//  Copyright (c) 2013 Dat Nguyen. All rights reserved.
//

#include "BitManipulation.h"

#define CHAR_BIT 8
void IntegerSign()
{
//    In the first approach, the problem of representing a number's sign can be to allocate one sign bit to represent the sign: set that bit (often the most significant bit) to 0 for a positive number, and set to 1 for a negative number. The remaining bits in the number indicate the magnitude (or absolute value). Hence in a byte with only 7 bits (apart from the sign bit), the magnitude can range from 0000000 (0) to 1111111 (127).
    
    int v = -45;      // we want to find the sign of v
    int sign;   // the result goes here
    
    // CHAR_BIT is the number of bits per byte (normally 8).
    sign = -(v < 0);  // if v < 0 then -1, else 0. Because true == 1 and False == 0
    
    // or, to avoid branching on CPUs with flag registers (IA32):
    sign = -(int)((unsigned int)((int)v) >> (sizeof(int) * CHAR_BIT - 1));
    
    // or, for one less instruction (but not portable):
    sign = v >> (sizeof(int) * CHAR_BIT - 1);
}

void OppositeSign()
{
    int x = 8, y = -8;   // input values to compare signs
    
    bool f = ((x ^ y) < 0); // true if x and y have opposite signs. ^ is XOR 1 will be set if both are different
}

void IntegerAbsoluteValue()
{
//   In mathematics, the absolute value (or modulus) |x| of a real number x is the non-negative value of x without regard to its sign. Namely, |x| = x for a positive x, |x| = −x for a negative x, and |0| = 0. For example, the absolute value of 3 is 3, and the absolute value of −3 is also 3. The absolute value of a number may be thought of as its distance from zero.

    int v = 3;         // we want to find the absolute value of v
    unsigned int r;     // the result goes here
    int const mask = v >> sizeof(int) * CHAR_BIT - 1; // 1 for '-' and 0 or '+'
    
    r = (v + mask) ^ mask;
    
//Some CPUs don't have an integer absolute value instruction (or the compiler fails to use them). On machines where branching is expensive, the above expression can be faster than the obvious approach, r = (v < 0) ? -(unsigned)v : v, even though the number of operations is the same.
}

void IntegerMin()
{
    int x = 10, y = 9;
    int r; // the result goes here
    
    r = y ^ ((x ^ y) & -(x < y)); // min(x,y)
    
//    On some rare machines where branching is very expensive and no condition move instructions exist, the above expression might be faster than the obvious approach, r = (x < y) ? x : y, even though it involves two more instructions. (Typically, the obvious approach is best, though.) It works because if x < y, then -(x < y) will be all ones, so r = y ^ (x ^ y) & ~0 = y ^ x ^ y = x. Otherwise, if x >= y, then -(x < y) will be all zeros, so r = y ^ ((x ^ y) & 0) = y. On some machines, evaluating (x < y) as 0 or 1 requires a branch instruction, so there may be no advantage.
    
}

void IntegerMax()
{
    int x = 10, y = 9;
    int r; // the resukt goes here
    
    r = x ^ ((x ^ y) & -(x < y)); // max(x, y)
}

void isPowerOfTwo()
{
    unsigned int v = 8; // we want to see if v is a power of 2
    bool f;             // the result goes here
    
    f = (v & (v - 1)) == 0;
    
    //Note that 0 is incorrectly considered a power of 2 here. To remedy this, use:
    f = v && !(v & (v - 1));
}

void signExtendingConstantBitWidth()
{
//    Sign extension is automatic for built-in types, such as chars and ints. But suppose you have a signed two's complement number, x, that is stored using only b bits. Moreover, suppose you want to convert x to an int, which has more than b bits. A simple copy will work if x is positive, but if negative, the sign must be extended. For example, if we have only 4 bits to store a number, then -3 is represented as 1101 in binary. If we have 8 bits, then -3 is 11111101. The most-significant bit of the 4-bit representation is replicated sinistrally to fill in the destination when we convert to a representation with more bits; this is sign extending. In C, sign extension from a constant bit-width is trivial, since bit fields may be specified in structs or unions. For example, to convert from 5 bits to an full integer:
    
    int x = -3; // convert this from using 5 bits to a full int
    int r; // resulting sign extended number goes here
    struct {signed int x:5;} s;
    r = s.x = x;
}

void signExtendingVariableBitWidth()
{
//    Sometimes we need to extend the sign of a number but we don't know a priori the number of bits, b, in which it is represented. (Or we could be programming in a language like Java, which lacks bitfields.)

    unsigned b = 5; // number of bits representing the number in x
    int x = -3;      // sign extend this b-bit number to r
    int r;      // resulting sign-extended number
    int const m = 1U << (b - 1); // mask can be pre-computed if b is fixed
    
    x = x & ((1U << b) - 1);  // (Skip this if bits in x above position b are already zero.)
    r = (x ^ m) - m;
    
//    The code above requires four operations, but when the bitwidth is a constant rather than variable, it requires only two fast operations, assuming the upper bits are already zeroes.
}

void conditionallySetClearBits()
{
    // Conditionally set or clear bits without branching
    bool f = true;         // conditional flag
    unsigned int m = 8; // the bit mask
    unsigned int w = 4; // the word to modify:  if (f) w |= m; else w &= ~m;
    
    w ^= (-f ^ w) & m;
}

void conditionallyNegateValue()
{
    // If you need to negate only when a flag is false, then use the following to avoid branching
    
    bool fDontNegate = true;    // Flag indicating we should not negate v.
    int v = 5;                  // Input value to negate if fDontNegate is false.
    int r;                      // result = fDontNegate ? v : -v;
    
    r = (fDontNegate ^ (fDontNegate - 1)) * v;
    
    // if you need to negate only when a flag is true, then use this:
    bool fNegate;  // Flag indicating if we should negate v.
    
    r = (v ^ -fNegate) + fNegate;
}

void mergeBits()
{
    //Merge bits from two values according to a mask
    
    unsigned int a = 4;    // value to merge in non-masked bits
    unsigned int b = 5;    // value to merge in masked bits
    unsigned int mask = 1; // 1 where bits from b should be selected; 0 where from a.
    unsigned int r;    // result of (a & ~mask) | (b & mask) goes here
    
    r = a ^ ((a ^ b) & mask);
    //This shaves one operation from the obvious way of combining two sets of bits according to a bit mask. If the mask is a constant, then there may be no advantage.
}

void countingBits()
{
    //Counting bits set (naive way)
    
    unsigned int v = 99; // count the number of bits set in v
    unsigned int c; // c accumulates the total bits set in v
    
    for (c = 0; v; v >>= 1)
    {
        c += v & 1;
    }
    //The naive approach requires one iteration per bit, until no more bits are set. So on a 32-bit word with only the high set, it will go through 32 iterations.
   
    {
        //Counting bits set, Brian Kernighan's way
    
        unsigned int v = 99; // count the number of bits set in v
        unsigned int c; // c accumulates the total bits set in v
        for (c = 0; v; c++)
        {
            v &= v - 1; // clear the least significant bit set
        }
        //Brian Kernighan's method goes through as many iterations as there are set bits. So if we have a 32-bit word with only the high bit set, then it will only go once through the loop.
    }
    
    {
        //Counting bits set, in parallel
        
        unsigned int v = 99; // count bits set in this (32-bit value)
        unsigned int c; // store the total here
        static const int S[] = {1, 2, 4, 8, 16}; // Magic Binary Numbers
        static const int B[] = {0x55555555, 0x33333333, 0x0F0F0F0F, 0x00FF00FF, 0x0000FFFF};
        
        c = v - ((v >> 1) & B[0]);
        c = ((c >> S[1]) & B[1]) + (c & B[1]);
        c = ((c >> S[2]) + c) & B[2];
        c = ((c >> S[3]) + c) & B[3];
        c = ((c >> S[4]) + c) & B[4];
        
        //The B array, expressed as binary, is:
        //B[0] = 0x55555555 = 01010101 01010101 01010101 01010101
        //B[1] = 0x33333333 = 00110011 00110011 00110011 00110011
        //B[2] = 0x0F0F0F0F = 00001111 00001111 00001111 00001111
        //B[3] = 0x00FF00FF = 00000000 11111111 00000000 11111111
        //B[4] = 0x0000FFFF = 00000000 00000000 11111111 11111111
        
        //We can adjust the method for larger integer sizes by continuing with the patterns for the Binary Magic Numbers, B and S. If there are k bits, then we need the arrays S and B to be ceil(lg(k)) elements long, and we must compute the same number of expressions for c as S or B are long. For a 32-bit v, 16 operations are used.
        
        //The best method for counting bits in a 32-bit integer v is the following:
        v = v - ((v >> 1) & 0x55555555);                    // reuse input as temporary
        v = (v & 0x33333333) + ((v >> 2) & 0x33333333);     // temp
        c = ((v + (v >> 4) & 0xF0F0F0F) * 0x1010101) >> 24; // count
        
        
        //The best bit counting method takes only 12 operations, which is the same as the lookup-table method, but avoids the memory and potential cache misses of a table. It is a hybrid between the purely parallel method above and the earlier methods using multiplies (in the section on counting bits with 64-bit instructions), though it doesn't use 64-bit instructions. The counts of bits set in the bytes is done in parallel, and the sum total of the bits set in the bytes is computed by multiplying by 0x1010101 and shifting right 24 bits.
    }
    
    {
        //Count bits set (rank) from the most-significant bit upto a given position
        
        //The following finds the the rank of a bit, meaning it returns the sum of bits that are set to 1 from the most-signficant bit downto the bit at the given position.
        uint64_t v = 5;       // Compute the rank (bits set) in v from the MSB to pos.
        unsigned int pos = 2; // Bit position to count bits upto.
        uint64_t r;       // Resulting rank of bit at pos goes here.
        
        // Shift out bits after given position.
        r = v >> (sizeof(v) * CHAR_BIT - pos);
        // Count set bits in parallel.
        // r = (r & 0x5555...) + ((r >> 1) & 0x5555...);
        r = r - ((r >> 1) & ~0UL/3);
        // r = (r & 0x3333...) + ((r >> 2) & 0x3333...);
        r = (r & ~0UL/5) + ((r >> 2) & ~0UL/5);
        // r = (r & 0x0f0f...) + ((r >> 4) & 0x0f0f...);
        r = (r + (r >> 4)) & ~0UL/17;
        // r = r % 255;
        r = (r * (~0UL/255)) >> ((sizeof(v) - 1) * CHAR_BIT);
    }
}

void countingBitsLookupTable()
{
    unsigned char BitsSetTable256[256] =
    {
#   define B2(n) n,     n+1,     n+1,     n+2
#   define B4(n) B2(n), B2(n+1), B2(n+1), B2(n+2)
#   define B6(n) B4(n), B4(n+1), B4(n+1), B4(n+2)
        B6(0), B6(1), B6(1), B6(2)
    };
    
    unsigned int v = 21; // count the number of bits set in 32-bit value v
    unsigned int c; // c is the total bits set in v
    
    // Option 1:
    c = BitsSetTable256[v & 0xff] +
    BitsSetTable256[(v >> 8) & 0xff] +
    BitsSetTable256[(v >> 16) & 0xff] +
    BitsSetTable256[v >> 24];
    
    // Option 2:
    unsigned char * p = (unsigned char *) &v;
    c = BitsSetTable256[p[0]] +
    BitsSetTable256[p[1]] +
    BitsSetTable256[p[2]] +
    BitsSetTable256[p[3]];
    
    
    // To initially generate the table algorithmically:
    BitsSetTable256[0] = 0;
    for (int i = 0; i < 256; i++)
    {
        BitsSetTable256[i] = (i & 1) + BitsSetTable256[i / 2];
    }
}

void selectBitPosGivenCount()
{
    //Select the bit position (from the most-significant bit) with the given count (rank)
    
    //The following 64-bit code selects the position of the rth 1 bit when counting from the left. In other words if we start at the most significant bit and proceed to the right, counting the number of bits set to 1 until we reach the desired rank, r, then the position where we stop is returned. If the rank requested exceeds the count of bits set, then 64 is returned. The code may be modified for 32-bit or counting from the right.
    
    uint64_t v = 99;          // Input value to find position with rank r.
    unsigned int r = 32;      // Input: bit's desired rank [1-64].
    unsigned int s;      // Output: Resulting position of bit with rank r [1-64]
    uint64_t a, b, c, d; // Intermediate temporaries for bit count.
    unsigned int t;      // Bit count temporary.
    
    // Do a normal parallel bit count for a 64-bit integer,
    // but store all intermediate steps.
    // a = (v & 0x5555...) + ((v >> 1) & 0x5555...);
    a =  v - ((v >> 1) & ~0UL/3);
    // b = (a & 0x3333...) + ((a >> 2) & 0x3333...);
    b = (a & ~0UL/5) + ((a >> 2) & ~0UL/5);
    // c = (b & 0x0f0f...) + ((b >> 4) & 0x0f0f...);
    c = (b + (b >> 4)) & ~0UL/0x11;
    // d = (c & 0x00ff...) + ((c >> 8) & 0x00ff...);
    d = (c + (c >> 8)) & ~0UL/0x101;
    t = (d >> 32) + (d >> 48);
    // Now do branchless select!
    s  = 64;
    // if (r > t) {s -= 32; r -= t;}
    s -= ((t - r) & 256) >> 3; r -= (t & ((t - r) >> 8));
    t  = (d >> (s - 16)) & 0xff;
    // if (r > t) {s -= 16; r -= t;}
    s -= ((t - r) & 256) >> 4; r -= (t & ((t - r) >> 8));
    t  = (c >> (s - 8)) & 0xf;
    // if (r > t) {s -= 8; r -= t;}
    s -= ((t - r) & 256) >> 5; r -= (t & ((t - r) >> 8));
    t  = (b >> (s - 4)) & 0x7;
    // if (r > t) {s -= 4; r -= t;}
    s -= ((t - r) & 256) >> 6; r -= (t & ((t - r) >> 8));
    t  = (a >> (s - 2)) & 0x3;
    // if (r > t) {s -= 2; r -= t;}
    s -= ((t - r) & 256) >> 7; r -= (t & ((t - r) >> 8));
    t  = (v >> (s - 1)) & 0x1;
    // if (r > t) s--;
    s -= ((t - r) & 256) >> 8;
    s = 65 - s;
    
    //If branching is fast on your target CPU, consider uncommenting the if-statements and commenting the lines that follow them.
}


void computeParity()
{
    //Compute parity by lookup table
    
    static const bool ParityTable256[256] =
    {
#   define P2(n) n, n^1, n^1, n
#   define P4(n) P2(n), P2(n^1), P2(n^1), P2(n)
#   define P6(n) P4(n), P4(n^1), P4(n^1), P4(n)
        P6(0), P6(1), P6(1), P6(0)
    };
    
    unsigned char b = 6;  // byte value to compute the parity of
    bool parity = ParityTable256[b];
    
    {
        // OR, for 32-bit words:
        unsigned int v = 22;
        v ^= v >> 16;
        v ^= v >> 8;
        bool parity = ParityTable256[v & 0xff];
    
        // Variation:
        unsigned char * p = (unsigned char *) &v;
        parity = ParityTable256[p[0] ^ p[1] ^ p[2] ^ p[3]];
    }
    
    {
        //Compute parity of a byte using 64-bit multiply and modulus division
        
        unsigned char b = 4;  // byte value to compute the parity of
        bool parity = (((b * 0x0101010101010101ULL) & 0x8040201008040201ULL) % 0x1FF) & 1;
        
        //The method above takes around 4 operations, but only works on bytes.
    }
    
    {
        //Compute parity of word with a multiply
        
        //The following method computes the parity of the 32-bit value in only 8 operations using a multiply.
        {
            unsigned int v = 8; // 32-bit word
            v ^= v >> 1;
            v ^= v >> 2;
            v = (v & 0x11111111U) * 0x11111111U;
            (v >> 28) & 1;
        }
        {
            //Also for 64-bits, 8 operations are still enough.
            unsigned long long v; // 64-bit word
            v ^= v >> 1;
            v ^= v >> 2;
            v = (v & 0x1111111111111111UL) * 0x1111111111111111UL;
            (v >> 60) & 1;
        }
    }
    
    {
        //Compute parity in parallel
        
        unsigned int v = 8;  // word value to compute the parity of
        v ^= v >> 16;
        v ^= v >> 8;
        v ^= v >> 4;
        v &= 0xf;
        (0x6996 >> v) & 1;
        
        //The method above takes around 9 operations, and works for 32-bit words. It may be optimized to work just on bytes in 5 operations by removing the two lines immediately following "unsigned int v;". The method first shifts and XORs the eight nibbles of the 32-bit value together, leaving the result in the lowest nibble of v. Next, the binary number 0110 1001 1001 0110 (0x6996 in hex) is shifted to the right by the value represented in the lowest nibble of v. This number is like a miniature 16-bit parity-table indexed by the low four bits in v. The result has the parity of v in bit 1, which is masked and returned.
    }

}

void swap()
{
    {
        int a = 3, b = 6;
        //Swapping values with subtraction and addition
        ((&(a) == &(b)) || (((a) -= (b)), ((b) += (a)), ((a) = (b) - (a))));
    
        //This swaps the values of a and b without using a temporary variable. The initial check for a and b being the same location in memory may be omitted when you know this can't happen. (The compiler may omit it anyway as an optimization.) If you enable overflows exceptions, then pass unsigned values so an exception isn't thrown. The XOR method that follows may be slightly faster on some machines. Don't use this with floating-point numbers (unless you operate on their raw integer representations).
    }
    
    {
        int a = 3, b = 6;
        //Swapping values with XOR
        
        (((a) ^= (b)), ((b) ^= (a)), ((a) ^= (b)));
        //This is an old trick to exchange the values of the variables a and b without using extra space for a temporary variable.
    }
    
    {
        //Swapping individual bits with XOR
        
        unsigned int i = 1, j = 5; // positions of bit sequences to swap
        unsigned int n = 3;    // number of consecutive bits in each sequence
        unsigned int b = 47;    // bits to swap reside in b
        unsigned int r;    // bit-swapped result goes here
        
        unsigned int x = ((b >> i) ^ (b >> j)) & ((1U << n) - 1); // XOR temporary
        r = b ^ ((x << i) | (x << j));
        
        //As an example of swapping ranges of bits suppose we have have b = 00101111 (expressed in binary) and we want to swap the n = 3 consecutive bits starting at i = 1 (the second bit from the right) with the 3 consecutive bits starting at j = 5; the result would be r = 11100011 (binary).
        //This method of swapping is similar to the general purpose XOR swap trick, but intended for operating on individual bits.  The variable x stores the result of XORing the pairs of bit values we want to swap, and then the bits are set to the result of themselves XORed with x.  Of course, the result is undefined if the sequences overlap.
    }
}

void reverseBits()
{
    {
        //Reverse bits the obvious way
    
        unsigned int v = 47;     // input bits to be reversed
        unsigned int r = v; // r will be reversed bits of v; first get LSB of v
        int s = sizeof(v) * CHAR_BIT - 1; // extra shift needed at end
    
        for (v >>= 1; v; v >>= 1)
        {
            r <<= 1;
            r |= v & 1;
            s--;
        }
    
        r <<= s; // shift when v's highest bits are zero
    }
    
    {
        //Reverse bits in word by lookup table
        static const unsigned char BitReverseTable256[256] =
        {
#   define R2(n)     n,     n + 2*64,     n + 1*64,     n + 3*64
#   define R4(n) R2(n), R2(n + 2*16), R2(n + 1*16), R2(n + 3*16)
#   define R6(n) R4(n), R4(n + 2*4 ), R4(n + 1*4 ), R4(n + 3*4 )
            R6(0), R6(2), R6(1), R6(3)
        };
        
        unsigned int v = 47; // reverse 32-bit value, 8 bits at time
        unsigned int c; // c will get v reversed
        
        // Option 1:
        c = (BitReverseTable256[v & 0xff] << 24) |
        (BitReverseTable256[(v >> 8) & 0xff] << 16) |
        (BitReverseTable256[(v >> 16) & 0xff] << 8) |
        (BitReverseTable256[(v >> 24) & 0xff]);
        
        // Option 2:
        unsigned char * p = (unsigned char *) &v;
        unsigned char * q = (unsigned char *) &c;
        q[3] = BitReverseTable256[p[0]];
        q[2] = BitReverseTable256[p[1]]; 
        q[1] = BitReverseTable256[p[2]]; 
        q[0] = BitReverseTable256[p[3]];
        
        //The first method takes about 17 operations, and the second takes about 12, assuming your CPU can load and store bytes easily.
    }
}











































