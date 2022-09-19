#include<bits/stdc++.h>
using namespace std;
class Node{
private:
    Node* links[26];
    bool flag = false;
public:
    bool containkey(char ch){
        if(links[ch-'a'] != NULL) return true;
        return false;
    }

    void put(char ch,Node* node){
        links[ch-'a'] = node;
    }

    Node* get(char ch){
        return links[ch-'a'];
    }

    void setEnd(){
        flag = true;
    }

    bool isend(){
        return flag;
    }
};


class Trie {
private:
    Node* root ;

public:

    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* node = root;
        for(int i=0;i<word.size();i++){ 

            if(node->containkey(word[i]) == false){

                node->put(word[i],new Node());

            }

            // move to referance trie

            node = node->get(word[i]);
        }

        node->setEnd();

    }

    /** Returns if the word is in the trie. */
    bool search(string word) {

        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(!node->containkey(word[i])){
                return false;
            }

            node = node->get(word[i]);
        }

        if(node->isend() == true){
            return true;
        }

        return false;

    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {

        Node* node = root;
        for(int i=0;i<prefix.size();i++){
            if(node->containkey(prefix[i]) == NULL){
                return false;
            }
            node = node->get(prefix[i]);
        }

        return true;

    }
};