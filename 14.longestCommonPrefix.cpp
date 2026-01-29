#include<iostream>
#include<vector>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if(strs.empty()) return "";
    
    string prefix{strs[0]};
    int n = strs.size();

    for(int i = 0; i < prefix.size(); i++) {
        char c = prefix[i];

        for(int j = 1; j < n; j++) {
            if(i >= strs[j].size() || strs[j][i] != c) {
                return prefix.substr(0, i);
            }
        }
    }

    return prefix;
} 

int main() {
    vector<string> strs = {"flower", "flow", "flight"};

    cout << "Common prefix: " << longestCommonPrefix(strs) << endl;
}