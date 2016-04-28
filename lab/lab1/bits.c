/* 
 * CS:APP Data Lab 
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#include "btest.h"
#include <limits.h>

/*
 * Instructions to Students:
 *
 * STEP 1: Fill in the following struct with your identifying info.
 */
team_struct team = 
{
   /* Team name: Replace with the identifying string you want to show
      up on the lab webpage with your results.  It need not be your
      Route Y login(s) if you wish to remain anonymous */
    "JK", 
   /* Student name 1: Replace with the full name of first team member */
   "Jae Lee",
   /* Login ID 1: Replace with the Route Y login ID of first team member */
   "jhl48",

   /* The following should only be changed if there are two team members */
   /* Student name 2: Full name of the second team member */
   "Allen Kim",
   /* Login ID 2: Route Y login ID of the second team member */
   "khkim"
};

#if 0
/*
 * STEP 2: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.
#endif

/*
 * STEP 3: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the btest test harness to check that your solutions produce 
 *      the correct answers. Watch out for corner cases around Tmin and Tmax.
 */
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
  // applying DeMorgan's law, x & y = ~(~x | ~y)
  return ~((~x)|(~y));
}
/* 
 * bitNor - ~(x|y) using only ~ and & 
 *   Example: bitNor(0x6, 0x5) = 0xFFFFFFF8
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitNor(int x, int y) {
  // applying DeMorgan's law, ~(x|y) = ~x & ~y
  return ((~x)&(~y));

}
/* 
 * copyLSB - set all bits of result to least significant bit of x
 *   Example: copyLSB(5) = 0xFFFFFFFF, copyLSB(6) = 0x00000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int copyLSB(int x) {
  // made LSB to be MSB and arithmatic right-shift filling all the numbers with initial LSB
  return (x << 31) >> 31;
}
/* 
 * evenBits - return word with all even-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 2
 */
int evenBits(void) {
  // made initial number 0101 0101 and left shifted
  int initial = 0x55;
  int second = (initial << 8) + initial;
  return (second << 16) + second;
}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 1 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
  // made 0xFFFFFFFF, shifted by (32-n) bits and negated which gives n bits of 0s and rest of the bits are 1s. With this value, AND with x.
  int initial = 0xFF;
  int second = (initial << 8) + initial;
  int third = (second << 16) + second;
  int final = ~(third << (33+(~n)));
  return final & (x >> n);
}
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1

 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
  // x|-x and right-shifting by 31 gives 0xffffffff when x is nonzero or 0x00000000 when x is zero. Adding 1 to this value results in 0 for any x other than 0, 1 for x = 0.
  int initial = x|(~x+1);
  int second = initial >> 31;
  return second + 1;
}
/* 
 * leastBitPos - return a mask that marks the position of the  int msb = (x >> 31) & 0x01;
 *               least significant 1 bit. If x == 0, return 0
 *   Example: leastBitPos(96) = 0x20
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 4 
 */
int leastBitPos(int x) {
  // -x & x gives leastBitPos
  return (~x+1) & x;
}
/* 
 * isNotEqual - return 0 if x == y, and 1 otherwise 
 *   Examples: isNotEqual(5,5) = 0, isNotEqual(4,5) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int isNotEqual(int x, int y) {
  // if x-y is 0 meaning x==y, !!(x-y) gives 0 because !!(x-y) checks if there is any value left.
  return !!(x+(~y)+1);
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  // -x = ~x+1
  return ~x+1;
}
/* 
 * isPositive - return 1 if x > 0, return 0 otherwise 
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */
int isPositive(int x) {
  // positive checks for positive or negative, and nonzero checks for zero or any value.
  int positive = !(x >> 31);
  int nonzero = !!x;
  return positive & nonzero;
}
/* 
 * isNonNegative - return 1 if x >= 0, return 0 otherwise 
 *   Example: isNonNegative(-1) = 0.  isNonNegative(0) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 3
 */
int isNonNegative(int x) {
  // check the MSB if it is 1 or 0.
  return !((x >> 31) & 0x01);
}
/* 
 * sum3 - x+y+z using only a single '+'
 *   Example: sum3(3, 4, 5) = 12
 *   Legal ops: ! ~ & ^ | << >>
 *   Max ops: 16
 *   Rating: 3
 */
/* A helper routine to perform the addition.  Don't change this code */
static int sum(int x, int y) {
  return x+y;
}
int sum3(int x, int y, int z) {
  int word1 = 0;
  int word2 = 0;
  /**************************************************************
     Fill in code below that computes values for word1 and word2
     without using any '+' operations or calling sum()! 
  ***************************************************************/
  // word1 calculates sum without carry-bits, and word2 calculates all the carry bits.
  word1 = x^y^z;
  word2 = ((x&y)|(y&z)|(z&x))<<1;
  /**************************************************************
     Don't change anything below here
  ***************************************************************/
  return sum(word1,word2);
}
/* 
 * addOK - Determine if can compute x+y without overflow
 *   Example: addOK(0x80000000,0x80000000) = 0,
 *            addOK(0x80000000,0x70000000) = 1, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int addOK(int x, int y) {
  // if xmsb & ymsb gives 1, that means the result of adding yields different sign from x and y.
  int sum = x + y;
  int xmsb = ((x^sum) >> 31) & 0x01;
  int ymsb = ((y^sum) >> 31) & 0x01;
  return !(xmsb & ymsb);
}
/* 
 * abs - absolute value of x (except returns TMin for TMin)
 *   Example: abs(-1) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int abs(int x) {
  // msb is either 0 or 1. temp is x when x is positive or ~x when x is negative. Adding msb to temp, you get the abs of x. 
  int msb = (x >> 31) & 0x01;
  int temp = (x >> 31)^x;
  return temp + msb;
}
/* 
 * isNonZero - Check whether x is nonzero using
 *              the legal operators except !
 *   Examples: isNonZero(3) = 1, isNonZero(0) = 0
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4 
 */
int isNonZero(int x) {
  // when x is nonzero, -x^x and right shifting by 31 gives 0xffffffff. ANDing this value with 0x00000001 gives 1 which indicates that x is nonzero. In case of TMIN, -x^x and right shifting by 31 gives 0x00000000, but if I OR this value with its MSB, it gives 1 which indicates that it is not zero.
  int msb = (x >> 31) & 0x01;
  int temp = (((~x+1)^x) >> 31) & 0x01;
  return temp | msb;
}
