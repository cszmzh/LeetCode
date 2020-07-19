#include <iostream>
#include <vector>
#include <map>
using namespace std;

/**
 * LeetCode
 * 1.两数之和
 * https://leetcode-cn.com/u/banana798/
 */

class Solution {
public:
    //暴力遍历法 时间复杂度o(n²)
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        for(int i=0; i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j]==target){
                    ans.push_back(i);
                    ans.push_back(j);
                }
            }
        }
        return ans;
    }

    //哈希法 时间复杂度o(n)
    vector<int> twoSum_hash(vector<int>& nums, int target) {
        vector<int> ans;
        map<int,int>hashmap;
        for(int i=0;i<nums.size();i++){
            int tag = target - nums[i];
            if(hashmap[tag]){
                ans.push_back(hashmap[tag]-1);
                ans.push_back(i);
                return ans;
            }
            //防止处理value为0的情况，因为查询key是否存在时对应value会初始化为0
            hashmap[nums[i]]=i+1;
        }
    }

};


int main() {
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(11);
    nums.push_back(15);
    Solution solution;
    vector<int> ans = solution.twoSum_hash(nums, 9);
    cout<<ans[0]<<" "<<ans[1];
}
