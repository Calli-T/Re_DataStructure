#include <stdio.h>
#include <stdlib.h>

typedef struct node* tree_pointer;
struct node {
	char data;
	struct node* left_child;
	struct node* right_child;
};

tree_pointer makeNode() {

	tree_pointer temp = (struct node*)malloc(sizeof(struct node));
	temp->data = '\0';
	temp->right_child = 0;
	temp->left_child = 0;

	return temp;

}

void setNode(tree_pointer node, char value, tree_pointer left, tree_pointer right) {

	node->data = value;
	node->left_child = left;
	node->right_child = right;

}

void inorder(tree_pointer ptr) {
	if (ptr) {
		inorder(ptr->left_child);
		printf("%c ", ptr->data);
		inorder(ptr->right_child);
	}
}

tree_pointer copy(tree_pointer root) {
	tree_pointer temp;
	if (root) {
		temp = (tree_pointer)malloc(sizeof(struct node));
		temp->left_child = copy(root->left_child);
		temp->right_child = copy(root->right_child);
		temp->data = root->data;

		return temp;
	}

	return NULL;
}

//-------------------------------------------------------------//

int main() {

	tree_pointer arr[9];
	tree_pointer copyTree = NULL;
	for (int i = 0; i < 9; i++)
		arr[i] = makeNode();

	setNode(arr[0], '+', arr[1], arr[2]);
	setNode(arr[1], '*', arr[3], arr[4]);
	setNode(arr[2], 'E', NULL, NULL);
	setNode(arr[3], '*', arr[5], arr[6]);
	setNode(arr[4], 'D', NULL, NULL);
	setNode(arr[5], '/', arr[7], arr[8]);
	setNode(arr[6], 'C', NULL, NULL);
	setNode(arr[7], 'A', NULL, NULL);
	setNode(arr[8], 'B', NULL, NULL);

	printf("original: ");
	inorder(arr[0]);
	printf("\n");

	copyTree = copy(arr[0]);

	printf("copiedTree: ");
	inorder(copyTree);
	printf("\n");


	return 0;

}