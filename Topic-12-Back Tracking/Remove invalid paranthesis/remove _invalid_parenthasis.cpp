//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
    }
 
    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            if(i!=A.size()-1) cout << A[i]<< " ";
            else cout << A[i];
        }
        cout << endl;
    }
};


// } Driver Code Ends


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


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        
        string s; 
        cin>>s;
        
        Solution obj;
        vector<string> res = obj.removeInvalidParentheses(s);
        
        Array::print(res);
        
    }
}

// } Driver Code Ends