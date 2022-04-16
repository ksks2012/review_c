#include "./lib/cheader.h"


BinaryTreeNode* ConstructCore(int *preorder_start, int *preorder_end, int *inorder_start, int *inorder_end) {
	int root_value = preorder_start[0];
	BinaryTreeNode *root = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
	root->value = root_value;
	root->left = root->right = NULL;

	if(preorder_start == preorder_end) {
		if(inorder_start == inorder_end && *preorder_start == *inorder_start) {
			return root;
		}
		else
			return NULL;
	}

	int *inorder_root = inorder_start;
	while (inorder_root <= inorder_end && *inorder_root != root_value) {
		++inorder_root;
	}

	if(inorder_root == inorder_end && *inorder_root != root_value) {
		return NULL;
	}

	int left_len = inorder_root - inorder_start;
	int *left_preorder_end = preorder_start + left_len;
	if(left_len > 0) {
		root->left = ConstructCore(preorder_start + 1, left_preorder_end, inorder_start, inorder_root - 1);
	}
	if (left_len < preorder_end - preorder_start) {
		root->right = ConstructCore(left_preorder_end + 1, preorder_end, inorder_root + 1, inorder_end);
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
