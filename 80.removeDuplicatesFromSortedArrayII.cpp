#include<iostream>
#include<vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    int k{2};

    for(int i = 2; i < nums.size(); i++){
        if(nums[i] != nums[k - 2]){
            nums[k] = nums[i];
            k++;
        }
    }
    return k;
}

int main() {
     vector<int> nums = { 0, 0, 1, 1, 1, 1, 2, 3, 3};

     cout << "Remaining unique duo of elements: " << removeDuplicates(nums) << endl;
}