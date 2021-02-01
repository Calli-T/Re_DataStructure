#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	int a, b;
	cin >> N >> M;

	vector<int> inDegree(N + 1);//내차
	vector<vector<int>> successor(N + 1);//후임
	vector<int> ans(N + 1, 0);

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		successor[a].push_back(b);
		inDegree[b]++;
	}
	/*
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < successor[i].size(); j++) {
			cout << successor[i][j] << " ";
		}
		cout << '\n';
	}
	*/

	//선행자가 없는 점들을 먼저 넣어준다
	queue<int> Q;
	for (int i = 1; i <= N; i++) {
		if (inDegree[i] == 0)
			Q.push(i);
	}

	for (int i = 0; i < N; i++) {
		if (Q.empty()) break;

		int from = Q.front();
		Q.pop();
		ans[i] = from;//i가 순서고, from은 큐에서 빠진 정점이다

		//내차가 0인 점만 큐에 들어가고, 큐에서 빠지는 순서가 곧 정렬순서이다
		for (int j = 0; j < successor[from].size(); j++) {

			//빠진 정점이 가리키는 정점의 내차를 하나씩감소
			int temp = successor[from][j];
			--inDegree[temp];

			//감소된 내차가 0이면 큐에 삽입
			if(inDegree[temp] == 0)
				Q.push(temp);

		}

	}

	for (int i = 0; i < N; i++)
		cout << ans[i] << " ";
	
}

/*
6 8
1 2
1 3
1 4
2 5
3 5
3 6
4 5
4 6
*/

/*#include <iostream>
#include <vector>
#include <queue>
#define MAX 10

using namespace std;

int n, inDegree[MAX];
vector<int> a[MAX];

void topologySort() {
	int result[MAX];
	queue<int> q;
	// 진입 차수가 0인 노드를 큐에 삽입합니다. 
	for (int i = 0; i < n; i++) {
		if (inDegree[i] == 0) q.push(i);
	}
	// 정렬이 완전히 수행되려면 정확히 n개의 노드를 방문합니다. 
	for (int i = 0; i < n; i++) {
		// n개를 방문하기 전에 큐가 비어버리면 사이클이 발생한 것입니다. 
		if (q.empty()) {
			printf("사이클이 발생했습니다.");
			return;
		}
		int x = q.front();
		q.pop();
		result[i] = x;
		for (int i = 0; i < a[x].size(); i++) {
			int y = a[x][i];
			// 새롭게 진입차수가 0이 된 정점을 큐에 삽입합니다. 
			if (--inDegree[y] == 0)
				q.push(y);
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", result[i]);
	}
}

int main(void) {

	n = 6;

	a[0].push_back(1);
	inDegree[1]++;
	a[0].push_back(2);
	inDegree[2]++;
	a[0].push_back(3);
	inDegree[3]++;

	a[1].push_back(4);
	inDegree[4]++;

	a[2].push_back(4);
	inDegree[4]++;
	a[2].push_back(5);
	inDegree[5]++;

	a[3].push_back(4);
	inDegree[4]++;
	a[3].push_back(5);
	inDegree[5]++;

	topologySort();
}*/