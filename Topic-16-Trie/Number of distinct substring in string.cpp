#include<bits/stdc++.h>
using namespace std;

class Node{
private:
    Node* links[26];
public:
    bool containkey(char ch){
        if(links[ch-'a'] != NULL) return true;
        return false;
    }

    Node* get(char ch){
        return links[ch-'a'];
    }

    void put(char ch,Node* node){
        links[ch-'a'] = node;
    }


};

class Trie{
private:
    Node* root;
public:
    Trie(){
        root = new Node();
    }

    int getDistinctSubstring(string &s){
        Node * root = new Node();
  		int count = 0;
  		int n = s.size();

  		for (int i = 0; i < n; i++) {

    		Node * node = root; // every time we start finding from the root

   		 	for (int j = i; j < n; j++) {

      			if (!node -> containkey(s[j])) {

        			node -> put(s[j], new Node());

        			count++; // put it in 

      			} // else { if it is already present then that is not distinct}

      			node = node -> get(s[j]);
    		}

  		}
  		
  		return count + 1; // add one for empty string 
    }
};

int main(){
    string s;
    cin>>s;

    Trie ob;

    cout<<ob.getDistinctSubstring(s);

    return 0;

}