#include <vector>
#include <iostream>
#include <queue>

#define INF 100000000

using namespace std;

struct Edge {
	int end;
	int distance;
};

struct tempValue {
	int destination;
	int totalDistance;
};

struct cmp {
	bool operator()(tempValue& a, tempValue& b) {
		return a.totalDistance > b.totalDistance;
	}
};

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int V, E, start;
	int a, b, c; //출발지, 목적지, 가중치를 담을 임시변수
	Edge temp;//b, c를 담는 변수
	cin >> V >> E >> start;
	vector<vector<Edge>> graph(V + 1);
	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		temp.end = b;
		temp.distance = c;
		graph[a].push_back(temp);
	}
	priority_queue<tempValue, vector<tempValue>, cmp> Q;
	vector<int> distance(V + 1, INF);
	distance[start] = 0;

	/*
	cout << endl;
	for (int i = 0; i < graph.size(); i++) {
		for (int j = 0; j < graph[i].size(); j++) {
			cout << i << " " << graph[i][j].end << " " << graph[i][j].distance << endl;
		}
	}
	*/

	tempValue first;
	first.destination = start;
	first.totalDistance = distance[start];
	Q.push(first);
	int cur, curDist;

	while (!Q.empty()) {
		auto now = Q.top();
		Q.pop();
		cur = now.destination;
		curDist = now.totalDistance;

		if (now.totalDistance > distance[now.destination]) continue;

		for (int i = 0; i < graph[cur].size(); i++) {

			//cout << graph[cur][i].end << endl;
			if (graph[cur][i].distance + curDist < distance[graph[cur][i].end]) {
				distance[graph[cur][i].end] = graph[cur][i].distance + curDist;
				first.destination = graph[cur][i].end;
				first.totalDistance = distance[graph[cur][i].end];
				Q.push(first);
			}

		}

	}

	for (int i = 1; i <= V; i++) {
		if (distance[i] != INF)
			cout << distance[i] << '\n';
		else
			cout << "INF" << '\n';
	}
	cout << endl;

	return 0;

}

/*
5 6
1
5 1 1
1 2 2
1 3 3
2 3 4
2 4 5
3 4 6
*/

/*#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <iterator>

using namespace std;

#define Edge pair<int, int>
#define PAIR pair<int, int>
#define DT first		//destination
#define WT second		//weight
#define INF 3000000		//최대거리보다 큰 값, 무한대와 비슷하게 사용

struct cmp {
	bool operator()(Edge& a, Edge& b) {
		return a.second > b.second;
	}
};

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);





	int V, E;
	cin >> V >> E;

	vector<int> dist(V + 1);		//아래블럭은 dist를 시작위치말고 싹 INF로고정해준다
	int start = 0;
	cin >> start;
	for (int i = 1; i <= V; i++)
		dist[i] = INF;
	dist[start] = 0;

	vector<vector<Edge>> edge(V + 1); //edge[u]에 목적지가v이고 가중치가 e인 pair를 넣는다
	int u, v, e;
	for (int i = 1; i <= E; i++) {
		cin >> u >> v >> e;
		edge[u].push_back(Edge(v, e));
	}

	vector<int> visit(V + 1);
	priority_queue<PAIR, vector<PAIR>, cmp> Q;//top이 현재의 위치, 시작점과의 거리를 가지도록하는 우선순위큐

	//visit[start] = 1;
	Q.push(Edge(start, dist[start]));





	while (!Q.empty()) {

		auto now = Q.top();
		Q.pop();

		if (now.second > dist[now.first]) continue;

		for (auto it = edge[now.first].begin(); it != edge[now.first].end(); it++) {
			if ((it->WT + now.second) > dist[it->DT]) continue;
			Q.push(Edge(it->DT, it->WT + now.second));
			dist[it->DT] = it->WT + now.second;
		}


	}






	for (int i = 1; i <= dist.size() - 1; i++) {
		if (dist[i] != INF)
			cout << dist[i] << '\n';
		else
			cout << "INF" << '\n';
	}
	cout << endl;

	return 0;
}*/