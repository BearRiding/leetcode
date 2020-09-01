/**
 * @brief 给定一个整数，将其转为罗马数字。输入确保在 1 到 3999 的范围内。

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
    
    string intToRoman(int num) {
        string result = "";        
        for(int i = 0; i < maps.size() && num > 0; i++){
            cout << maps[i].first << " " << maps[i].second << endl;
            int temp = num / maps[i].first;
            num %= maps[i].first;
            for(int j = 0; j < temp; j++){
                result += maps[i].second;
            }
        }

        return result;
    }

    string intToRoman_back(int num) {
        unordered_map<int, string> ops;
        init(ops);
        string result = "";
        int count = 1000;
        while(num){
            int temp = num / count;
            if(temp == 0){
                count /= 10;
                continue;
            }
            if(temp == 9){
                result += ops[temp * count];
            }
            else if(temp > 5){
                result += ops[5 * count];
                temp -= 5;
                while(temp){
                    result += ops[count]; 
                    temp--;
                }
            }
            else if(temp == 5){
                result += ops[temp * count];
            }
            else if(temp == 4){
                result += ops[temp * count];
            }
            else if(temp > 0){
                while(temp){
                    result += ops[count]; 
                    temp--;
                }
            }
            num %= count;
            count /= 10;
        }
        return result;
        
    }
    void init(unordered_map<int, string> &ops){
        ops[1] = "I";
        ops[4] = "IV";
        ops[5] = "V";
        ops[9] = "IX";
        ops[10] = "X";
        ops[40] = "XL";
        ops[50] = "L";
        ops[90] = "XC";
        ops[100] = "C";
        ops[400] = "CD";
        ops[500] = "D";
        ops[900] = "CM";
        ops[1000] = "M";
    }
    
    void run()
    {
        Solution solution;
        cout << solution.intToRoman(58);
        return 0;
    }
};


