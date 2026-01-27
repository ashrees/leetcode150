#include<iostream>

using namespace std;

int charToNum(char a) {
    switch(a) {
        case 'I' : return 1;
        case 'V' : return 5;
        case 'X' : return 10;
        case 'L' : return 50;
        case 'C' : return 100;
        case 'D' : return 500;
        case 'M' : return 1000;
        default : return 0;
    }
}

int romanToInt(string s) {
    int inNum{0};

    for(int i = 0; i < s.length(); i++) {
       if(i + 1 < s.length() && charToNum(s[i]) < charToNum(s[i + 1])) {
        inNum -= charToNum(s[i]);
       } else {
        inNum += charToNum(s[i]);
       }
    }

    return inNum;
}

int main() {
    string s = "MCMXCIV";

    cout << "'" << s << "'" << " To Int: " << romanToInt(s) << endl;
}