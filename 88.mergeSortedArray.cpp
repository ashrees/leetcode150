#include<iostream>
#include<vector>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i{m - 1};
    int j{n - 1};
    int k{m + n - 1 };

    while( j >= 0) {
        if( i >= 0 && nums1[i] > nums2[j]) {
            nums1[k--] = nums1[i--];
        } else {
            nums1[k--] = nums2[j--];
        }
    }
}

int main() {
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 8};

    cout << "Before merge\n";
    cout << "nums1: ";
    for(auto v : nums1) {
        cout << v << ", "; 
    }

    cout<<endl;

    cout << "nums2: "; 
    for(auto v : nums2) {
        cout << v << ", "; 
    }

    cout<<endl;

    merge(nums1, 3, nums2, 3);

    cout << "After Merge\n";

    cout << "nums1: ";
    for(auto v : nums1) {
        cout << v << ", "; 
    } 
}