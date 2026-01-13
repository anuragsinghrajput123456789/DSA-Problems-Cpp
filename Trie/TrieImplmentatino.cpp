#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    
    TrieNode(char ch) {
        data = ch;
        for(int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isTerminal = false;
    }
};

class Trie {
private:
    TrieNode* root;

    // Helper to check if node can be deleted
    bool isEmpty(TrieNode* node) {
        for(int i = 0; i < 26; i++) {
            if(node->children[i] != nullptr)
                return false;
        }
        return true;
    }

    // Recursive delete utility
    TrieNode* removeUtil(TrieNode* current, const string& word, int depth) {
        // Base case: end of word
        if(depth == word.length()) {
            // If this is the end of word, unmark it
            if(current->isTerminal) {
                current->isTerminal = false;
            }

            // If node has no children → can be deleted
            if(isEmpty(current)) {
                delete current;
                return nullptr;
            }
            return current;
        }

        int index = word[depth] - 'A';

        // If path doesn't exist → nothing to delete
        if(current->children[index] == nullptr) {
            return current;
        }

        // Recursive call
        current->children[index] = removeUtil(
            current->children[index], 
            word, 
            depth + 1
        );

        // After recursion: check if current node can be deleted
        if(!current->isTerminal && isEmpty(current)) {
            delete current;
            return nullptr;
        }

        return current;
    }

public:
    Trie() {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, string word) {
        if(word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'A';
        TrieNode* child;

        if(root->children[index] != nullptr) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }

    void insertWord(string word) {
        if(word.empty()) return;
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode* root, string word) {
        if(word.length() == 0) {
            return root->isTerminal;
        }

        int index = word[0] - 'A';

        if(root->children[index] == nullptr)
            return false;

        return searchUtil(root->children[index], word.substr(1));
    }

    bool search(string word) {
        if(word.empty()) return false;
        return searchUtil(root, word);
    }

    // Delete word from Trie (with proper node cleanup)
    void remove(string word) {
        if(word.empty()) return;
        root = removeUtil(root, word, 0);
    }

    // Just for demonstration
    void printExists(string word) {
        cout << word << " exists : " << boolalpha << search(word) << endl;
    }
};


int main() {
    Trie t;

    t.insertWord("CAT");
    t.insertWord("CAR");
    t.insertWord("CARD");
    t.insertWord("DOG");
    t.insertWord("COW");

    cout << "Before deletion:\n";
    t.printExists("CAT");
    t.printExists("CAR");
    t.printExists("CARD");
    t.printExists("CAN");
    t.printExists("DOG");

    cout << "\nAfter deleting 'CAR':\n";
    t.remove("CAR");

    t.printExists("CAT");   // true
    t.printExists("CAR");   // false
    t.printExists("CARD");  // true (still exists)
    t.printExists("CAN");   // false
    t.printExists("DOG");   // true

    cout << "\nAfter deleting 'CARD':\n";
    t.remove("CARD");

    t.printExists("CAT");   // true
    t.printExists("CARD");  // false

    return 0;
}