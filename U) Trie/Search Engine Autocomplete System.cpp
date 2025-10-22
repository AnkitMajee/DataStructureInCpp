// Question: Implement a Trie-based autocomplete system with Insert, Autocomplete, Delete, and Update operations.

// Input:
// insert(word, frequency) - a string word and its frequency
// autocomplete(prefix, K) - a string prefix and an integer K to return the top K completions
// delete(word) - a string word to delete from the Trie
// updateFrequency(word, newFrequency) - a string word to update its frequency
// search(word) - a string word to check if it exists in the Trie

// Output:
// autocomplete(prefix, K) - return the top K most frequent completions for the given prefix
// search(word) - return true if the word exists in the Trie, otherwise return false
// delete(word) - return true if the word is successfully deleted, otherwise return false
// updateFrequency(word, newFrequency) - return true if the frequency is updated, otherwise return false

// Constraints:
// 1. The number of queries will not exceed 10^6.
// 2. The length of each word/query will not exceed 1000.

#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

class TrieNode
{
public:
    unordered_map<char, TrieNode *> children;
    unordered_map<string, int> wordFrequency;

    TrieNode() {}
    ~TrieNode() {
        for (auto& pair : children) { 
            delete pair.second; 
        } 
    }
};

class Trie
{
private:
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    ~Trie() {
        deleteAll(root);
    }

private:
    void deleteAll(TrieNode* node) {
        if (!node) return;
        for (auto& pair : node->children) { 
            deleteAll(pair.second); 
        }
        delete node;
    }

    void insert(const string &word, int frequency)
    {
        TrieNode *current = root;
        for (char c : word)
        {
            if (current->children.find(c) == current->children.end())
            {
                current->children[c] = new TrieNode();
            }
            current = current->children[c];
        }
        current->wordFrequency[word] = frequency;
    }

    vector<string> autocomplete(const string &prefix, int K)
    {
        TrieNode *current = root;
        vector<string> results;

        for (char c : prefix)
        {
            if (current->children.find(c) == current->children.end())
            {
                return results; // No words with this prefix
            }
            current = current->children[c];
        }

        priority_queue<pair<int, string>> pq;
        collectAllWords(current, pq);

        int count = 0;
        while (!pq.empty() && count < K)
        {
            results.push_back(pq.top().second);
            pq.pop();
            count++;
        }

        return results;
    }

    void collectAllWords(TrieNode* node, priority_queue<pair<int, string>>& pq)
    {
        if (!node) return;
        
        // Add words at current node
        for (const auto &entry : node->wordFrequency)
        {
            pq.push({entry.second, entry.first});
        }
        
        // Recursively collect from children
        for (const auto &child : node->children)
        {
            collectAllWords(child.second, pq);
        }
    }

    bool deleteWord(const string &word)
    {
        return deleteWordHelper(root, word, 0);
    }

    bool deleteWordHelper(TrieNode *current, const string &word, int index)
    {
        if (index == word.length())
        {
            if (current->wordFrequency.find(word) != current->wordFrequency.end())
            {
                current->wordFrequency.erase(word);
                return current->children.empty() && current->wordFrequency.empty();
            }
            return false;
        }

        char c = word[index];
        if (current->children.find(c) == current->children.end())
        {
            return false; // Word doesn't exist
        }

        TrieNode *nextNode = current->children[c];
        bool shouldDeleteCurrentNode = deleteWordHelper(nextNode, word, index + 1);

        if (shouldDeleteCurrentNode)
        {
            current->children.erase(c);
            return current->children.empty() && current->wordFrequency.empty();
        }

        return false;
    }

    bool updateFrequency(const string &word, int newFrequency)
    {
        TrieNode *current = root;
        for (char c : word)
        {
            if (current->children.find(c) == current->children.end())
            {
                return false; // Word not found
            }
            current = current->children[c];
        }
        if (current->wordFrequency.find(word) != current->wordFrequency.end())
        {
            current->wordFrequency[word] = newFrequency;
            return true;
        }
        return false;
    }

    bool search(const string &word)
    {
        TrieNode *current = root;
        for (char c : word)
        {
            if (current->children.find(c) == current->children.end())
            {
                return false;
            }
            current = current->children[c];
        }
        return current->wordFrequency.find(word) != current->wordFrequency.end();
    }
};

int main()
{
    Trie trie;

    trie.insert("apple", 5);
    trie.insert("app", 10);
    trie.insert("applause", 3);
    trie.insert("banana", 4);

    cout << "Autocomplete for 'app': ";
    vector<string> results = trie.autocomplete("app", 3);
    for (const string &word : results)
    {
        cout << word << " ";
    }
    cout << endl;

    cout << "Search 'apple': " << (trie.search("apple") ? "Found" : "Not Found") << endl;

    cout << "Update frequency of 'apple' to 8: ";
    cout << (trie.updateFrequency("apple", 8) ? "Updated" : "Not Found") << endl;

    cout << "Autocomplete for 'app' after frequency update: ";
    results = trie.autocomplete("app", 3);
    for (const string &word : results)
    {
        cout << word << " ";
    }
    cout << endl;

    cout << "Delete 'app': ";
    cout << (trie.deleteWord("app") ? "Deleted" : "Not Found") << endl;

    return 0;
}
