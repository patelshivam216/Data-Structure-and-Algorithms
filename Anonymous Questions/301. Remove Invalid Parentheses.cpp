#include<bits/stdc++.h>
using namespace std;
/*

find_wast() -> used to find that how many parenthesis are extra and not more useful

find_ans() -> when we get count of wast parenthesis we remove one by one and when 
we remove parenthesis same as count then we check if that resulted string have 
wats or not if not than that could be our ans;

*/

int find_wast(string s){
    stack<char> stack;
    int n = s.size();
    for(int i=0;i<n;i++){
        char ch = s[i];
        
        if(ch == '('){
            stack.push(ch);
        }else if(ch == ')'){
            if(stack.size() == 0) stack.push(ch);
            else if(stack.top() == '(') stack.pop();
            else if(stack.top() == ')') stack.push(ch);
        }
    }
    
    return stack.size();
}

void find_ans(string s , int mn , set<string> &ans){
    
    if(mn == 0){
        int wast = find_wast(s);
        if(wast == 0) ans.insert(s);
        return;
    }
    
    for(int i=0;i<s.size();i++){

        // remove ith parenthesis
        
        string left = s.substr(0,i);
        string right = s.substr(i+1);
        
        find_ans(left+right,mn-1,ans);
        
        
    }
    
}
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        
        set<string> hashans;
        vector<string> ans;
        int mn = find_wast(s);
        
        find_ans(s,mn,hashans);
        for(auto  str : hashans){
            ans.push_back(str);
        }
        return ans;
        
    }
};