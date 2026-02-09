#include<iostream>
#include<vector>

using namespace std;

int maxArea(vector<int>& height) {
    int maxArea{0};
    int left{0};
    int right = height.size() - 1;

    while(left < right) {
        maxArea = max(maxArea, (right - left) * min(height[left], height[right]));
        
        if(height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return maxArea;
}

int main() {
    vector<int> height = {1 ,8 ,6 ,2 ,5 ,4 ,8 ,3 ,7};
    cout << "The maximum amount of water a container can store is: " << maxArea(height) << endl;
}