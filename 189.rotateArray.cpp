#include<iostream>
#include<vector>

using namespace std;

void rotateArray(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;
    vector<int> rotated(n);

    for(int i = 0; i < n; i++) {
        rotated[(i + k) % n] = nums[i];
    }

    cout << "Before Rotation: ";
    for(int v : nums) {
        cout << v << " ";
    }

    cout<<endl;

    for(int i = 0; i < n; i++) {
        nums[i] = rotated[i];
    }

    cout << "Rotated Array: ";
    for(int v : nums) {
        cout << v << " ";
    }
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int rotate{3}; 
    rotateArray(nums, rotate);
}