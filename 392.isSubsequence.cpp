#include<iostream>

using namespace std;

bool isSubsequence(string s, string t) {
    int sp{0};
    int tp{0};

    while(sp < s.length() && tp < t.length()) {
        if(s[sp] == t[tp]) {
            sp++;
        }
        tp++;
    }

    return sp == s.length();
}

int main() {
    string s{"abc"};
    string t{"arbdgcd"};

    if(isSubsequence(s, t)) {
        cout << "\"" << t << "\"" << " is subsequence of \"" << s << "\"" << endl; 
    } else {
        cout << "\"" << t << "\"" << " is not a subsequence of \"" << s << "\"" << endl; 
    }
}