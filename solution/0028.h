//实现 strStr() 函数。
//给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。
//
//示例 1:
//输入: haystack = "hello", needle = "ll"
//输出: 2
//
//示例 2:
//输入: haystack = "aaaaa", needle = "bba"
//输出: -1

#ifdef t0028

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle == "") return 0;
        if(haystack == "") return -1;
        if(needle.length() > haystack.length()) return -1;
        
        int j = 0;
        for(int i = 0; i < haystack.length() - needle.length() + 1; i++){
            if(haystack.substr(i, needle.length()) == needle){
                return i;
            }
        }
        return -1;
            
    }
    
    void run(){
        cout << solution.strStr("he4ll", "ll"); 
    }
};

#endif