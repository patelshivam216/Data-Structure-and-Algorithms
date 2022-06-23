#include<bits/stdc++.h>
using namespace std;
int main(){

    string s;
    int k;
    cin>>s>>k;

    int n=s.size();
    int ans=0;
    unordered_map<char,int> m;
    int i=0;
    int j=0;
    while(i<n){

        m[s[i]]++;

        if(m.size() == k ){

            ans=max(ans,i-j+1);

        }
        else if(m.size()>k){

            while(m.size()>k){
                m[s[j]]--;
                if(m[s[j]] == 0){
                    m.erase(s[j]);
                }

                j++;
            }
        }

        i++;
        
    }

    cout<<ans;



    return 0;
}