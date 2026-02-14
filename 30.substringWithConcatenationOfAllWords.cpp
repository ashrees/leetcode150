#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> indexes;

    if(s.empty() || words.empty()) return {};

    unordered_map<string, int> counts;
    for(string word : words) counts[word]++;
    int n = s.length(), num = words.size();
    int len = words[0].length();

    for(int start = 0; start < len; start++) {
        unordered_map<string, int> seen;
        int left = start, matched{0};

        for(int right = start; right + len <= n; right += len) {
            string word = s.substr(right, len);

            if(counts.count(word)) {
                seen[word]++;
                matched++;

                while(seen[word] > counts[word]) {
                    string leftWord = s.substr(left, len);
                    seen[leftWord]--;
                    left += len;
                    matched--;
                }

                if(matched == num) indexes.push_back(left);
            } else {
                seen.clear();
                matched = 0;
                left = right + len;
            }
        }
    }
    return indexes;
}

int main() {
    string s{"barfoofoobarthefoobarman"};
    vector<string> words = {"bar","foo","the"};

    cout << "The indexes are: ";

    for(int i : findSubstring(s, words)) {
        cout << i << " ";
    }
}