/* 
 * 两数之和
 * 思路，使用map
 */ 

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution { 
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mymap;
        for(int i = 0; i < nums.size(); i++){            
            if(mymap.find(target - nums[i]) != mymap.end()){
                vector<int> result;
                result.push_back(mymap.at(target - nums[i]));
                result.push_back(i);
                return result;
            }
            mymap[nums[i]] = i;;
        }
        return nums;
    }
    
    void run()
    {
        vector<int> nums;
        int target = 6;
    //    for(int i = 0; i < 10; i++){
    //        nums.push_back(rand()%15);
    //    }
        nums.push_back(3);
        nums.push_back(2);
        nums.push_back(4);

        Solution solution;
        vector<int> result = solution.twoSum(nums, target);  
        for(int i = 0; i < result.size(); i++){
            cout << result[i] << "\t";
        }
        return 0;
    }
};

