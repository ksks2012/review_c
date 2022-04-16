#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"
#include "queue.h"

void print_preorder_tree(BinaryTreeNode *root) {
	if(root == NULL)
		return;
	printf("%d, ", root->value);
	print_preorder_tree(root->left);
	print_preorder_tree(root->right);
}

void print_inorder_tree(BinaryTreeNode *root) {
	if(root == NULL)
		return;
	print_inorder_tree(root->left);
	printf("%d, ", root->value);
	print_inorder_tree(root->right);
}

void print_postorder_tree(BinaryTreeNode *root) {
	if(root == NULL)
		return;
	print_postorder_tree(root->left);
	print_postorder_tree(root->right);
	printf("%d, ", root->value);
}

void BFS(BinaryTreeNode *root) {

	if(root == NULL)
		return;
	Queue *q = queue_new();

	queue_enqueue(q, root);
	while(!queue_is_empty(q)) {
		int size = q->size;
		for(int i = 0; i < size; i++) {
			BinaryTreeNode *top = queue_dequeue(q);
			printf("%d, ", (int *)(top->value));
			if(top->left != NULL)
				queue_enqueue(q, top->left);
			if(top->right != NULL)
				queue_enqueue(q, top->right);
		}
	}

}

void DFS(BinaryTreeNode *root) {
	if(root == NULL)
		return;
}
