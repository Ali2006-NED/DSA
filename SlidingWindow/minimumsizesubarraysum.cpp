#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
        
        int left = 0;
        int right;
        int currentWindowSum = 0;
        int res = INT_MAX;

        for(right = 0; right < nums.size(); right++){
            currentWindowSum += nums[right];
            while(currentWindowSum >= target){
                res = min(res,right - left + 1);
                currentWindowSum-=nums[left];
                left++;
            }

        }

        return res == INT_MAX ? 0 : res;
    }

int main() {
    vector<int> nums = {2,3,1,2,4,3};
    int target = 7;
    cout<<minSubArrayLen(target,nums);
    return 0;
}
