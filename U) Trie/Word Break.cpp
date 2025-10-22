// Question Details:
// Given a string 's' and an array of words (dictionary), determine if 's' can be segmented into 
// one or more dictionary words. Words can be used once. Use Trie and DP for efficient lookup and segmentation.
//
// Constraints:
// 1 <= length of s <= 1000
// 1 <= number of words <= 1000
// Words contain only lowercase letters.
//
// Input:
// String s
// Array of dictionary words
//
// Output:
// true if s can be segmented into dictionary words, else false.

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const string &word) {
        TrieNode* current = root;
        for (char c : word) {
            if (current->children.find(c) == current->children.end()) {
                current->children[c] = new TrieNode();
            }
            current = current->children[c];
        }
        current->isEndOfWord = true;
    }

    bool search(const string &word) {
        TrieNode* current = root;
        for (char c : word) {
            if (current->children.find(c) == current->children.end()) {
                return false;
            }
            current = current->children[c];
        }
        return current->isEndOfWord;
    }
};

bool wordBreak(const string &s, const vector<string> &words) {
    Trie trie;
    for (const string &word : words) {
        trie.insert(word);
    }

    int n = s.size();
    vector<bool> dp(n + 1, false);
    dp[0] = true;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (dp[j] && trie.search(s.substr(j, i - j))) {
                dp[i] = true;
                break;
            }
        }
    }

    return dp[n];
}

int main() {
    string s = "applepie";
    vector<string> words = {"apple", "pie", "banana"};

    if (wordBreak(s, words)) {
        cout << "true\n";
    } else {
        cout << "false\n";
    }

    return 0;
}
