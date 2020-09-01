/**
 * 罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const vector<pair<int, string>> maps {
            {1000, "M"},
            {900, "CM"},
            {500, "D"},
            {400, "CD"},
            {100, "C"},
            {90, "XC"},
            {50, "L"},
            {40, "XL"},
            {10, "X"},
            {9, "IX"},
            {5, "V"},
            {4, "IV"},
            {1, "I"}
    };
    
    int romanToInt(string s) {
        int result = 0;
        int count = 0;
        for(int i = 0; i < maps.size() && count < s.length(); i++){
            if(count <= s.length() && s.substr(count, 2) == maps[i].second){
                result += maps[i].first;
                count += 2;
                continue;
            }
            
            while(count < s.length() && s.substr(count, 1) == maps[i].second){
                result += maps[i].first;
                count++;
            }
        }
        return result;
    }
    
    void run()
    {
        Solution solution;
        cout << solution.romanToInt("LVIII");
        return 0;
    }
};


