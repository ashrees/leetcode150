/*
 * LeetCode Problem 68: Text Justification
 * 
 * Problem Description:
 * Given an array of strings 'words' and a width 'maxWidth', format the text such that
 * each line has exactly 'maxWidth' characters and is fully (left and right) justified.
 * 
 * Rules:
 * 1. Pack as many words as possible in each line
 * 2. Pad extra spaces when necessary so that each line has exactly maxWidth characters
 * 3. Extra spaces should be distributed as evenly as possible between words
 * 4. If spaces cannot be divided evenly, left slots get more spaces than right slots
 * 5. The last line should be left-justified with no extra space between words
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
 * Function: fullJustify
 * Formats text to be fully justified with specified width
 * 
 * Parameters:
 *   words - vector of strings containing the words to justify
 *   maxWidth - maximum width of each line
 * 
 * Returns:
 *   vector<string> - fully justified text lines
 * 
 * Algorithm:
 *   1. Group words into lines (fit as many words as possible per line)
 *      - Start with the first word
 *      - Keep adding words while they fit (considering at least 1 space between words)
 *      - Stop when the next word would exceed maxWidth
 * 
 *   2. For each line (except last):
 *      - Calculate total spaces needed to fill the line to maxWidth
 *      - Distribute spaces evenly between words
 *      - If spaces cannot be divided evenly, add extra spaces to left slots
 *      - Formula: spacesPerSlot = totalSpaces / (numWords - 1)
 *      - Extra spaces: totalSpaces % (numWords - 1) go to leftmost gaps
 * 
 *   3. For last line:
 *      - Left justify (single space between words)
 *      - Pad remaining spaces at the end to reach maxWidth
 * 
 *   4. Edge cases to handle:
 *      - Single word in a line (treat as left-justified)
 *      - Last line always left-justified regardless of word count
 */
vector<string> fullJustify(vector<string>& words, int maxWidth) {
    // Function skeleton with documentation - implementation to be added
    // Follow the algorithm steps documented above
}

int main() {
    // Test case 1: Multiple words with varying lengths
    vector<string> words1 = {"This", "is", "an", "example", "of", "text", "justification."};
    int maxWidth1 = 16;
    
    cout << "Test Case 1:" << endl;
    vector<string> result1 = fullJustify(words1, maxWidth1);
    for(const string& line : result1) {
        cout << "\"" << line << "\"" << endl;
    }
    
    return 0;
}
