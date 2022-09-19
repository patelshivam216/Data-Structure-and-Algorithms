#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>

class Node
{
private:
    Node *links[2];

public:
    bool iscontainKey(int bit)
    {
        if (links[bit] == NULL)
        {
            return false;
        }

        return true;
    }

    Node *get(int bit)
    {
        return links[bit];
    }

    void put(int bit, Node *node)
    {
        links[bit] = node;
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(int num)
    {
        Node *node = root;
        for (int i = 31; i >= 0; --i)
        {
            int bit = ((1 << i) & num);

            if (node->iscontainKey(bit) == false)
            {
                node->put(bit, new Node());
            }

            node = node->get(bit);
        }
    }

    int getMax(int num)
    {
        int maxi = 0;
        Node *node = root;
        for (int i = 31; i >= 0; i -= 1)
        {
            int bit = ((1 << i) & num);

            if (node->iscontainKey(!bit))
            {

                maxi = (maxi | (1 << i));
                node->get(!bit);
            }
            else
            {
                node = node->get(bit);
            }
        }

        return maxi;
    }
};

int main()
{

    int n, m;
    cin >> n >> m;

    vi a1(n);
    vi a2(m);
    Trie ob;
    int maxi = -1e9;

    for (int i = 0; i < n; i++)
    {
        cin >> a1[i];
        ob.insert(a1[i]);
    }

    for (int j = 0; j < m; j++)
    {
        cin >> a2[j];
        maxi = max(maxi, ob.getMax(a2[j]));
    }

    cout << maxi << endl;

    return 0;
}

/*

incomplete - find bug

7 7
6 6 0 6 8 5 6
1 7 1 7 8 0 2


*/