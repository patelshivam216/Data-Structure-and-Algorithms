#include <bits/stdc++.h>
using namespace std;

/*

--> in the array value could be more then one time so to deal with that
--> let say our sequance is : 13 11 3 6 11 , 11 is our root and to find it's 
--> greater we have to more right so we do some change on it 
--> after moving right if we have something greater then that could be our ans 

*/
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

Node *insert(Node *root, int value, Node *&suc)
{
    if (root == NULL)
    {
        return root = new Node(value);
    }

    if (value < root->data)
    {
        suc = root;
        root->left = insert(root->left, value, suc);
    }
    if (value >= root->data) // Here we less than and equal, is nessasary
    {
        root->right = insert(root->right, value, suc);
    }

    return root;
}

class Solution
{
public:
    vector<int> findLeastGreater(vector<int> &arr, int n)
    {
        vector<int> ans(n, 0);
        Node *root = NULL;
        for (int i = n - 1; i >= 0; --i)
        {
            Node *suc = NULL;
            root = insert(root, arr[i], suc);

            if (suc == NULL)
            {
                ans[i] = -1;
            }
            else
                ans[i] = suc->data;
        }

        return ans;
    }
};