#include <iostream>
#include <vector>
#define VECOUT(v) for (int def_i = 0; def_i < v.size(); ++def_i) cout << v[def_i] << ','
#define PRINT(x) cout << x << endl
#define N 10
#include <algorithm>
#include <map>

using namespace std;

class TrieNode {
public:
    bool isEnd;
    TrieNode *next[26] = {NULL};
    TrieNode() : isEnd(false) {}
    bool isNull() {
        for (int i = 0; i < 26; ++i)
            if (next[i])
                return false;
        return true;
    }
};

class WordDictionary {
public:
    TrieNode *root = new TrieNode();
    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode *p = root;
        for (int i = 0; i < word.length(); ++i) {
            int index = int(word[i] - 97);
            if (p->next[index])
                p = p->next[index];
            else
                p = p->next[index] = new TrieNode();
        }
        p->isEnd = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return searchOne(word, root);
    }

    bool searchOne(string word, TrieNode *p) {
        int wordLen = word.length();
        if (!p->isNull() && !wordLen)
            if (p->isEnd)
                return true;
            else
                return false;
        else if (p->isNull() && !wordLen) {
            return true;
        }
        else if (p->isNull() && wordLen)
            return false;
        else {
            if (word[0] == '.') {
                for (int i = 0; i < 26; ++i)
                    if (p->next[i])
                        if (searchOne(word.substr(1), p->next[i]))
                            return true;
                return false;
            }
            int c = word[0] - 97;
            if (p->next[c])
                return searchOne(word.substr(1), p->next[c]);
            else
                return false;
        }
    }
};

int main()
{
    WordDictionary wordDictionary;
//    wordDictionary.addWord("and");
//    wordDictionary.addWord("an");
//    wordDictionary.addWord("add");
    wordDictionary.addWord("ab");
    wordDictionary.addWord("bcd");
    cout << wordDictionary.root->next[1]->next[2]->next[3]->isEnd   << endl;
    cout << wordDictionary.search(".cd");
    cout << endl;
}
