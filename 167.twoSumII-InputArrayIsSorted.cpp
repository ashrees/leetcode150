#include<iostream>
#include<vector>

using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    int i{0};
    int j = numbers.size() - 1;

    while(i < j) {
        int sum = numbers[i] + numbers[j];
        if(sum == target) {
            return {i + 1, j + 1};
        } else if(sum < target) {
            i++;
        } else {
            j--;
        }
    }

    return {};
}

int main() {
    vector<int> numbers = {-10 ,-8 ,-2 ,1 ,2 ,5 ,6};
    int target{0};
    
    cout << "Indices are: ";
    
    for(int idx : twoSum(numbers, target)) {
        cout << idx << " ";
    }
}