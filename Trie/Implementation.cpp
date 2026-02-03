
#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    TrieNode* next[26];
    bool end;

    TrieNode() {
        end = false;
        for (int i = 0; i < 26; i++) next[i] = nullptr;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    // CREATE
    void insert(string s) {
        TrieNode* cur = root;
        for (char c : s) {
            int i = c - 'a';
            if (!cur->next[i]) cur->next[i] = new TrieNode();
            cur = cur->next[i];
        }
        cur->end = true;
    }

    // READ
    bool search(string s) {
        TrieNode* cur = root;
        for (char c : s) {
            int i = c - 'a';
            if (!cur->next[i]) return false;
            cur = cur->next[i];
        }
        return cur->end;
    }

    // DELETE
    bool removeUtil(TrieNode* node, string& s, int d) {
        if (!node) return false;

        if (d == s.size()) {
            if (!node->end) return false;
            node->end = false;
            return empty(node);
        }

        int i = s[d] - 'a';
        if (removeUtil(node->next[i], s, d + 1)) {
            delete node->next[i];
            node->next[i] = nullptr;
            return !node->end && empty(node);
        }
        return false;
    }

    void remove(string s) {
        removeUtil(root, s, 0);
    }

    // UPDATE
    void update(string oldWord, string newWord) {
        remove(oldWord);
        insert(newWord);
    }

    bool empty(TrieNode* node) {
        for (int i = 0; i < 26; i++) {
            if (node->next[i]) return false;
        }
        return true;
    }
    
    void printUtil(TrieNode* node, string& path) {
    if (node->end) {
        cout << path << endl;
    }

    for (int i = 0; i < 26; i++) {
        if (node->next[i]) {
            path.push_back('a' + i);
            printUtil(node->next[i], path);
            path.pop_back();
        }
    }
}

void printAll() {
    string path = "";
    printUtil(root, path);
}

};

int main() {
    Trie t;

    t.insert("cat");
    t.insert("car");

    cout << t.search("cat") << endl;   // 1
    cout << t.search("cap") << endl;   // 0

    t.update("cat", "cow");
    cout << t.search("cat") << endl;   // 0
    cout << t.search("cow") << endl;   // 1

    t.remove("car");
    cout << t.search("car") << endl;   // 0

    return 0;
}
