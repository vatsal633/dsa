#include<iostream>
#include<vector>
using namespace std;

static int idx = -1;
int count=0;

class node{
public:
    int data;
    node *left;
    node *right;

    node(int val){
        data = val;
        left = right = NULL;
    }
};

node *buildTree(vector<int> preorder){
    idx++;

    if(preorder[idx]==-1) return NULL;
    
    node *root = new node(preorder[idx]);

    root->left = buildTree(preorder);
    root->right = buildTree(preorder);

    return root;

}


// 3 recursion algo for travling binary trees 
// 1.preoder - trvale by this logic {root,left,right}

// 2.inorder - 
// 3.postorder

// iterative
// level order triversal


void preOrder(node *root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<endl;
    count++;
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(node *root){
    if(root==NULL) return;

    inOrder(root->left);
    cout<<root->data;   
    inOrder(root->right);
}

void postOrder(node *root){
    if(root==NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data; 
}

int sum (node *root){
    if (root==NULL)
    {
        return 0;
    }
    
    int left = sum(root->left);
    int right = sum(root->right);


    return left+right+root->data;
}

// subtree question 
// 1.finding subroot in main tree
// 2.if found we check that it is identical or not(call identical function)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// bool isIdentical(struct TreeNode *p,struct TreeNode *q){
//     if(p==NULL || q==NULL){
//         return p==q;
//     }

//     return p->val == q->val 
//     && isIdentical(p->left,q->left) 
//     && isIdentical(p->right,q->right);
// }

// bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
//     if(root==NULL || subRoot==NULL){
//         return root==subRoot;
//     }

//     if(root->val==subRoot->val && isIdentical(root,subRoot)){
//         return true;
//     }

//     return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
// }





int main(){
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    

    return 0;
}   