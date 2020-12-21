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

//-------------------------------------------------------------//

void stackEmpty() {
	//printf("스택이 비었습니다\n");
}
void stackFull() {
	printf("스택이 가득차있습니다\n");
}

int top = -1;
int max_size = 1000;
tree_pointer* element1;
void push(tree_pointer item) {
	if (top >= max_size - 1) { //꽉찼나 확인
		stackFull();
	}
	else {
		element1[++top] = item;
	}
}
tree_pointer pop() {
	if (top == -1) {
		stackEmpty();
		exit(1);
	}
	else {
		return element1[top--];
	}
}

tree_pointer Top(void) {
	return element1[top];
}

//-------------------------------------------------------------//

typedef struct {
	tree_pointer key;
} element;
struct Queue {
	element data;
	struct Queue* link;
};
struct Queue* front, * rear;
int sizeofQ = 0;

void addQ(element item) {
	struct Queue* temp = (struct Queue*)malloc(sizeof(struct Queue));
	if (temp == NULL) {
		fprintf(stderr, "The memory is full\n");
		exit(1);
	}

	temp->data = item;
	temp->link = NULL;
	if (front)rear->link = temp;
	else front = temp;
	rear = temp;

	sizeofQ++;

}

element deleteQ() {
	struct Queue* temp = front;
	element item;
	if (temp == NULL) {
		fprintf(stderr, "The queue is empty\n");
		exit(1);
	}

	if (sizeofQ != 0)
		sizeofQ--;

	item = temp->data;
	front = temp->link;
	free(temp);
	return item;
}
bool isEmptyQ() {
	if (front == NULL) return true;
	return false;
}

//-------------------------------------------------------------//

void inorder(tree_pointer ptr) {
	if (ptr) {
		inorder(ptr->left_child);
		printf("%c ", ptr->data);
		inorder(ptr->right_child);
	}
}

void preorder(tree_pointer ptr) {
	if (ptr) {
		printf("%c ", ptr->data);
		preorder(ptr->left_child);
		preorder(ptr->right_child);
	}
}

void postorder(tree_pointer ptr) {
	if (ptr) {
		postorder(ptr->left_child);
		postorder(ptr->right_child);
		printf("%c ", ptr->data);
	}
}

void iterInorder(tree_pointer node) {

	for (;;) {
		for (; node; node = node->left_child)
			push(node);
		node = pop();
		if (!node) break;
		printf("%c ", node->data);
		node = node->right_child;
	}

}

//-------------------------------------------------------------//

//-------------------------------------------------------------//

int main() {

	tree_pointer arr[9];
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

	printf("inorder: ");
	inorder(arr[0]);
	printf("\n");

	printf("preorder: ");
	preorder(arr[0]);
	printf("\n");

	printf("postorder: ");
	postorder(arr[0]);
	printf("\n");

	element1 = (tree_pointer*)malloc(sizeof(tree_pointer) * max_size);
	printf("iterInorder: ");
	iterInorder(arr[0]);
	printf("\n");
	

	return 0;

}