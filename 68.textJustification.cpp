#include<iostream>
#include<vector>
#include<string>

using namespace std;

/**
 * LeetCode Problem #68: Text Justification
 * 
 * Given an array of strings words and a width maxWidth, format the text such that
 * each line has exactly maxWidth characters and is fully (left and right) justified.
 * 
 * @param words - Vector of strings representing the words to justify
 * @param maxWidth - Maximum width of each line
 * @return Vector of strings representing the justified text lines
 */
vector<string> justifyText(vector<string> words, int maxWidth) {
    vector<string> result;
    
    // TODO: Implement text justification logic here
    
    return result;
}

int main() {
    // Example 1: Basic text justification
    vector<string> words1 = {"This", "is", "an", "example", "of", "text", "justification."};
    int maxWidth1 = 16;
    
    cout << "Example 1:" << endl;
    cout << "Input words: ";
    for(const auto& word : words1) {
        cout << "\"" << word << "\" ";
    }
    cout << endl;
    cout << "Max width: " << maxWidth1 << endl;
    cout << "Output:" << endl;
    
    vector<string> result1 = justifyText(words1, maxWidth1);
    for(const auto& line : result1) {
        cout << "\"" << line << "\"" << endl;
    }
    
    cout << endl;
    
    // Example 2: Another test case
    vector<string> words2 = {"What", "must", "be", "acknowledgment", "shall", "be"};
    int maxWidth2 = 16;
    
    cout << "Example 2:" << endl;
    cout << "Input words: ";
    for(const auto& word : words2) {
        cout << "\"" << word << "\" ";
    }
    cout << endl;
    cout << "Max width: " << maxWidth2 << endl;
    cout << "Output:" << endl;
    
    vector<string> result2 = justifyText(words2, maxWidth2);
    for(const auto& line : result2) {
        cout << "\"" << line << "\"" << endl;
    }
    
    return 0;
}
