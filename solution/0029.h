//给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。
//返回被除数 dividend 除以除数 divisor 得到的商。
//
//示例 1:
//输入: dividend = 10, divisor = 3
//输出: 3
//
//示例 2:
//输入: dividend = 7, divisor = -3
//输出: -2
//说明:
//
//被除数和除数均为 32 位有符号整数。
//除数不为 0。
//假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−231,  231 − 1]。本题中，如果除法结果溢出，则返回 231 − 1。

#ifdef t0029

#include <bits/stdc++.h>
#define long long long 
using namespace std;


class Solution {
public:
    void print(string name, long num){
        bitset<64> temp(num);
        cout << temp << "  " << name << endl;
    }
    int divide(int dividend, int divisor) {
        if(divisor == 0) return INT_MAX;
        if(dividend == 0) return 0;
        
        long lresult = 0;
        long ldividend = abs((long)dividend);
        long ldivisor = abs((long)divisor);
        long left = 0;
        
        int cnt = 0;
        
        while(!(ldividend & 0x0000000080000000)){
            ldividend = ldividend << 1;
            cnt++;
        }
//        print("ldividend", ldividend);
        cnt = 32 - cnt;
        
        while(cnt--){
            ldividend = ldividend << 1;
//            print("ldividend", ldividend); 
            left = (left << 1) | ((ldividend >> 32) & 0000000000000001);
//            print("left", left);
            if(left >= ldivisor) {
                left = left - ldivisor;
                lresult += 1;
            }
//            print("leftafter", left);
            lresult = lresult << 1;    
//            print("lresult", lresult);      
            
        }      
        lresult = lresult >> 1;
        lresult *= (dividend > 0 ? 1 : -1 ) * (divisor > 0 ? 1 : -1 );
        if(lresult > INT_MAX || lresult < INT_MIN) return INT_MAX;
        else return lresult;
    }
    
    void run(){
        cout << solution.divide(-2147483648,-1);
    }
};

#endif