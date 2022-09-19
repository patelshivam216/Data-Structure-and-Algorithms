/*

Problem statement:

Given two strings s and t of lengths m and n respectively, return the minimum window
substring of s such that every character in t (including duplicates) is included in 
the window. If there is no such substring, return the empty string "".

Approch

--> firs find char freq of second string and based on that maintain matching pointer
--> then take window of variable size if we hit matching == m condition ,
 m is size of second string

--> also when have to maintain character map for window and if we hit that condition then we capture
that ans string and then remove that character from  window and window character map
and also at that time maintain matching parameter is also inportant 


*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    string findans(string a,string b){
        if(a == ""){
            return b;
        }

        if(a.size() < b.size()){
            return a;
        }else return b;
    }
public:
    string minWindow(string s, string t) {

        int n = s.size();
        int m = t.size();
        
        if(n<m) return "";


        map<char,int> need;
        for(auto c : t) need[c]++;

        string ans = "";
        int matching = 0;
        map<char,int> window;

        int i = 0;
        int j = 0;
        while(i < n){

            if(need.find(s[i]) != need.end() and window[s[i]] < need[s[i]]){
                matching += 1;
                window[s[i]]++;
            }else window[s[i]]++;

            if(matching == m){
                
                while(matching == m){
                    if(ans.size() == 0)
                        ans = findans(ans,s.substr(j,i-j+1));
                    if(ans.size() > i-j+1){
                        ans = s.substr(j,i-j+1);
                    }

                    window[s[j]]-=1;
                    if(window[s[j]] < need[s[j]]){
                        matching -= 1;
                    }
                    j++;
                }
            }

            i += 1;
        }

        return ans;
        
    }
};


int main(){
    string s,t;
    cin>>s>>t;

    Solution ob;
    cout<<ob.minWindow(s,t)<<endl;


    return 0;
}


/*
ADOBECODEBANC
ABC  
*/
