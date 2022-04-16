#include "./lib/cheader.h"


BinaryTreeNode* ConstructCore(int *preorderStart, int *preorderEnd, int *inorderStart, int *inorderEnd) {
	int root_value = preorderStart[0];
	BinaryTreeNode *root = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
	root->value = root_value;
	root->left = root->right = NULL;

	if(preorderStart == preorderEnd) {
		if(inorderStart == inorderEnd && *preorderStart == *inorderStart) {
			return root;
		}
		else
			return NULL;
	}

	int *inorder_root = inorderStart;
	while (inorder_root <= inorderEnd && *inorder_root != root_value) {
		++inorder_root;
	}

	if(inorder_root == inorderEnd && *inorder_root != root_value) {
		return NULL;
	}

	int left_len = inorder_root - inorderStart;
	int *left_preorder_end = preorderStart + left_len;
	if(left_len > 0) {
		root->left = ConstructCore(preorderStart + 1, left_preorder_end, inorderStart, inorder_root - 1);
	}
	if (left_len < preorderEnd - preorderStart) {
		root->right = ConstructCore(left_preorder_end + 1, preorderEnd, inorder_root + 1, inorderEnd);
	}

	return root;
}

BinaryTreeNode * Construct(int *preorder, int *inorder, int length) {
	if(preorder == NULL || inorder == NULL || length <= 0)
		return NULL;

	return ConstructCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
}

int main() {
	int preorder_list[8] = {1, 2, 4, 7, 3, 5, 6, 8};
	int inorder_list[8] = {4, 7, 2, 1, 5, 3, 8, 6};

	BinaryTreeNode *tree = Construct(preorder_list, inorder_list, 8);
	print_preorder_tree(tree);
	printf("\n");
	print_inorder_tree(tree);
	printf("\n");
	print_postorder_tree(tree);
}
