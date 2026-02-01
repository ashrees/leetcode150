#include<iostream>
#include<vector>

using namespace std;

string convert(string s, int numRows) {
    if(numRows == 1 || numRows >= s.length()){
        return s;
    }

    int index{0};
    int direction{1};

    vector<vector<char>> rows(numRows);

    for(char c : s) {
        rows[index].push_back(c);
        if(index == 0) {
            direction = 1;
        } else if(index == numRows - 1) {
            direction= -1;
        }
        index += direction;
    }

    string result;
    for(const auto& row : rows) {
        for(char c : row) {
            result += c;
        }
    }
    return result;
}

int main() {
    string s = "PAYPALISHIRING";
    int numRows = 3;
    cout << "zigzag: " << convert(s, numRows) << endl;
}