#include<iostream>
#include<vector>

using namespace std;

bool canJump(vector<int>& nums) {
    int maxJump{0};

    for(int i = 0; i < nums.size(); i++) {
        if(i > maxJump) {
            return false;
        }

      maxJump = max(maxJump, i + nums[i]);
    }

    return true;
}

int main() {
    vector<int> nums = { 3, 2, 1, 0, 4};
    // vector<int> nums = { 2, 3, 1, 1, 4};

    if(canJump(nums)) {
        cout << "Yes, can jump to last index." << endl;
    } else {
        cout << "No, cannot get to last index." << endl;
    } 
}