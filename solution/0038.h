/*给定一个正整数 n（1 ≤ n ≤ 30），输出外观数列的第 n 项。
注意：整数序列中的每一项将表示为一个字符串。

「外观数列」是一个整数序列，从数字 1 开始，序列中的每一项都是对前一项的描述。前五项如下：

1.     1
2.     11
3.     21
4.     1211
5.     111221
6.     312211
7.     13112221
8.     1113213211
第一项是数字 1
描述前一项，这个数是 1 即 “一个 1 ”，记作 11
描述前一项，这个数是 11 即 “两个 1 ” ，记作 21
描述前一项，这个数是 21 即 “一个 2 一个 1 ” ，记作 1211
描述前一项，这个数是 1211 即 “一个 1 一个 2 两个 1 ” ，记作 111221*/

#ifndef t0038
#define t0038

#include <sstream>

class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        
        string current_line = "11";
        stringstream stream;
        for(int i = 2; i < n; i++){
            int length = current_line.length();
            int count = 1;
            int k = 1;
            while(k < length){
                while(k < length && current_line[k-1] == current_line[k]){
                    count++;
                    k++;
                }
                stream << count;
                stream << current_line[k-1];
                k++; count = 1;
            }
            if(current_line[length-1] != current_line[length-2]) {
                stream << count;
                stream << current_line[k-1];
            }
            current_line = stream.str();
//            cout << current_line << endl;
            stream.str("");
        }
        return current_line;
    }
    
    void run(){
        cout << countAndSay(6);
    }
};


#endif
