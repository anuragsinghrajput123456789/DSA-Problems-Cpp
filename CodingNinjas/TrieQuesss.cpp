#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    char data;
    TrieNode* children[26];
    int childCount;
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        childCount = 0;
        isTerminal = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* node, const string& word, int index) {
        if (index == word.size()) {
            node->isTerminal = true;
            return;
        }

        int idx = word[index] - 'a';

        if (!node->children[idx]) {
            node->children[idx] = new TrieNode(word[index]);
            node->childCount++;
        }

        insertUtil(node->children[idx], word, index + 1);
    }

    void insertWord(const string& word) {
        insertUtil(root, word, 0);
    }

    string lcp() {
        string ans = "";
        TrieNode* curr = root;

        while (curr && curr->childCount == 1 && !curr->isTerminal) {
            for (int i = 0; i < 26; i++) {
                if (curr->children[i]) {
                    ans.push_back('a' + i);
                    curr = curr->children[i];
                    break;
                }
            }
        }
        return ans;
    }
};

string longestCommonPrefix(vector<string>& arr, int n) {
    if (n == 0) return "";

    Trie t;

    for (int i = 0; i < n; i++) {
        t.insertWord(arr[i]);
    }

    return t.lcp();
}
