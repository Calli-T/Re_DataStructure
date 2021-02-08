#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> weight;//가중치

vector<vector<int>> successor;//후임
vector<int> inDegree;//들어오는점
vector<vector<int>> successorR;//선임

vector<int> inDegreeR;//들어왔던점

vector<int> EST; //Earliest Start Time
vector<int> LST; //Latest Start Time

vector<int> ans;
vector<int> ansR;

int N, M;

void topologicalSort(int start) {

	//선행자가 없는 점부터 집어넣는다
	queue<int> Q;
	for (int i = 0; i < N; i++) {
		if (inDegree[i] == 0)
			Q.push(i);
	}

	for (int i = start; i < N; i++) {
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
			if (inDegree[temp] == 0)
				Q.push(temp);

			//가리키는점의 EST < 빠진점의 EST + 빠진점의 가중치일 경우
			//가리키는점의 EST = 빠진점의 EST + 빠진점의 가중치
			if (EST[temp] < EST[from] + weight[from])
				EST[temp] = EST[from] + weight[from];

		}

	}

	for (int i = 0; i < N; i++)
		cout << ans[i] << " ";
	cout << endl;

	for (int i = 0; i < N; i++)
		cout << EST[i] << " ";
	cout << endl;

}

void topologicalSortR(int start) {

	//선행자가 없는 점부터 집어넣는다
	queue<int> Q;
	for (int i = 0; i < N; i++) {
		if (inDegreeR[i] == 0) { 
			Q.push(i);
			LST[i] = EST[i];
		}
	}

	for (int i = start; i < N; i++) {
		if (Q.empty()) break;

		int from = Q.front();
		Q.pop();
		ansR[i] = from;//i가 순서고, from은 큐에서 빠진 정점이다

		//내차가 0인 점만 큐에 들어가고, 큐에서 빠지는 순서가 곧 정렬순서이다
		for (int j = 0; j < successorR[from].size(); j++) {

			//빠진 정점이 가리키는 정점의 내차를 하나씩감소
			int temp = successorR[from][j];
			--inDegreeR[temp];

			//감소된 내차가 0이면 큐에 삽입
			if (inDegreeR[temp] == 0)
				Q.push(temp);

			if (LST[temp] > LST[from] - weight[temp])
				LST[temp] = LST[from] - weight[temp];

		}

	}

	for (int i = 0; i < N; i++)
		cout << ansR[i] << " ";
	cout << endl;

	for (int i = 0; i < N; i++)
		cout << LST[i] << " ";
	cout << endl;

}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int a, b, c;
	cin >> N >> M;

	weight.resize(N, 0);

	successor.resize(N);
	inDegree.resize(N, 0);

	successorR.resize(N);
	inDegreeR.resize(N, 0);

	EST.resize(N, 0);
	LST.resize(N, 1000000);//LST는 줄이는 연산이므로 초기값은 커야한다(INF)

	ans.resize(N, 0);
	ansR.resize(N, 0);

	for (int i = 0; i < N; i++) {
		cin >> c;
		weight[i] = c;
	}
	 
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		successor[a].push_back(b);
		successorR[b].push_back(a);
		inDegree[b]++;
		inDegreeR[a]++;
	}

	topologicalSort(0);
	topologicalSortR(0);

	cout << endl;
	for (int i = 0; i < N; i++) {
		if (LST[i] == EST[i])
			cout << "Vertex: " << i << "is Critical Activity" << endl;
	}

}

/*
6 8
7 5 10 8 3 5
0 1
0 2
0 3
1 4
2 4
2 5
3 4
3 5
*/