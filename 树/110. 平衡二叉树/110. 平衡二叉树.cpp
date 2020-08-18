
struct ReturnNode {
	int depth;
	bool balance;
	ReturnNode(int x, bool y) : depth(x), balance(y) {}
};


class Solution {
public:
	bool isBalanced(TreeNode* root) {
		return isBST(root).balance;
	}
	ReturnNode isBST(TreeNode* root) {
		if (root == NULL) {
			return ReturnNode(0, true);
		}
		ReturnNode left = isBST(root->left);
		ReturnNode right = isBST(root->right);

		if (left.balance==false || right.balance == false) {
			return ReturnNode(0, false);
		}
		if (abs(left.depth - right.depth) > 1) {
			return ReturnNode(0, false);
		}
		return ReturnNode(max(left.depth, right.depth) + 1, true);
	}
};