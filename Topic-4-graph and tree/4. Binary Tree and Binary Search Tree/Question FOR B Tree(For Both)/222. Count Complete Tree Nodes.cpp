#include<bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
int leftheight(TreeNode* root){
    int height = 0;
    TreeNode* node = root;
    while(node){
        height += 1;
        node = node->left;
    }
    return height;
}
int rightheight(TreeNode* root){
    int height = 0;
    TreeNode* node = root;
    while(node){
        height += 1;
        node = node->right;
    }
    return height;
}

int countNodes_(TreeNode* root){
    if(root == NULL) return 0;
    
    int lh = leftheight(root);
    int rh = rightheight(root);
    
    if(lh == rh){
        return (1<<lh)-1;
    }
    
    return 1 + countNodes_(root->right) + countNodes_(root->left);
}
class Solution {
public:
    int countNodes(TreeNode* root) {
        return countNodes_(root);
    }
};