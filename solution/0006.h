/**
 * @brief 将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。
 * @param argc
 * @param argv
 * @return 
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * @brief 参考了网上代码
     * @param s
     * @param numRows
     * @return 
     */
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        string metric[numRows];
        int direct = -1;
        int i = 0;
        for(auto c : s){
            metric[i] += c;
            if(i == 0 || i == numRows -1) direct = - direct;
            i += direct;
        }
        string result;
        for(int i = 0; i < numRows; i++){
            result += metric[i];            
        }
        cout << result;       
        return result;
    }
    

    /**
     * @brief 复杂的,自己写的
     * @param s
     * @param numRows
     * @return 
     */
    string convert_back(string s, int numRows) {
        if(numRows == 1) return s;
        char metric [numRows][s.length()+1];
        memset(metric, 0, sizeof(metric));
        int direct = 0;
        int p = 0, q = 0;
        for(int i = 0; i < s.length(); i++){            
            metric[p][q] = s[i];
            if(direct == 0) {
                p++;
                if(p >= numRows) {
                    direct = 1;
                    p -= 2;
                    q++;
                }
            } else{
                p--; q++;
                if(p < 0){
                    direct = 0;
                    q--;
                    p += 2;
                }
            }
            
            for(int i = 0; i < numRows; i++){
                for(int j = 0; j < s.length(); j++){
                    if(metric[i][j] < 30){
                        printf("   ");
                    }else
                        printf("%c  ", metric[i][j]);
                }
                cout << endl;
            }
            cout << endl;
        }
        string result = "";
        for(int i = 0; i < numRows; i++){
            for(int j = 0; j < s.length()+1; j++){
                if(metric[i][j] < 30) continue;
                result += metric[i][j];
            }
        }
        return result;
    }
    
    void run()
    {
        Solution solution;
        string s = "LEETCODEISHIRING";
    //    string s = "AB";
        solution.convert(s, 4);
        return 0;
    }
};

