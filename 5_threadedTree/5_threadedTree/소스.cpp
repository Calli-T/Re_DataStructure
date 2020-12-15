#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct thread_tree* ttp;//threaded tree pointer
struct thread_tree {
	bool left_thread;
	ttp left_child;

	char data;
	ttp right_child;
	bool right_thread;
};

struct thread_tree* insucc(ttp ptr) {
	
	ttp temp = ptr->right_child;

	if (!ptr->right_thread)
		while (!temp->left_child)
			temp = temp->left_child;

	return temp;

}

void inorderT(ttp tree) {
	
	ttp temp = tree;

	for (;;) {
		temp = insucc(temp);
		if (temp == tree) break;
		printf("%3c", temp->data);
	}

}

//----------------------------------------------------------------------//

ttp makeNode() {

	ttp temp = (ttp)malloc(sizeof(struct thread_tree));

	temp->data = '\0';
	temp->right_child = 0;
	temp->left_child = 0;
	temp->left_thread = false;
	temp->right_thread = false;

	return temp;

}

//----------------------------------------------------------------------//

int main() {

	return 0;

}