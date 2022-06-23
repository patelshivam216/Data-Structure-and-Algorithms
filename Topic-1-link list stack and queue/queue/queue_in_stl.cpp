#include <bits/stdc++.h>
using namespace std;
int main()
{

    queue<int> s;
    s.push(3);
    s.push(4);
    s.push(5);
    cout<<s.front()<<endl;
    s.pop();
    cout<<s.front()<<endl;
    s.pop();
    cout<<s.front()<<endl;
    s.pop();

    return 0;
}

