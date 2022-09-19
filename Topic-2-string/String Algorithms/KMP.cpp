// *************  KMP string matching algorithms  ************//

/*

--> Time complexity reduces to O(N+M)
--> prefixArray's time complexity is O(N)

--> for EX : abcabcd and do hands On

--> question : find the pos of string s in string t

*/


#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>

vi prefixArray(string s){
    int n = s.size();
    vi pi(n,0);
    for(int i=1;i<n;i++){
        int j = pi[i-1];

        // if Not (Before match)
        while(j>0 and s[i]!=s[j]){
            j = pi[j-1];
        }
        
        // if matches
        if(s[i] == s[j]){
            j++;
        }

        pi[i]=j;
    }

    // Time complexity : O(n)
    return pi;

}

int main(){

    /*** TEST

    string s = "abcabcd";
    vi prefix = prefixArray(s);
    for(auto v : prefix) cout<<v<<" ";
    
    */

    string s = "na";
    string t = "apnacollage";
    vi prefix = prefixArray(s);

    int i = 0,j = 0;
    int pos = -1;
    while(i<t.size()){
        if(t[i] ==  s[j]){ // if both are matching then move ahead
            i++;
            j++;
        }else{ // if not matching
            if(j!=0){ // and if j>0 , then reach out previously matched position
                j = prefix[j-1];
            }else i++; // if we are yet at 0 then move i only
        }

        if(j == s.size()){ // if we reach at end 
            pos = i-s.size(); // then we matched both string so 
        }
    }

    cout<<pos<<endl;


    return 0;
}