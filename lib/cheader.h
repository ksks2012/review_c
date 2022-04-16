#ifndef __CHEADER_H__
#define __CHEADER_H__

#include <stdio.h>
#include <stdlib.h>
#include "list_node.h"
#include "queue.h"


typedef struct BinaryTreeNode
{
	void * value;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BinaryTreeNode;

void print_preorder_tree(BinaryTreeNode *root) {
	if(root == NULL)
		return;
}

void print_inorder_tree(BinaryTreeNode *root) {
	if(root == NULL)
		return;
}

void print_postorder_tree(BinaryTreeNode *root) {
	if(root == NULL)
		return;
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

#endif
