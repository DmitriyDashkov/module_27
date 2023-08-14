#pragma once
#define ALPHABET_SIZE 52
#define MAX_WORDS_IN_MESSAGE 50
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct TrieNode
{
    TrieNode();
    TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;
    int count = 0;
};

class Trie
{
private:
    TrieNode* m_root;
public:
    Trie();
    TrieNode* root() { return m_root; }
    //    TrieNode *getNode();

    void insert(string key);                            //вставка слова в дерево
    bool search(string key);                            //есть ли слово в дереве?
    void coutWordsFromRoot(TrieNode* root, string word);//распечатка слов дерева начиная с корня
    void coutWordsFromWord(string word);                //распечатка слов с префиксом word
    void printWords();                                   //распечатка всех слов дерева


};
extern bool chInRange(char ch);
