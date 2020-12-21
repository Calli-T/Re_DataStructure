#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node* chain;
struct node {
	int data;
	struct node* link;
};
bool visited[8] = { false };

struct Queue {
	int vertex;
	struct Queue* link;
};
struct Queue* front = NULL, * rear = NULL;
int szQ = 0;

void addQ(int item) {

	struct Queue* temp = (struct Queue*)malloc(sizeof(struct Queue));
	if (temp == NULL) {
		fprintf(stderr, "The memory is full\n");
		exit(1);
	}

	temp->vertex = item;
	temp->link = NULL;
	if (front)rear->link = temp;
	else front = temp;
	rear = temp;

	szQ++;

}
int deleteQ() {
	struct Queue* temp = front;
	int item;
	if (temp == NULL) {
		fprintf(stderr, "The queue is empty\n");
		exit(1);
	}

	if (szQ != 0)
		szQ--;

	item = temp->vertex;
	front = temp->link;
	free(temp);
	return item;
}

chain* graph;

void dfs(int v) {

	chain w;
	visited[v] = true;
	printf("%5d", v);
	for (w = graph[v]; w; w = w->link)
		if (!visited[w->data]) dfs(w->data);

}

void bfs(int v) {

	chain w;
	printf("%5d", v);
	visited[v] = true;
	addQ(v);

	while (front) {
		
		v = deleteQ();

		for (w = graph[v]; w; w = w->link) {
			
			if (!visited[w->data]) {
				printf("%5d", w->data);
				addQ(w->data);
				visited[w->data] = true;
			}

		}

	}
	
}

chain makeChain() {

	chain temp = (struct node*)malloc(sizeof(struct node));

	temp->data = 0;
	temp->link = NULL;

	return temp;

}

void makeList(chain head, int list[], int size) {

	chain now = head;

	for (int i = 0; i < size; i++) {

		chain temp = makeChain();

		//printf("%d ", list[i]);

		now->data = list[i];
		now->link = temp;

		now = temp;

	}
	//printf("\n");

}

int main() {

	int size[8] = { 3,4,4,3,3,3,3,5 };

	graph = (chain*)malloc(sizeof(chain) * 8);
	for (int i = 0; i < 8; i++)
		graph[i] = (chain)malloc(sizeof(struct node));

	int list[8][5] = { 0 };
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < size[i]; j++) {
			scanf_s("%d", &list[i][j]);
		}
	}

	for (int i = 0; i < 8; i++) {
		makeList(graph[i], list[i], size[i]);
	}

	/*for (int i = 0; i < 8; i++) {

		chain now = graph[i];
		while (true) {

			printf("%d ", now->data);
			now = now->link;

			if (now->link == NULL) break;
		}
		printf("\n");

	}*/


	//dfs(5);
	bfs(0);

	return 0;
}

/*
0 1 2
1 0 3 4
2 0 5 6
3 1 7
4 1 7
5 2 7
6 2 7
7 3 4 5 6
*/