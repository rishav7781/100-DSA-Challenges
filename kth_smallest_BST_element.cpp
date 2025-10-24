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
class Solution {
public:
    int preorder=0;
    int kthSmallest(TreeNode* root, int k) {
       if(root==NULL) return -1;

       //inorder
       int leftAns,rightAns;

        //left
        if(root->left !=NULL){
            leftAns=kthSmallest(root->left,k);

            if(leftAns!=-1){
               return leftAns; 
            }
        }
            //root

            if(preorder+1==k){
                return root->val;
            }
            preorder++;

            //right
            if(root->right !=NULL){
            rightAns=kthSmallest(root->right,k);

            if(rightAns!=-1){
               return rightAns; 
            }
       
        }
         return -1;
    }
};