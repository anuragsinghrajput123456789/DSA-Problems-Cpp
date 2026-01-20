
#include <bits/stdc++.h>
using namespace std;

class Trienode {
public:
    char data;
    Trienode* children[26];
    bool isTerminal;

    Trienode(char ch) {
        data = ch;
        isTerminal = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
public:
    Trienode* root;

    Trie() {
        root = new Trienode('\0');
    }

    // CREATE / INSERT
    void insertUtil(Trienode* node, string word) {
        if (word.length() == 0) {
            node->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';

        if (!node->children[index]) {
            node->children[index] = new Trienode(word[0]);
        }

        insertUtil(node->children[index], word.substr(1));
    }

    void insert(string word) {
        insertUtil(root, word);
    }

    // READ / SEARCH
    bool searchUtil(Trienode* node, string word) {
        if (word.length() == 0) {
            return node->isTerminal;
        }

        int index = word[0] - 'a';

        if (!node->children[index]) {
            return false;
        }

        return searchUtil(node->children[index], word.substr(1));
    }

    bool search(string word) {
        return searchUtil(root, word);
    }

    // UPDATE
    void update(string oldWord, string newWord) {
        remove(oldWord);
        insert(newWord);
    }

    // DELETE
    bool deleteUtil(Trienode* node, string word, int depth) {
        if (!node) return false;

        if (depth == word.length()) {
            if (!node->isTerminal) return false;
            node->isTerminal = false;
            return isEmpty(node);
        }

        int index = word[depth] - 'a';

        if (deleteUtil(node->children[index], word, depth + 1)) {
            delete node->children[index];
            node->children[index] = nullptr;
            return !node->isTerminal && isEmpty(node);
        }

        return false;
    }

    void remove(string word) {
        deleteUtil(root, word, 0);
    }

    bool isEmpty(Trienode* node) {
        for (int i = 0; i < 26; i++) {
            if (node->children[i]) return false;
        }
        return true;
    }
};

int main() {
    Trie t;

    t.insert("hello");
    t.insert("help");

    cout << t.search("hello") << endl; // 1
    cout << t.search("hel") << endl;   // 0

    t.update("hello", "hi");
    cout << t.search("hello") << endl; // 0
    cout << t.search("hi") << endl;    // 1

    t.remove("help");
    cout << t.search("help") << endl;  // 0

    return 0;
}
