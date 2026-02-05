#include<iostream>

using namespace std;

bool isPalindrome(string s) {
        int start{0};
        int end = s.size() - 1;
        while(start<=end) {
            if(!isalnum(s[start])){start++; continue;}
            if(!isalnum(s[end])){end--; continue;}
            if(tolower(s[start])!=tolower(s[end])) return false;
            else{
                start++;
                end--;
            }
    }
    return true;

}

int main() {
    string s = "A man, a plan, a canal: Panama";
    if(isPalindrome(s)) {
        cout << "The string is a valid palindrome." << endl;
    } else {
        cout << "The string is not a valid palindrome." << endl;
    }
}