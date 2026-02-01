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
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        childCount = 0;
        isTerminal = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* node, string word) {
        if (word.length() == 0) {
            node->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        if (node->children[index] != nullptr) {
            child = node->children[index];
        } else {
            child = new TrieNode(word[0]);
            node->children[index] = child;
            node->childCount++;
        }

        insertUtil(child, word.substr(1));
    }

    void insertWord(string word) {
        insertUtil(root, word);
    }

    void lcp(string str, string &ans) {
        TrieNode* curr = root;

        for (int i = 0; i < str.length(); i++) {
            char ch = str[i];
            int index = ch - 'a';

            if (curr->childCount == 1 && curr->children[index] != nullptr) {
                ans.push_back(ch);
                curr = curr->children[index];
            } else {
                break;
            }

            if (curr->isTerminal) {
                break;
            }
        }
    }
};

string longestCommonPrefix(vector<string> &arr, int n) {
    if (n == 0) return "";

    Trie t;

    for (int i = 0; i < n; i++) {
        t.insertWord(arr[i]);
    }

    string ans = "";
    t.lcp(arr[0], ans);
    return ans;
}


int main(){



    return 0; 
}