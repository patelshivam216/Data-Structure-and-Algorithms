#include <bits/stdc++.h>
using namespace std;
int main()
{

    int a[] = {4, 5, 6, 7, 0, 1, 2};
    int x = 0;
    int n = 7;
    int start = 0;
    int end = n - 1;
    int idx = 0;

    while (start < end)
    {
        int mid = (start + end) / 2;

        int next = (mid + 1) % n;
        int pre = (mid - 1 + n) % n;

        if (a[mid] <= a[next] and a[mid] <= a[pre])
        {
            idx = mid + 1;
            break;
        }
        else if (a[start] <= a[mid])
        {
            start = mid + 1;
        }
        else if (a[mid] <= a[end])
        {
            end = mid - 1;
        }
    }

    bool flag = false;

    start = 0;
    end = idx - 1;

    while (start < end)
    {
        int mid = (start + end) / 2;
        if (a[mid] == x)
        {
            flag = true;
            cout << mid;
            break;
        }
        else if (x < a[mid])
        {
            end = mid - 1;
        }
        else if (x > a[mid])
        {
            start = mid + 1;
        }
    }

    if (!flag)
    {
        start = idx;
        end = n - 1;

        while (start < end)
        {
            int mid = (start + end) / 2;

            if (a[mid] == x)
            {

                cout << mid;
                break;
            }
            else if (x < a[mid])
            {
                end = mid - 1;
            }
            else if (x > a[mid])
            {
                start = mid + 1;
            }
        }
    }

    * /

        return 0;
}