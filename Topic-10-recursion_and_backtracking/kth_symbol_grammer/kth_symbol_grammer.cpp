#include<bits/stdc++.h>
using namespace std;
int symbol(int N,int K){
    if(N==1 && K==1){
        return 0;
    }

    int mid = pow(2,N-1)/2;
    if(K<=mid){
        return symbol(N-1,K);
    }else
        return !symbol(N-1,K-mid);

}
/*
N=1 0
N=2 0  1
N=3 0  1  1  0
N=4 0  1  1  0  1  0  0  1
k-> k1 k2 k3 k4 k5 k6 k7 k8

*/
int main(){
    int N,K;
    cin>>N>>K;

    cout<<symbol(N,K);

    return 0;
}