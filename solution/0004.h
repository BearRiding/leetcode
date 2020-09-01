/**
 * @class Solution
 * @author bearking
 * @date 05/11/2019
 * @file main.cpp
 * @brief 给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。
        请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
 */

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int count = 0;
        int i = 0, j = 0;
        int total = nums1.size() + nums2.size();
        int flag = total % 2 == 0 ? 0 : 1;
        int resultpos = 0, resultside = 0;
        int resultpos2 = 0, resultside2 = 0;
        
        while(count <= total / 2 + flag){
            if(count == total / 2 + flag){
                resultpos2 = resultpos;
                resultside = resultside;
            }
            if(i < nums1.size() && j < nums2.size()){
                if(nums1[i] < nums2[j]){
                    resultpos = nums1[i];
                    resultside = 1;
                    i++;
                } else{
                    resultpos = nums2[j];
                    resultside = 2;
                    j++;
                }
            } else if( j < nums2.size()){
                resultpos = nums2[j];
                resultside = 2;
                j++;
            } else if(i < nums1.size()) {
                resultpos = nums1[i];
                resultside = 1;
                i++;
            }
            count++;
        }
        if(flag) {
            return resultpos2;
        } else{
            return ((double)resultpos + resultpos2) / 2;
        }
    }
    
    vector<int> init(){
        int max = (rand() % 4) + 3;
        vector<int> vec;
        for(int i = 0; i < max; i++){
            vec.push_back(rand()%30);
        }
        return vec;
    }

    void print(vector<int> vec){
        for(int i = 0; i < vec.size(); i++){
            cout << vec[i] << "  ";
        }
        cout << endl;
    }

    void run()
    {
        srand(time(0));
        Solution solution;
        vector<int> vec1 = {1,2};
        vector<int> vec2 = {3,4};
        sort(vec1.begin(), vec1.end());
        sort(vec2.begin(), vec2.end());
        print(vec1);
        print(vec2);

        cout << solution.findMedianSortedArrays(vec1, vec2);
        return 0;
    }
};


