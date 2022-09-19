// *************  STRING HASH ************//

/*

--> base should be greater than 27
--> a's interger value is 1 NOT 0 
--> rooling has function if we have hash of "apna" and "ap" then we can find hash of "na"

--> this grows exponentially so mod it with 1e9+7
-->probability of collisions is 1/1e9+7 

QUE : find number of unique string

Bruteforce -: NMlog(N) sorting the string
M - size of string
N - length of string

Final Time compexity : O(NM) + O(Nlon(N))

*/


#include<bits/stdc++.h>
using namespace std;
#define ll long long

int const base = 31;
int const N = 1e5+7;
int const MOD = 1e9+7;
vector<ll> powers(N);

ll HashValues(string s){
    ll hash = 0;
    for(int i=0;i<s.size();i++){
        hash = (hash + (s[i] - 'a' + 1)*powers[i])%MOD;
    }

    return hash;
}

int main(){

    // prerequirement
    powers[0]=1;
    for(int i=1;i<N;i++){
        powers[i] = (powers[i-1] * base)%MOD;
    }

    // input

    int n;
    cin>>n;
    vector<string> strings(n);
    for(int i=0;i<n;i++) cin>>strings[i];

    // calculate hash value for strings
    vector<ll> store;
    
    for(int i=0;i<n;i++){
        store.push_back(HashValues(strings[i]));
    }

    sort(store.begin(),store.end());
    int count = 0;

    for(int i=0;i<n;i++){
        if(i == 0 || store[i]!=store[i-1]){
            count += 1;
        }
    }

    cout<<count<<endl;

    return 0;


}
