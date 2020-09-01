/**
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 * 如果不存在公共前缀，返回空字符串 ""。
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) {
            return "";
        }
        if(strs.size() == 1){
            return strs[0];
        }
        int maxprefix = 0;
        while(true){
            for(int i = 0; i < strs.size()-1; i++){
                if(strs[i].length() <= maxprefix || strs[i+1].length() <= maxprefix){
                    return strs[i].substr(0, maxprefix);
                }
                if(strs[i][maxprefix] != strs[i+1][maxprefix]){
                    return strs[i].substr(0, maxprefix);
                }
            }
            maxprefix++;
        }
    }
    
    void run()
    {
        vector<string> strs = {};
        Solution solution;
        cout << solution.longestCommonPrefix(strs);
        return 0;
    }
};


