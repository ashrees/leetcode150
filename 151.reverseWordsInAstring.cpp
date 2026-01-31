#include<iostream>
#include<algorithm>

using namespace std;

string reverseWords(string s) {
    reverse(s.begin(), s.end());

    string result;
    string word;

    for(char c : s) {
        if(c == ' ') {
            if(!word.empty()) {
                reverse(word.begin(), word.end());
                result += word + " ";
                word.clear();
            } 
        } else {
                word += c;
            }
    }

    if(!word.empty()) {
        reverse(word.begin(), word.end());
        result += word;
        word.clear();
    }


    if(!result.empty() && result.back() == ' ') {
        result.pop_back();
    }

    return result;
}

int main() {
    string s{"the sky is blue "};

    cout << "reversed:" << "\"" <<reverseWords(s) << "\"" << endl;
}