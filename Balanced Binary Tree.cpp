// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};



class Solution {
public:
bool valid=true;
int maxDepth(TreeNode *root) {
    // int localDepth = 0;
    if (!root) return 0;
    int l=0,r=0;
    if(root->right!=nullptr) r=maxDepth(root->right); 
    if(root->left!=nullptr) l=maxDepth(root->left);
    if(abs(r-l)>1) valid=false;
    return 1+max(l,r);
  }

  bool isBalanced(TreeNode *root) {
    maxDepth(root);
    return valid;
  }
};