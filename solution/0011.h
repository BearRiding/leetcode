/**
 * 给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。
 * 在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。
 * 找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
 * 说明：你不能倾斜容器，且 n 的值至少为 2。
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int max = 0;
        
        while(i < j){
            int temp = min(height[i], height[j])*(j - i);
            if(temp > max) max = temp;
            if(height[i] > height[j]) {
                j--;
            } else{
                i++;
            }
        }
        return max;
    }

    int maxArea_back(vector<int>& height) {
        int maxCount = 0;
        for(int i = 0; i < height.size()-1; i++){
            for(int j = i; j < height.size(); j++){
                int temp = min(height[i], height[j])*(j - i);
                if(temp > maxCount){
                    maxCount = temp;
                }
            }
        }
        return maxCount;
    }
    
    void run()
    {
        vector<int> temp = {1,2,4,3};
        Solution solution;
        cout << solution.maxArea(temp);
        return 0;
    }
};


