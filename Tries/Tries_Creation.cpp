#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

//trie structure
struct TrieNode
{
  struct TrieNode* child[26];
  bool is_str_end;
};

//to create a trieNode type node
struct TrieNode* createNode()
{
  struct TrieNode *t=new struct TrieNode;
  if(t)
  {
    t->is_str_end=false;
    for (int i = 0; i < 26; ++i)
    {
        t->child[i]=NULL;
    }
    return t;
  }
  else
    return NULL;
}

//to insert a new character in the Trie ,if it is already present then ignore and
//keep on traversing else insert the key
void InsertNode(struct TrieNode *root,string word)
{
  int index;    //for storing the index of the character in a-z
  struct TrieNode *t=root;

  for(int i=0;i<word.length();i++)
  {
    index=word[i]-'a';
    if(t->child[index]==NULL)
        t->child[index]=createNode();

    t=t->child[index];
  }

  //when finally the string end
  t->is_str_end=true;
}

//searches the string in the Trie
bool searchString(struct TrieNode *root,string word)
{
   int index;
   struct TrieNode *t=root;

   for (int i = 0; i <word.length(); ++i)
   {
      index=word[i]-'a';
      if(t->child[index]==NULL)
      {
        return false;
       }
       t=t->child[index];
   }
   if(t!=NULL && t->is_str_end==true)
      return true;
}


int main()
{
  // Input keys (use only 'a' through 'z' and lower case)
    string word[8] = {"the", "a", "there", "answer", "any",
                     "by", "bye", "their"};
    struct TrieNode *root = createNode();

    // Construct trie
    for (int i = 0; i < sizeof(word)/sizeof(string); i++)
        InsertNode(root, word[0]);

    // Search for different keys
  
   cout<<"them:"<<searchString(root,"thek")<<endl;
    return 0;
}
