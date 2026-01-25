#include<iostream>
#include<vector>

using namespace std;

int trap(vector<int>& height) {
    int left{0}, right = height.size() - 1;
    int leftMax{0}, rightMax{0};
    int waterUnits{0};

    while(left < right) {
        if(height[left] < height[right]) {
            leftMax = max(leftMax, height[left]);
            waterUnits += leftMax - height[left];
            left++;
        } else {
            rightMax = max(rightMax, height[right]);
            waterUnits += rightMax - height[right];
            right--;
        }
    }

    return waterUnits;
}

int main() {
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};

    cout << "Total units of Water can be stored: " << trap(height) << endl;
}