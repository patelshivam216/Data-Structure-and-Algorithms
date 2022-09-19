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

    bool isEnd(){
        return flag;
    }
};

class Trie{
private:
    Node* root;
public:
    Trie(){
        root = new Node();
    }

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


    bool isAllprefixExists(string &word){
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if( node->containkey(word[i]) ){
                node = node->get(word[i]);
                if((node->isEnd()) == false){
                    return false;
                }
            }else return false;
        }

        return node->isEnd();
    }
};


string completeString(int n, vector<string> &a){
    Trie ob;
    for(int i=0;i<n;i++){
        string word = a[i];
        ob.insert(word);
    }

    int len = 0;
    string ans = "";
    for(int i=0;i<n;i++){
        string word = a[i];
        if(ob.isAllprefixExists(word)){
            if(len < word.size()){
                ans = word;
                len = word.size();
            }
        }
    }

    if(ans == "") return "None";

    return ans;

}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        string ans = completeString(n,arr);
        if(ans == "") cout<<"None"<<endl;
        else cout<<ans<<endl;

    }

    return 0;

}

/*

input:

3
6
g l lm ga lmn gaz
3
a aa aaa
3
sc sct sctz

*/