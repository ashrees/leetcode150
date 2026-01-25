#include<iostream>
#include<vector>

using namespace std;

int candy(vector<int>& ratings) {
    int n = ratings.size(); 
    vector<int> candies(n, 1);

    for(int i = 1; i < n; ++i) {
        if(ratings[i] > ratings[i - 1]) {
            candies[i] = candies[i - 1] + 1;
        }
    }

    for(int i = n - 2; i >= 0; --i) {
        if(ratings[i] > ratings[i + 1]) {
            candies[i] = max(candies[i], candies[i + 1] + 1);
        }
    }

    int totalCandies;

    for(int candy : candies) {
        totalCandies += candy;
    }

    return totalCandies;
}

int main() {
    vector<int> ratings = {1, 3, 2, 2, 1};

    cout << "Total candies needed: " << candy(ratings) << endl;
}