// *************  rabin-karp algorithm  ************//

/*

--> calculate the occurance of s in t
--> upon string hashing
--> EQUATION :  P^i * hash[i...j] = hash[0...j] - hash[0...i-1];

so j-i+1 == s.size() , then we find occurance 


*/


#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<long long int>
int const N = 1e5+10;
int const base = 31;
int const mod = 1e9+7;
vi powers(N);

ll FindHash(string s){
    ll hash = 0;
    for(int i=0;i<s.size();i++){
        hash = (hash + (s[i] - 'a'+ 1)*powers[i])%mod;
    }

    return hash;
}


int main(){
    powers[0]=1;
    for(int i=1;i<N;i++){
        powers[i] = (powers[i-1]*base)%mod;
    }

    string s = "na";
    string t = "apnacollagenaa";
    int S = s.size();
    int T = t.size();
    
    ll hashOfS = FindHash(s);

    // here we break down whole string t , so we can easily calculate hash[i...j]

    vi h(T+1,0); // hash value at every index of string t 
    for(int i=0;i<T;i++){
        h[i+1] = (h[i] + (t[i]-'a' + 1)*powers[i])%mod;
    }

    for(int i=0;i + S - 1 < T ;  i++){ // in t last S index are use less if we can't find it before i+S-1
        ll cur_hash = (h[i+S] - h[i] + mod) % mod; // from equation

        // cur_hash have been multiplied by power^i so , to make equal we have to multiply hashOfS with power[i]

        if(cur_hash == (powers[i] * hashOfS)%mod ){ 
            cout<<"found at "<<i<<endl; 
        }
    }

    return 0;
}