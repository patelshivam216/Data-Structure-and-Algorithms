#include<bits/stdc++.h>
using namespace std;

// first finding the count of nodes 
void find_count(Node *root, int &c)
{
    if (root == NULL)
    {
        return;
    }
    find_count(root->left, c);
    c += 1;
    find_count(root->right, c);
}

// then find out first and second element , which are needed for even and odd length
void find_M(Node *root, int &count, int &first, int &second)
{
    if (!root)
        return;

    find_M(root->left, count, first, second);

    if (count == 1)
        first = root->data;
    else if (count == 0) // second is for odd nodes's count
        second = root->data;

    count -= 1;

    find_M(root->right, count, first, second);
}

float findMedian(struct Node *root)
{
    int nodes = 0;
    find_count(root, nodes);

    int temp1 = nodes / 2;
    int first = 0;
    int second = 0;

    find_M(root, temp1, first, second);

    if (nodes % 2) // if nodes are odd then 
        return second;
    else // if nodes are even then
        return (first + second) / 2.0;
}