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

    void insert(string key);                            //������� ����� � ������
    bool search(string key);                            //���� �� ����� � ������?
    void coutWordsFromRoot(TrieNode* root, string word);//���������� ���� ������ ������� � �����
    void coutWordsFromWord(string word);                //���������� ���� � ��������� word
    void printWords();                                   //���������� ���� ���� ������


};
extern bool chInRange(char ch);
