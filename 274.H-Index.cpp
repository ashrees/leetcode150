#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(), citations.end());

        for (int i = 0; i < n; i++) {
            if (citations[i] >= n - i) {
                return n - i;
            }
        }

        return 0;
    }

int main() {
    vector<int> citations = {3,0,6,1,5};
    
    cout << "h-index is: " << hIndex(citations) << endl;
}