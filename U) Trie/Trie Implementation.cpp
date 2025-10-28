// Problem Statement: Implement a Trie Data Structure which supports the following three operations:

// Search (word): To check if the string `word` is present in the Trie or not.
// Insert (word): To insert a string `word` in the Trie.
// Start With(word): To check if there is a string that has the prefix `word`.
// Trie is a data structure that is like a tree data structure in its organisation. It consists of nodes that store letters or alphabets of words, which can be added, retrieved, and deleted from it in a very efficient way.

// In other words, Trie is an information retrieval data structure, which can beat naive data structures like Hashmap, Tree, etc in the time complexity of its operations.
#include <iostream>
using namespace std;
class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode *root, string word)
    {
        // base case
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }
        // assumption, word will be in CAPS
        int index = word[0] - 'A';
        TrieNode *child;
        // present
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            // absent
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // RECURSION
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode *root, string word)
    {
        // base case
        if (word.length() == 0)
        {
            return root->isTerminal;
        }
        int index = word[0] - 'A';
        TrieNode *child;

        // present
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            // absent
            return false;
        }
        return searchUtil(child, word.substr(1));
    }

    bool searchWord(string word)
    {
        return searchUtil(root, word);
    }

    void deleteUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = false;
        }
        int index = word[0] - 'A';
        TrieNode *child;

        // present
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            // absent
            cout << "word not found" << endl;
            return;
        }
        return deleteUtil(child, word.substr(1));
    }

    void deleteWord(string word)
    {
        deleteUtil(root, word);
    }
};

int main()
{
    Trie *t = new Trie();

    t->insertWord("ARM");
    t->insertWord("DO");
    t->insertWord("TIME");
    t->insertWord("HELLO");

    cout << "Present or Not DO " << t->searchWord("DO") << endl;

    t->deleteWord("DO");
    
    cout << "Present or Not DO " << t->searchWord("DO") << endl;
    cout << t->searchWord("HEL") << endl;

    return 0;
}