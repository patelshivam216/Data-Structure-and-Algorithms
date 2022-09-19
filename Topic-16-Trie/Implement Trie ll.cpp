#include<bits/stdc++.h>
using namespace std;
class Node{
private:
    Node* links[26];
    int cp = 0; // count prefix
    int ew = 0; // end with

public:

    bool containkey(char ch){
        if(links[ch-'a'] != NULL ) return true;
        return false;
    }

    Node* get(char ch){
        return link[ch-'a'];
    }

    void put(char ch,Node* node){
        links[ch-'a'] = node;
    }

    void increasePrefix(){
        cp += 1;
    }

    void increaseEnd(){
        ew += 1;
    }

    void reducePrefix(){
        cp -= 1;
    }
    void reduceEnd(){
        ew -= 1;
    }

    int getEnd(){
        return ew;
    }

    int getPrefix(){
        return cp;
    }


};


class Trie{
    node* root;

    public:

    Trie(){

        root = new Node();
    }

    void insert(string &word){
        Node* node = root;
        for(int i=0;i<word.size();i++){

            if(!node->containkey(word[i])){
                node->put(word[i],new Node());
            }

            node = node->get(word[i]);
            // increase it after because when we searching, when whole word finish then we 
            // easy calculate prefix because we moved ahead already
            node->increasePrefix();

        }

        node->increaseEnd();
    }

    int countWordsEqualTo(string &word){
        
        Node* node = root;
        for(int i=0;i<word.size();i++){

            if(!node->containkey(word[i])){
                return 0;
            }
            node = node->get(word[i]);
        }

        return node->getEnd();

    }

    int countWordsStartingWith(string &word){
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(!node->containkey(word[i])){
                return 0;
            }

            node = node->get(word[i]);
        }

        return node->getPrefix();
    }

    void erase(string &word){
        Node* node = root;

        for(int i=0;i<word.size();i++){

            if(node->containkey(word[i])){
                node = node->get(word[i]);
                node->reducePrefix();
            }else return;
            
        }

        node->reduceEnd();
    }
};