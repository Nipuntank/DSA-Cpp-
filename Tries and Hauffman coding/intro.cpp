#include <iostream>
#include <string>
using namespace std;
class TrieNode
{
public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data)
    {
        this->data = data;
        isTerminal = false;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
    }
};
class Trie
{
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode('\0');
    }
    bool search(TrieNode *root, string word)
    {
        if (word.size() == 0)
        {
            return root->isTerminal;
        }
        int index = word[0] - 'a';
        if (root->children[index] != NULL)
        {
            return false;
        }
        return search(root->children[index], word.substr(1));
    }
    bool search(string word)
    {
        return search(root, word);
    }
    void insertWord(TrieNode *root, string word)
    {
        // base case
        if (word.size() == 0)
        {
            root->isTerminal = true;
            return;
        }

        // calculation
        TrieNode *child;
        int index = word[0] - 'a';
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        insertWord(child, word.substr(1));
        // recursive call
    }
    void insertWord(string word)
    {
        insertWord(root, word);
    }
    void remove(TrieNode *root, string word)
    {
        if (word.size() == 0)
        {
            root->isTerminal = false;
            return;
        }
        TrieNode *child;
        int index = word[0] - 'a';
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return;
        }
        remove(child, word.substr(1));

        // remove child if its is useless
        if (child->isTerminal == false)
        {
            for (int i = 0; i < 26; i++)
            {
                if (child->children[i]!=NULL)
                {
                    return ;
                }
            }
            delete child;
            root->children[index]=NULL;
        }
    }
    void remove(string word)
    {
        remove(root, word);
    }
};
int main()
{
    Trie t;
    t.insertWord("and");
    t.insertWord("ans");
    t.insertWord("bed");
    t.insertWord("bank");
    cout<<t.search("ans")<<endl;
    t.remove("ans");
    cout<<t.search("ans")<<endl;
    return 0;
}