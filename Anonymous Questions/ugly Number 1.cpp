class Solution {
public:
    int fun(int n, int x)
    {
        while(n % x == 0)
            n /= x;
        return n;
    }
    bool isUgly(int n) {
        if(n <= 0)
            return false;
        n = fun(n, 2);
        n = fun(n, 3);
        n = fun(n, 5);
        return n == 1;
    }
};