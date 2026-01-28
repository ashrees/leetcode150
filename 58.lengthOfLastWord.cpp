#include<iostream>

using namespace std;

int lengthOfLastWord(string s) {
    int sLen = s.size() - 1;
    int wLen{0};

    while(sLen >= 0 && s[sLen] == ' ') sLen--;

    while(sLen >= 0 && s[sLen] != ' ' ) {
        wLen++;
        sLen--;
    }

    return wLen;
}

int main() {
    string s = "   fly me   to   the moon  ";

    cout << "Last Word is " << lengthOfLastWord(s) << " in Length" << endl;
}