#include<iostream>
#include<vector>

using namespace std;

string intToRoman(int num) {
    const vector<pair<int, string>> valueRoman{
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"} 
    };

    string result;

    for(const auto& [val, roman] : valueRoman) {
        if(num == 0) {
            break;
        }

        while( num >= val) {
            result += roman;
            num -= val;
        }
    }

    return result;
}

int main() {
    int num{3843};

    cout << num << " in converted to roman: " << intToRoman(num) << endl;
}