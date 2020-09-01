/**
 * 给定一个包含 n 个整数的数组 nums 和一个目标值 target，
 * 判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？
 * 找出所有满足条件且不重复的四元组。
 */


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if(nums.size() < 4) return result;
        sort(nums.begin(), nums.end());
        
//        for(int i = 0; i < nums.size(); i++){
//            cout << nums[i] << "  ";
//        }
//        cout << endl;
//        
        for(int i = 0; i < nums.size() - 3; i++){
//            if(nums[i] > target) break;
            if(i != 0 && nums[i] == nums[i-1]) continue;
            for(int j = i+1; j < nums.size() - 2; j++){
                int sum = nums[i] + nums[j];
//                if(sum > target) break;
                if(j != i+1 && nums[j] == nums[j-1]) continue;
                int l = j + 1;
                int r = nums.size() - 1;
                while(l < r){      
                    int sum_back = sum + nums[l] + nums[r];
//                    printf("%d %d %d %d %d \n", nums[i], nums[j], nums[l], nums[r], sum_back);
                    if(sum_back == target){
                        vector<int> temp = {nums[i], nums[j], nums[l], nums[r]};
                        result.push_back(temp);
                        while(l < r &&  nums[l] == nums[l+1]) l++;
                        while(l < r && nums[r] == nums[r-1]) r--;
                        l++;
                        r--;
                    } else if(sum_back > target) r--;
                    else l++;
                }
            }
        }
//        for(int i = 0; i < result.size(); i++){
//            for(int j = 0; j < 4; j++){
//                printf("%d  ", result[i][j]);
//            }
//            cout << endl;
//        }
        return result;
    }
    
    void run()
    {
        Solution solution;
        vector<int> nums = {1,-2,-5,-4,-3,3,3,5};
        int target = -11;
        solution.fourSum(nums, target);
        return 0;
    }

};

