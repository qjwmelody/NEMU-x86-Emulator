/* 
 * CS:APP Data Lab 
 * 
 * 祁佳薇 16307130293
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

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
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
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
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

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
  /*运用德摩根定律：~(x&y)=(~x)|(~y)*/
  return ~((~x)|(~y));
}


/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
  /*求第n个字节
   *先右移n个字节即n*8位将低位移出
   *然后与0xff进行与运算，清除高位保留低位*/
  return x>>(n<<3)&0xff;
}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
  /*逻辑右移>>>与算数右移>>的区别是左边空位补上的数字
   *算数右移以后，高位补上的是符号位，正数为0，负数为1
   *而逻辑右移是高位一律补0，所以需要在进行算数右移运算后，
   *将结果与前n位为0，后32-n位为1的常数相与得到结果
   *该常数可以通过把10...0算数右移n-1位后取反得到
   *其中n=0时不可以直接右移n-1位，所以写成(y>>n)<<1
  */
  return (x>>n)&(~(((1<<31)>>n)<<1));
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
  /*用数00...0100...0100...0100...0100...01与x进行与运算
   *判断x的0，8，16，24位是否为1，结果s保存每4个字节上1的个数
   *将x逐位右移，可以检测到32位每一位
   *最终s每个字节德值保存对应x每个字节上1的个数
   *将s四个字节的值相加，得到x中1的个数，最低字节信息即为最后结果
   */
  int temp=0x1|0x1<<8|0x1<<16|0x1<<24;//temp=0x1111
  int s=temp&x;//检测0，8，16，24位是否是1
  s+=temp&(x>>1);//检测1，9，17，25位是否是1
  s+=temp&(x>>2);//检测2，10，18，26位是否是1
  s+=temp&(x>>3);//检测3，11，19，27位是否是1
  s+=temp&(x>>4);//检测4，12，20，28位是否是1
  s+=temp&(x>>5);//检测5，13，21，29位是否是1
  s+=temp&(x>>6);//检测6，14，22，30位是否是1
  s+=temp&(x>>7);//检测7，15，23，31位是否是1
  s+=(s>>16);//将s的高16位加到低16位上
  s+=(s>>8);//将s的高8位加到低8位上
  return s&0xff;//保留s的最低字节信息作为最终结果
}
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
  /*寻找0的特殊性：0及其补码德最高位都是0
   *其它数字原码和补码最高位一个是0一个是1
   *所以可以通过右移检验最后一位来检验x|(~x+1)最高位即可
   */
  return (~((x|(~x+1))>>31))&1;
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  /*返回补码编码的最小整数，即-2^31，0x80000000*/
  return 1<<31;
}
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
  /*如果x是负数能用n位表示，那么y=0
   *如果x是正数能用n位表示，那么y=0xffffffff
   *在这两种情况下，返回1，否则返回0
   */
  int y=x>>(n+(~1)+1);
  return !y^!(~y);
}
/* 
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
    /*如果是正数，直接右移n位
     *如果是负数，需要加上一个偏移量2^n-1
     *(当低位不全是0时，需要另加1以使得结果更偏向0)
     */
    int s=x>>31;
    int bias=s&((1<<n)+~0);
    return (x+bias)>>n;
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  /*返回相反数，就是求其补码（取反加1）*/
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
  /*正数条件是最高位为0，且值不为0
   *判断x值是否为0，取对应布尔值(!!x)即可
   */
  int s=x>>31;
  return !s&(!!x);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  /*符合条件的有两种情况：
   *1、x<0,y>=0,此时x符号位是1，y符号位是0
   *2、x,y符号位相同，并且x<=y,不会发生溢出，直接判断
   *x-y<=0,x-y-1<0,x+~y<0
   */
  int sx=x>>31;
  int sy=y>>31;
  int a=sx&(!sy);
  int b=(!(sx^sy))&((x+~y)>>31);
  return a|b;
}
/*
 * ilog2 - return floor(log base 2 of x), where x > 0
 *   Example: ilog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int ilog2(int x) {
  /*即求32位二进制数最高位1对应的2的指数
   *用二分法作分段移位查找
   */
  int s1,s2,s3,s4,s5;
  s1=(!!(x>>16))<<4;
  x=x>>s1;//如果高16位不是全0，说明含有2^16，右移16位
  
  s2=(!!(x>>8))<<3;
  x=x>>s2;//如果高8位不是全0，说明含有2^8，右移8位

  s3=(!!(x>>4))<<2;
  x=x>>s3;//如果高4位不是全0，说明含有2^4，右移4位

  s4=(!!(x>>2))<<1;
  x=x>>s4;//如果高2位不是全0，说明含有2^2，右移2位

  s5=!!(x>>1);
  return s1+s2+s3+s4+s5;
}
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
 /*返回一个单精度浮点数（1位符号位+8位阶码+23位尾数）的相反数
  *当x=NaN时，即阶码全为1，尾数不为0，返回NaN
  *当x!=NaN时，直接将符号位取反返回-x即可
  *其中判断是否为NaN可先与0x7fffffff，把符号位变为0，大于0x7f800000则是*/
 if((uf&0x7fffffff)>0x7f800000)
   return uf;
 return uf^0x80000000;
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
  /*将int型变量强制转换为单精度浮点型
   *需考虑符号、阶码、尾数三部分
   *其中处理精度部分，判断x&0xff，遵循四舍五入原则
   *超过2^7，直接进位,frac++
   *等于2^7，如果frac最后一位是0则不进位直接截断，否则产生进位
   */
  int s=x&(1<<31);//获取符号位
  int i;
  int exp;//指数域
  int frac=0;//尾数域
  int delta;//偏差
  int frac_mask=(1<<23)-1;//尾数域的掩码低23位全1，高9位全0
  if(x==0)//如果为0就直接返回
    return x;
  else if(x==(1<<31))//如果x为-2^31，对应浮点数就是1 1.0*2^31
    exp=158;//exp=31+127=158
  else{
    if(s)//获取绝对值
      x=-x;
    i=30;//次高位才是有效数字起始位
    while(!(x>>i))//从左往右查找第一个不为0的位
      i--;
    exp=i+127;//e=E+Bias
    x=x<<(31-i);//舍弃前面的0，得到有效数据开头的数据
    frac=frac_mask&(x>>8);//frac取尾数（x的高23位）
    x=x&0xff;//由于右移8位舍弃了低8位，现在获取以用于舍入操作
    delta=x>128||((x==128)&&(frac&1));//处理精度，四舍五入
    frac+=delta;//加上精度
    if(frac>>23){//若舍入后尾数>23位，只取23位，高位舍弃，阶码加1
      frac&=frac_mask;
      exp+=1;
    }
  }
  return s|(exp<<23)|frac;//整合最后结果
}
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
  /*如果uf&0x7f800000==0，说明uf的指数是0，uf是非规格化数/0
   *可以将uf的尾数左移一位实现乘2，通过与0x80000000来保持符号
   *而如果结果不为0，且阶码不是0xff，那么指数直接加1
   *如果阶码为0xff，说明是NaN,直接返回
   */  
  int temp=uf&0x7f800000;
  if(temp==0)
    return ((uf&0x007fffff)<<1|(uf&0x80000000));
  else if(temp!=0x7f800000)
    uf+=0x00800000;
    return uf;
}
