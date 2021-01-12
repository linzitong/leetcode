//给定一个二叉树，判断它是否是高度平衡的二叉树。
//本题中，一棵高度平衡二叉树定义为：
//一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。
//思路：使用递归的方式，给出每个节点的高度，当前节点的高度为子节点中最高的+1.当子节点中有节点不平衡，或者当前节点的子节点左右相差超过1的时候，就不平衡。
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
	int height(TreeNode* root){
		if(root==NULL){
    		return 0;
		}
		int x=height(root->left);
		int y=height(root->right);
		if(x==-1||y==-1||abs(x-y)>1){
			return -1;
		}
		return max(x,y)+1;
	}
    bool isBalanced(TreeNode* root) {
		if(height(root)==-1){
			return false;
		}else{
			return true;
		}
		
    }
};
