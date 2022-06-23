#include <bits/stdc++.h>
using namespace std;
class Node
{

public:
    int data;
    Node *left;
    Node *right;
    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

void inorder(Node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

string serialize(Node *root)
{
    // here we use level traversal
    // add all nodes in queue if its null or not
    // if find null from queue then add # to string
    // if find node without NULL then append it to string
    string s = "";
    if (root == NULL)
    {
        return s;
    }

    queue<Node *> q;
    q.push(root);

    s.append(to_string(root->data));

    while (q.size() > 0)
    {
        int size = q.size();

        for (int i = 0; i < size; i++)
        {
            auto node = q.front();
            q.pop();
            if (node->left)
            {
                s.append("," + to_string(node->left->data));
                q.push(node->left);
            }
            else
                s.append(",#");

            if (node->right)
            {
                s.append("," + to_string(node->right->data));
                q.push(node->right);
            }
            else
                s.append(",#");
        }
    }
    return s;
}

Node *deserialize(string s)
{
    if (s.size() == 0)
        return NULL;

    queue<char> q; // strong character of string input
    for (auto ch : s)
    {
        if (ch == ',')
            continue;
        q.push(ch);
    }

    Node *root = new Node(q.front() - '0');
    q.pop();

    queue<Node *> qt; // stroring nodes
    qt.push(root);

    while (q.size() > 0)
    {

        auto node = qt.front();
        qt.pop();

        auto ch = q.front(); // first char input data
        q.pop();

        if (ch == '#')
        {
            node->left = NULL;
        }
        else
        {
            node->left = new Node(ch - '0');
            qt.push(node->left);
        }

        ch = q.front();
        q.pop();

        if (ch == '#')
        {
            node->right = NULL;
        }
        else
        {
            node->right = new Node(ch - '0');
            qt.push(node->right);
        }
    }

    return root;
}

int main()
{

    Node *root = new Node(1);
    root->left = new Node(2);
    // root->right=new Node(3);
    // root->left->left=new Node(4);
    root->left->right = new Node(3);
    root->left->right->left = new Node(4);
    root->left->right->right = new Node(5);

    inorder(root);
    string s = serialize(root);
    root = deserialize(s);
    cout << endl;
    inorder(root);

    return 0;
}