#include <bits/stdc++.h>
using namespace std;
int main()
{

    stack<int> s;
    s.push(3);
    s.push(4);
    s.push(5);
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();

    return 0;
}
