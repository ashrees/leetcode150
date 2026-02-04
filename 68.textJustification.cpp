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
 *   2. For each line (except last):
 *      - Calculate total spaces needed
 *      - Distribute spaces evenly between words
 *      - Add extra spaces to left slots if uneven distribution
 *   3. For last line:
 *      - Left justify (single space between words)
 *      - Pad remaining spaces at the end
 */
vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> result;
    int n = words.size();
    int i = 0;
    
    // Process each line
    while(i < n) {
        // Step 1: Determine which words fit in the current line
        int lineLength = words[i].size();  // Length of first word
        int j = i + 1;  // Index of next word to consider
        
        // Keep adding words while they fit (accounting for at least 1 space between words)
        while(j < n && lineLength + 1 + words[j].size() <= maxWidth) {
            lineLength += 1 + words[j].size();  // Add space + word length
            j++;
        }
        
        // Step 2: Build the justified line
        int numWords = j - i;  // Number of words in current line
        
        string line = "";
        
        // Check if this is the last line or line has only one word
        if(j == n || numWords == 1) {
            // Last line or single word: left justify
            for(int k = i; k < j; k++) {
                line += words[k];
                if(k < j - 1) line += " ";  // Single space between words
            }
            // Pad remaining spaces at the end
            int paddingNeeded = maxWidth - line.size();
            for(int p = 0; p < paddingNeeded; p++) {
                line += " ";
            }
        } else {
            // Middle lines: fully justify
            int totalSpaces = maxWidth - lineLength + (numWords - 1);  // Total spaces to distribute
            int spaceSlots = numWords - 1;  // Number of gaps between words
            int spacesPerSlot = totalSpaces / spaceSlots;  // Base spaces per gap
            int extraSpaces = totalSpaces % spaceSlots;  // Extra spaces for left slots
            
            // Build the line with distributed spaces
            for(int k = i; k < j; k++) {
                line += words[k];
                if(k < j - 1) {
                    // Add base spaces
                    for(int s = 0; s < spacesPerSlot; s++) {
                        line += " ";
                    }
                    // Add extra space to left slots
                    if(extraSpaces > 0) {
                        line += " ";
                        extraSpaces--;
                    }
                }
            }
        }
        
        result.push_back(line);
        i = j;  // Move to next set of words
    }
    
    return result;
}

/*
 * Main function: Test the text justification implementation
 * Demonstrates the algorithm with sample inputs
 */
int main() {
    // Test case 1: Multiple words with varying lengths
    vector<string> words1 = {"This", "is", "an", "example", "of", "text", "justification."};
    int maxWidth1 = 16;
    
    cout << "Test Case 1:" << endl;
    cout << "Words: ";
    for(const string& word : words1) {
        cout << word << " ";
    }
    cout << endl;
    cout << "Max Width: " << maxWidth1 << endl;
    cout << "Justified Text:" << endl;
    
    vector<string> result1 = fullJustify(words1, maxWidth1);
    for(const string& line : result1) {
        cout << "\"" << line << "\"" << endl;
    }
    
    cout << endl;
    
    // Test case 2: Short words
    vector<string> words2 = {"What", "must", "be", "acknowledgment", "shall", "be"};
    int maxWidth2 = 16;
    
    cout << "Test Case 2:" << endl;
    cout << "Words: ";
    for(const string& word : words2) {
        cout << word << " ";
    }
    cout << endl;
    cout << "Max Width: " << maxWidth2 << endl;
    cout << "Justified Text:" << endl;
    
    vector<string> result2 = fullJustify(words2, maxWidth2);
    for(const string& line : result2) {
        cout << "\"" << line << "\"" << endl;
    }
    
    cout << endl;
    
    // Test case 3: Single word per line
    vector<string> words3 = {"Science", "is", "what", "we", "understand", "well", "enough", "to", "explain", "to", "a", "computer.", "Art", "is", "everything", "else", "we", "do"};
    int maxWidth3 = 20;
    
    cout << "Test Case 3:" << endl;
    cout << "Words: ";
    for(const string& word : words3) {
        cout << word << " ";
    }
    cout << endl;
    cout << "Max Width: " << maxWidth3 << endl;
    cout << "Justified Text:" << endl;
    
    vector<string> result3 = fullJustify(words3, maxWidth3);
    for(const string& line : result3) {
        cout << "\"" << line << "\"" << endl;
    }
    
    return 0;
}
