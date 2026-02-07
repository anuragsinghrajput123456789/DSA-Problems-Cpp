#include <bits/stdc++.h>
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

    void insertUtil(TrieNode *node, string word)
    {

        if (word.length() == 0)
        {
            node->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode *child;

        if (node->children[index])
        {
            child = node->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            node->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }

    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    void getAllSuggestions(TrieNode *curr,
                           vector<string> &temp,
                           string prefix)
    {

        if (curr->isTerminal)
        {
            temp.push_back(prefix);
        }

        for (char ch = 'a'; ch <= 'z'; ch++)
        {

            TrieNode *next = curr->children[ch - 'a'];

            if (next)
            {
                prefix.push_back(ch);
                getAllSuggestions(next, temp, prefix);
                prefix.pop_back();
            }
        }
    }

    vector<vector<string>> getSuggestions(string query)
    {

        vector<vector<string>> ans;
        TrieNode *prev = root;
        string prefix = "";

        for (char ch : query)
        {

            prefix.push_back(ch);
            TrieNode *curr = prev->children[ch - 'a'];

            if (!curr)
            {
                break;
            }

            vector<string> temp;
            getAllSuggestions(curr, temp, prefix);
            ans.push_back(temp);

            prev = curr;
        }

        return ans;
    }
};

vector<vector<string>> phoneDirectory(vector<string> &contactList,
                                      string &queryStr)
{
    sort(contactList.begin(), contactList.end());

    contactList.erase(
        unique(contactList.begin(), contactList.end()),
        contactList.end());

    Trie t;

    for (string contact : contactList)
    {
        t.insertWord(contact);
    }

    return t.getSuggestions(queryStr);
}
