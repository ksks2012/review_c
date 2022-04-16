#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

typedef struct BinaryTreeNode
{
	void * value;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BinaryTreeNode;

void print_preorder_tree(BinaryTreeNode *);
void print_inorder_tree(BinaryTreeNode *);
void print_postorder_tree(BinaryTreeNode *);
void BFS(BinaryTreeNode *);
void DFS(BinaryTreeNode *);

#endif
