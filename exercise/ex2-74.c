/*
 * 练习题 2.74
 *
 * 写出具有如下原型的函数的代码：
 *
 * // Determine whether subtracting arguments will cause overflow
 * int tsub_ovf(int x, int y);
 *
 * 如果计算 x-y 导致溢出，这个函数就返回 1。
 *
 */

#include <limits.h>             /* INT_MIN */

/* Determine whether subtracting arguments will cause overflow */
int tsub_ovf(int x, int y)
{
        int r = x - y;
        int pos_overflow = !(x & INT_MIN) &&  (y & INT_MIN) &&  (r & INT_MIN);
        /* Have you ever thought of the case of "0 - INT_MIN" ? -INT_MIN equals to -INT_MIN，it does not overflow, but it correspond to "pos_overflow" in your code, how to deal with this? */
        
        int neg_overflow =  (x & INT_MIN) && !(y & INT_MIN) && !(r & INT_MIN);

        return pos_overflow || neg_overflow;
}
