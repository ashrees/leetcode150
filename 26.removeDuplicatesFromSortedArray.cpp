#include<iostream>
#include<vector>

using namespace std;

int removeDuplicate(vector<int>& nums) {
    int k{1};

    for(int i = 1; i < nums.size();i++ ) {
        if(nums[i] != nums[i - 1]) {
            nums[k++] = nums[i];
        }
    }
    return k;
}

int main() { 
    vector<int> nums = {1, 1, 2, 3, 4, 4};

    cout << "unique remaining elements: " << removeDuplicate(nums) << endl;
}