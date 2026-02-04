#include<iostream>
#include<vector>

using namespace std;

vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> result;
        int n = words.size();
        int i{0};

        while (i < n) {
            int lLength = words[i].size();
            int j = i + 1;

            while (j < n && lLength + 1 + words[j].size() <= maxWidth) {
                lLength += 1 + words[j].size();
                j++;
            }

        string line;
        int nWords = j - i;
        int totalSpaces = maxWidth - (lLength - (nWords - 1));

        if (j == n || nWords == 1) {
            line += words[i];

            for (int k = i + 1; k < j; k++) {
                line += " " + words[k];
            }

            line += string(maxWidth - line.size(), ' ');
        } else {
            int space = totalSpaces / (nWords - 1);
            int extra = totalSpaces % (nWords - 1);

            for (int k = i; k < j - 1; k++) {
                line += words[k];
                line += string(space + (k - i < extra ? 1 : 0), ' ');
            }

            line += words[j - 1];
        }

        result.push_back(line);
        i = j;
        }

    return result;
}

int main() {
    vector<string> words{"This", "is", "an", "example", "of", "text", "justification."};
    int maxWidth = 16;

    vector<string> justifiedText = fullJustify(words, maxWidth);

    for (const string& line : justifiedText) {
        cout << "\"" << line << "\"" << endl;
    }

    return 0;
}