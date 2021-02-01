#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge {
	int vertexA;
	int vertexB;
	int weight;
};

struct cmp {
	bool operator()(Edge& a, Edge& b) {
		return a.weight > b.weight;
	}
};

int simpleFind(int i, vector<int>& parent) {
	for (; parent[i] >= 0; i = parent[i]);
	return i;
}
void simpleUnion(int i, int j, vector<int>& parent) {
	parent[i] = j;
}

void weightedUnion(int i, int j, vector<int>& parent) {
	int temp = parent[i] + parent[j];
	if (parent[i] > parent[j]) {
		parent[i] = j;
		parent[j] = temp;
	}
	else {
		parent[j] = i;
		parent[i] = temp;
	}
}

int collapsingFind(int i, vector<int>& parent) {
	int root, trail, lead;
	for (root = i; parent[root] >= 0; root = parent[root]);
	for (trail = i; trail != root; trail = lead) {
		lead = parent[trail];
		parent[trail] = root;
	}
	return root;
}

vector<Edge> kruskal(priority_queue<Edge, vector<Edge>, cmp>& Q, int vertex) {

	/*cout << "\n";
	auto copyQ = Q;
	while (!copyQ.empty()) {
		auto now = copyQ.top();
		copyQ.pop();
		cout << now.vertexA << " " << now.vertexB << " " << now.weight << endl;
	}
	cout << endl;*/

	vector<int> parent(Q.size(), -1);
	vector<Edge> ans;

	//일단 하나 집어넣는다
	ans.push_back(Q.top());
	weightedUnion(Q.top().vertexB, Q.top().vertexA, parent);
	Q.pop();

	//간선이 정점의 갯수 - 1개 만큼 차거나, 차지 않더라도 모든 간선을 사용하면 종료
	while (ans.size() <= vertex - 1 && !Q.empty()) {
		auto now = Q.top();
		Q.pop();

		int tempRootA = collapsingFind(now.vertexA, parent);
		int tempRootB = collapsingFind(now.vertexB, parent);

		//간선의 양끝의 root가 다를 때 추가하며, 번호가 적은쪽이 root가 된다
		if (tempRootA != tempRootB) {
			ans.push_back(now);

			if (tempRootA < tempRootB) {
				weightedUnion(tempRootB, tempRootA, parent);
			}
			else {
				weightedUnion(tempRootA, tempRootB, parent);
			}
			//union을 어디다가 넣을것인가?
		}

		/*for (int j = 0; j < parent.size(); j++)
			cout << parent[j] << " ";
		cout << endl;*/

	}

	return ans;
}

int main() {

	int vertex, edge;
	cin >> vertex >> edge;
	priority_queue<Edge, vector<Edge>, cmp> Q;

	int a, b, c;
	Edge temp;
	for (int i = 0; i < edge; i++) {
		cin >> a >> b >> c;
		if (a < b) {
			temp.vertexA = a;
			temp.vertexB = b;
		}
		else {
			temp.vertexA = b;
			temp.vertexB = a;
		}
		temp.weight = c;
		Q.push(temp);
	}

	cout << endl;
	vector<Edge> ans = kruskal(Q, vertex);
	for (auto it = ans.begin(); it != ans.end(); it++) {
		cout << it->vertexA << " " << it->vertexB << " " << it->weight << endl;
	}

	return 0;

}

/*
7 9
0 1 28
1 2 16
2 3 12
3 4 22
4 5 25
5 0 10
1 6 14
6 4 24
3 6 17
*/

/*
7 11
0 2 10
2 5 2
0 1 5
2 1 7
2 3 12
3 5 11
5 6 14
1 3 6
3 6 15
1 4 9
4 6 3
*/