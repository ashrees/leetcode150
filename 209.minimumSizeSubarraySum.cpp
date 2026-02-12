#include<iostream>
#include<vector>
#include<limits>

using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
    int minLen = numeric_limits<int>::max();
    int left{0};
    int curSum{};

    for(int right = 0;right < nums.size(); right++) {
        curSum += nums[right];
        while(curSum >= target) {
            if(right < left + 1 < minLen) {
                minLen = right - left + 1;
                }
            curSum -= nums[left];
            left++;
        }
    }

    return minLen != numeric_limits<int>::max() ? minLen : 0;
}

int main() {
    int target{7};
    vector<int> nums = {2 ,3 ,1 ,2 ,4 ,3};

    cout << "\"" << minSubArrayLen(target, nums) << "\" is the minimal length of a subarray whose sum is greater than or equal to target \"" << target << "\"" << endl;
}