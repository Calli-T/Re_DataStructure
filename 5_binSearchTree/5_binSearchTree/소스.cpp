#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node* tree_pointer;
struct node {
	int data;
	tree_pointer left_child;
	tree_pointer right_child;
};

tree_pointer search(tree_pointer root, int key) {
	if (!root)return NULL;
	if (key == root->data) return root;
	if (key < root->data)
		return search(root->left_child, key);
	return search(root->right_child, key);
}

tree_pointer iterSearch(tree_pointer tree, int key) {

	while (tree != NULL) {
		if (key == tree->data) return tree;
		if (key < tree->data)
			tree = tree->left_child;
		else
			tree = tree->right_child;
	}

	return NULL;
}

tree_pointer modified_search(tree_pointer root, int key) {

	for (tree_pointer ptr = root; ptr != NULL;) {
		if (ptr->data == key)
			return NULL;
		if (key < ptr->data) {
			if (ptr->left_child == NULL)return ptr;
			else ptr = ptr->left_child;
		}
		else {
			if (ptr->right_child == NULL)return ptr;
			else ptr = ptr->right_child;
		}
	}
	return NULL;
}

void insert_node(tree_pointer* root, int num) {
	tree_pointer ptr, parent = modified_search(*root, num);

	if (parent || !(*root)) {
		ptr = (tree_pointer)malloc(sizeof(struct node));
		ptr->data = num;
		ptr->left_child = ptr->right_child = NULL;

		if (*root)
			if (num < parent->data)
				parent->left_child = ptr;
			else
				parent->right_child = ptr;
		else *root = ptr;
	}
}

void inorder(tree_pointer ptr) {
	if (ptr) {
		inorder(ptr->left_child);
		printf("%d ", ptr->data);
		inorder(ptr->right_child);
	}
}

void delete_node(tree_pointer* root, int key) {

	/*tree_pointer tp = iterSearch(*root, num);
	if (!tp) {
		fprintf(stderr, "There's no key");
		exit(1);
	}*/

	tree_pointer parent, temp;
	parent = NULL;
	temp = *root;

	while (temp != NULL) {
		if (key == temp->data) {
			//return temp;
			break;
		}
		else if (key < temp->data) {
			parent = temp;
			temp = temp->left_child;
		}
		else {
			parent = temp;
			temp = temp->right_child;
		}
	}

	if (!temp) exit(1);


	if (!temp->left_child && !temp->right_child) { //단말노드

		if (!parent) {
			*root = NULL;
		}
		else {
			if (parent->right_child == temp) {
				parent->right_child = NULL;
				free(parent->right_child);
			}
			else {
				parent->left_child = NULL;
				free(parent->left_child);
			}
		}

	}
	else if (!(temp->left_child && !temp->right_child)) { //child 하나

		tree_pointer child = (temp->left_child) ? temp->left_child : temp->right_child;

		if (!parent) {
			*root = child;
		}
		else {
			if (parent->left_child == temp)
				parent->left_child = child;
			else
				parent->right_child = child;
		}

	}
	else { //child 둘

	}
	free(temp);

}

int main() {

	//트리포인터를 담는 트리포인터
	tree_pointer* root = (tree_pointer*)malloc(sizeof(tree_pointer));
	*root = NULL;

	insert_node(root, 30);
	insert_node(root, 5);
	insert_node(root, 40);
	insert_node(root, 1000);
	insert_node(root, 90);

	//printf("%d\n", (*root)->data);

	tree_pointer tp = iterSearch(*root, 1000);
	if (tp)
		printf("%d\n", tp->data);

	inorder(*root);


	return 0;

}