#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"
#include "queue.h"
#include "stack.h"

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
			BinaryTreeNode *front = queue_dequeue(q);
			printf("%d, ", (int *)(front->value));
			if(front->left != NULL)
				queue_enqueue(q, front->left);
			if(front->right != NULL)
				queue_enqueue(q, front->right);
		}
	}
	printf("\n");
	queue_delete(q);
}

void DFS(BinaryTreeNode *root) {
	if(root == NULL)
		return;
	Stack *s = stack_new();

	stack_push(s, root);
	while(!stack_is_empty(s)) {
		BinaryTreeNode *top = stack_pop(s);
		if(top->right != NULL)
			stack_push(s, top->right);
		if(top->left != NULL)
			stack_push(s, top->left);
		printf("%d, ", (int *)(top->value));
	}
	printf("\n");
	stack_delete(s);
}
