#include<bits/stdc++.h>
using namespace std;
int main(){

    string s,ptr;
    cin>>s>>ptr;
    unordered_map<char , int> m;
    for(auto c : ptr){
        m[c]++;
    }
    int count,k;
    count=m.size();
    k=ptr.size();
    int ans,i,j;
    ans=0;
    j=0;
    i=0;
    
    while(i<s.size()){

        //calculation
        if(m.find(s[i]) != m.end()){
            m[s[i]]--;
        }

        if(m[s[i]]==0){
            count--;
        }

        if(i-j+1<k){
            i++;
        }
        else if(i-j+1==k){
            //calculation for ans
            if(count==0){
                ans++;
            }

            // calculation for silde the wondow
            if(m.find(s[j]) != m.end()){

                m[s[j]]++;
                count++;

            }
            i++;
            j++;
        }
    }

    cout<<ans;
    return 0;
}
