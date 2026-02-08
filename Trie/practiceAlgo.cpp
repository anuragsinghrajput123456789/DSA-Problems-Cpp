#include <iostream>
#include <string>
#include <vector>

using namespace std;

// --- TRIE IMPLEMENTATION ---
class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++) children[i] = nullptr;
        isTerminal = false;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() { root = new TrieNode('\0'); }

    void insertUtil(TrieNode* root, string &word, int i) {
        if (i == word.length()) {
            root->isTerminal = true;
            return;
        }
        if (word[i] < 'a' || word[i] > 'z') return; 

        int index = word[i] - 'a';
        if (root->children[index] == nullptr) {
            root->children[index] = new TrieNode(word[i]);
        }
        insertUtil(root->children[index], word, i + 1);
    }

    void insertWord(string word) { insertUtil(root, word, 0); }

    bool searchWord(string word) {
        TrieNode* curr = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (index < 0 || index >= 26 || curr->children[index] == nullptr) return false;
            curr = curr->children[index];
        }
        return curr->isTerminal;
    }
};

// --- SEARCH ALGORITHMS ---

int binarySearch(int arr[], int n, int target) {
    int s = 0, e = n - 1;
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) s = mid + 1;
        else e = mid - 1;
    }
    return -1;
}

int linearSearch(int arr[], int n, int target) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == target) return i;
    }
    return -1;
}

// --- ARRAY PRINTING ---

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

void printArrayRecursive(int arr[], int n) {
    if (n <= 0) return;
    cout << arr[0] << " ";
    // Move the pointer forward and reduce the count
    printArrayRecursive(arr + 1, n - 1);
}

int main() {
    int myArr[] = {2, 4, 6, 8, 10, 12};
    int n = 6;

    cout << "Binary Search (target 10): " << binarySearch(myArr, n, 10) << endl;
    cout << "Recursive Print: ";
    printArrayRecursive(myArr, n);
    cout << endl;

    Trie t;
    t.insertWord("code");
    cout << "Search 'code': " << (t.searchWord("code") ? "Found" : "Not Found") << endl;

    return 0;
}