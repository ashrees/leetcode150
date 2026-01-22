#include<iostream>
#include<vector>

using namespace std;

vector<int> productExpectSelf(vector<int>& nums) {
    vector<int> answer(nums.size(), 1);

    int left{1};
    for(int i = 0; i < nums.size(); i++) {
        answer[i] *= left;
        left *= nums[i];
    }

    int right{1};
    for(int i = nums.size() - 1; i >= 0; i--) {
        answer[i] *= right;
        right *= nums[i];
    }

    return answer;
}

int main() {
    vector<int> nums = {1, 2, 3, 4};

    cout << "Product of array except self: ";

    for(auto v : productExpectSelf(nums)) {
        cout << v << " ";
    }
}