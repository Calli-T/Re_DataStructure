#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node* tree_pointer;
struct node {
	int data;
	tree_pointer left_child;
	tree_pointer right_child;
};

tree_pointer makeNode() {

	tree_pointer temp = (struct node*)malloc(sizeof(struct node));
	//temp->data = 0;
	temp->right_child = 0;
	temp->left_child = 0;

	return temp;

}

tree_pointer genBinTree(tree_pointer root, int num) {

	//노드없는 트리
	if (num == 0) {
		root = NULL;
		return root;
	}
	tree_pointer* tempArr = (tree_pointer*)malloc(sizeof(tree_pointer) * (num + 1));
	for (int i = 1; i <= num; i++) {
		tempArr[i] = makeNode;
	}
	
}