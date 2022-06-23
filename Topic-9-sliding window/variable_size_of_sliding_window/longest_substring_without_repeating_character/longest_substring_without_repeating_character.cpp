#include<bits/stdc++.h>
using namespace std;
int main(){

    string s;
    cin>>s;

    int n=s.size();
    int ans=0;
    unordered_map<char,int> m;
    int i=0;
    int j=0;
    while(i<n){

        m[s[i]]++;

        if(m.size() == i-j+1 ){

            ans=max(ans,i-j+1);

        }
        else if(m.size()<i-j+1){// condition changed from k unique char's code

            while(m.size()<i-j+1){// condition changed from k unique char's code
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

//--------------my own code------------------


// #include<bits/stdc++.h>
// using namespace std;
// int main(){

//     string s;
//     cin>>s;
    

//     set<char> st;
//     int ans=INT_MIN;
//     int i=0;
//     int j=0;

//     while(i<s.size()){

//         if(st.find(s[i]) ==st.end() ){
//             st.insert(s[i]);
//         }
//         else{

//             ans=max(ans,i-j);
//             st.clear();
//             st.insert(s[i]);
//             j=i;

//         }
//         i++;
//     }
    
//     ans=max(ans,i-j);

//     cout<<ans;

//     return 0;
// }