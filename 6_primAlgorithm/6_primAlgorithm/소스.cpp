#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int main() {

	int vertex, edge;
	vector<vector<int>> graph;
	int a, b, c;

	cin >> vertex >> edge;
	graph.resize(vertex);

	for (int i = 0; i < edge; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	/*for (int i = 0; i < graph.size(); i++) {
		cout << i << "에는 ";
		for (int j = 0; j < graph[i].size(); j++) {
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}*/

	return 0;
}

//언젠간 코드를 짜볼것
/*
프림

우선순위 큐를 하나 만든다
각 점이 선택되었는지 selected 배열을 하나 만든다

점 하나를 넣는다(트리에....... set도 괜찮겠지)
selected에 true를 한다

트리 내부의 점이 포함된 모든 간선을 우선순위큐에 넣어준다


제일 가중치가 작은 간선을 하나 꺼낸다, 우선순위큐가 알아서 해줄거다
뺀 간선이, 트리 내부의 점을 하나만 포함할 경우(set에서 find를 해보자)
(=사이클을 형성하지 않으면) 넣어준다

아니면 그런 점이 나올 때까지 뺀다

뭔갈 넣어줬다면, selected를 true로 하고 트리나 set에 그 점을 넣어준다


간선이 정점-1개가 될 때까지 반복한다

set을 통해 tree의 점들을 set에 넣어줄거면 딱히 selected의 의미는 없다?

다익스트라처럼
트리(혹은 정점의 집합, 배열등등)와의 거리를 나타낼 dist[i]배열을 만들어 놓고 계산해도 될듯 하다
*/