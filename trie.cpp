#include "trie.h"
#include <string.h>

TrieNode::TrieNode()
{
    isEndOfWord = false;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        children[i] = nullptr;
}

Trie::Trie()
{
    m_root = new TrieNode;
}

void Trie::insert(string key)
{
    TrieNode* curr = root();
    for (size_t i = 0; i < key.length(); i++)
    {
        int index = 0;
        if (key[i] >= 65 && key[i] <= 90)
            index = key[i] - 'A';
        if (key[i] >= 97 && key[i] <= 122)
            index = key[i] - 'a';
        if (!curr->children[index]) {
            curr->children[index] = new TrieNode;
        }
        curr = curr->children[index];
        curr->count++;
    }
    curr->isEndOfWord = true;
}

bool Trie::search(string key)
{
    TrieNode* current = root();
    for (size_t i = 0; i < key.length(); i++)
    {
        int index = 0;
        if (key[i] >= 65 && key[i] <= 90)
            index = key[i] - 'A';
        if (key[i] >= 97 && key[i] <= 122)
            index = key[i] - 'a';
        if (!current->children[index])
            return false;
        current = current->children[index];
    }
    return current->isEndOfWord;
}

void Trie::coutWordsFromRoot(TrieNode* root, string word)
{
    if (root->isEndOfWord) cout << word << endl;
    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        TrieNode* sun = root->children[i];
        if (!sun) continue;
        char ch = char('a' + i);
        string word1 = word + ch;
        coutWordsFromRoot(sun, word1);
    }
}

void Trie::coutWordsFromWord(string prefix)
{
    string str = "";
    for (size_t i = prefix.length() - 1; ; i--) {
        if (((prefix[i] >= 65 && prefix[i] <= 90)) ||
            ((prefix[i] >= 97 && prefix[i] <= 122))) {
            str += prefix[i];
        }
        else break;
    }
    prefix = "";
    for (size_t i = 0; i < str.length(); i++)
    {
        prefix += str[str.length() - 1 - i];
    }
    TrieNode* current = root();
    for (size_t i = 0; i < prefix.length(); i++) {
        int index = 0;
        if (prefix[i] >= 65 && prefix[i] <= 90)
            index = prefix[i] - 'A';
        if (prefix[i] >= 97 && prefix[i] <= 122)
            index = prefix[i] - 'a';
        if (!current->children[index])
            return;
        current = current->children[index];
    }

    if (current->isEndOfWord) cout << prefix << endl;
    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        TrieNode* sun = current->children[i];
        if (!sun) continue;
        char ch = char('a' + i);
        string word1 = prefix + ch;
        coutWordsFromRoot(sun, word1);
    }
}

void Trie::printWords()
{
    string word;
    if (root()->isEndOfWord) {
        cout << word << endl;
        word = "";
    }
    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        TrieNode* sun = root()->children[i];
        if (!sun) continue;
        char ch = char('a' + i);
        string word1 = word + ch;
        coutWordsFromRoot(sun, word1);
    }
}
