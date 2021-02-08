#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> weight;//가중치
vector<vector<int>> weightR;

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
			if (EST[temp] < EST[from] + weight[from][j])
				EST[temp] = EST[from] + weight[from][j];

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

		//cout << from << endl;

		//내차가 0인 점만 큐에 들어가고, 큐에서 빠지는 순서가 곧 정렬순서이다
		for (int j = 0; j < successorR[from].size(); j++) {

			//빠진 정점이 가리키는 정점의 내차를 하나씩감소
			int temp = successorR[from][j];
			--inDegreeR[temp];

			//감소된 내차가 0이면 큐에 삽입
			if (inDegreeR[temp] == 0)
				Q.push(temp);

			//cout << temp << " " << from << endl;
			if (LST[temp] > LST[from] - weightR[from][temp])
				LST[temp] = LST[from] - weightR[from][temp];

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

	weight.resize(M);
	weightR.resize(M);
	for (int i = 0; i < M; i++)
		weightR[i].resize(M);

	successor.resize(N);
	inDegree.resize(N, 0);

	successorR.resize(N);
	inDegreeR.resize(N, 0);

	EST.resize(N, 0);
	LST.resize(N, 1000000);//LST는 줄이는 연산이므로 초기값은 커야한다(INF)

	ans.resize(N, 0);
	ansR.resize(N, 0);

	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		successor[a].push_back(b);
		successorR[b].push_back(a);
		inDegree[b]++;
		inDegreeR[a]++;
		weight[a].push_back(c);
		weightR[b][a] = c;
	}

	topologicalSort(0);
	topologicalSortR(0);

	cout << endl;
	for (int i = 0; i < N; i++) {
		if (LST[i] == EST[i])
			cout << "Vertex: " << i << " is Critical Activity" << endl;
	}

}

/*

9 11
0 1 6
0 2 4
0 3 5
1 4 1
2 4 1
3 5 2
4 6 8
4 7 6
5 7 4
6 8 2
7 8 4

*/

//임계작업의 단축이 프로젝트 시간을 단축 시키려면 임계작업이 모든 임계 경로에 포함되어있어야한다
//작업시간은 추정치에 불과하므로, 도중에 재평가가 이루어 질 수 있다
//재평가가 이루어진다면 임계작업이 비임계작업이 될 수 있고, 그 역도 가능하다