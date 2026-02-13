#include<iostream>
#include<vector>

using namespace std;

int lengthOfLongestSubstring(string s) {
    vector<bool> arr(128, false);
    int maxLen{0};
    int l{0};
    int r{0};

    while(r < s.size()) {
        if(!arr[s[r]]) {
            arr[s[r]] = true;
            maxLen = max(maxLen, r - l + 1);
            r++;
        } else {
            arr[s[l]] = false;
            l++;
        }
    }
    return maxLen;
}

int main() {
    string s{"abcabcbb"};

    cout << "Longest Substring length without repeating characters: \"" << lengthOfLongestSubstring(s) << "\"" << endl;
}