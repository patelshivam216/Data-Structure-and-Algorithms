#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include<bits/stdc++.h>
#include <algorithm>
using namespace std;
unordered_map<char,int> m={
    {'{',-1},
    {'}',1}  
};


int isvalid(string s){
    
    int ln=s.size();
    stack<char> st;
    string s1;
    int count=0;
    int op=0;
    int cl=0;
    s1=newstr(s);
    if(ln%2!=0){
            return -1;
    }
    
        for(auto braket : s){
            if(m[braket]>0){
                
                
                count++;
                
                
            }else {
                break;
            }
            
            
        }
    
    for(auto braket : s1){
        if(m[braket]<0)
            op++;
        else 
            cl++;
            
    }
    
    if(op==cl && op==1){
        return 0;
    }else if(op==cl && op>1){
        return count;
    }
    
    
    
    
}

string newstr(string s){
    int ln=s.size();
    string rstr;
    for(int i=1;i<ln;i++){
        rstr.push_back(s[i]);
    }
    rstr.push_back(s[0]);
    return rstr;
}

int main() {
    
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
       
        cout<<isvalid(s);
    }
      
    return 0;
}
