#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false)
#define fast2 cin.tie(NULL)
#define pb push_back
vector<string>word_dict;
vector<string>res;

struct TrieNode
{
	bool endOfWord;
	TrieNode* child[26];
	TrieNode()
	{
		endOfWord = false;
		for(int i=0;i<26;i++)
		{
			child[i] = NULL;
		}
	}
};

bool comp(const string &a, const string &b)
{
	return (a.length() < b.length());
}

void insert(TrieNode* root,string word){ //build the Trie
        TrieNode* temp=root;
        for(int i=0;i<(int)word.length();++i){
            int val=word[i]-'a';
            if(temp->child[val]==NULL)
                temp->child[val]=new TrieNode();
            temp=temp->child[val];
        }
        temp->endOfWord=true;
}

bool search(TrieNode* root, string word){ //search in the Trie
        TrieNode* temp=root;
        for(int i=0;i<(int)word.length();++i){
            int val=word[i]-'a';
            if(temp->child[val]==NULL)
                return false;
            temp=temp->child[val];
        }
        return temp->endOfWord;
}


bool split(TrieNode* root, string word){ //dfs to split the word and check
        string str="";
        for(int i=0;i<(int)word.length();++i){
            str+=word[i];
            string after=word.substr(i+1); //split the word to two parts
            if(search(root, str) && after!=""){
                if(search(root, after) || split(root, after))
                    return true;
            }
        }
        return false;
    }

int main()
{
	fast;
	fast2;
	clock_t t1,t2;
	t1 = clock();
	ifstream myFile;
	myFile.open("words1.txt");
	string s;
	if(myFile.is_open())
	{
		while(!myFile.eof())
		{
			myFile >> s;
			//cout<<s<<"\n";
			word_dict.pb(s);
		}
	}
	sort(word_dict.begin(),word_dict.end(),comp);
	TrieNode* root = new TrieNode();
      
	for(int i=0;i<(int)word_dict.size();i++)
	{
		string word = word_dict[i];
		if(split(root, word))
		{
			res.pb(word);
		}
		insert(root, word);
	}
	sort(res.begin(),res.end(),comp);
	//cout<<"Compound Word: "<<res[res.size()-1]<<"\n";
	//cout<<"Compond Word: "<<res[res.size()-2]<<"\n";
	t2 = clock();
	float diff = (float)t2 - (float)t1;
	float execution_time = diff/CLOCKS_PER_SEC;
	cout<<"\n"<<execution_time;
	
	for(int i=0;i<(int)res.size();i++)
	{
		cout<<res[i]<<"\n";
	}
	/**/		
	return 0;
}
    
