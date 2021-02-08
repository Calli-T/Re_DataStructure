#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> weight;//����ġ

vector<vector<int>> successor;//����
vector<int> inDegree;//��������
vector<vector<int>> successorR;//����

vector<int> inDegreeR;//���Դ���

vector<int> EST; //Earliest Start Time
vector<int> LST; //Latest Start Time

vector<int> ans;
vector<int> ansR;

int N, M;

void topologicalSort(int start) {

	//�����ڰ� ���� ������ ����ִ´�
	queue<int> Q;
	for (int i = 0; i < N; i++) {
		if (inDegree[i] == 0)
			Q.push(i);
	}

	for (int i = start; i < N; i++) {
		if (Q.empty()) break;

		int from = Q.front();
		Q.pop();
		ans[i] = from;//i�� ������, from�� ť���� ���� �����̴�

		//������ 0�� ���� ť�� ����, ť���� ������ ������ �� ���ļ����̴�
		for (int j = 0; j < successor[from].size(); j++) {

			//���� ������ ����Ű�� ������ ������ �ϳ�������
			int temp = successor[from][j];
			--inDegree[temp];

			//���ҵ� ������ 0�̸� ť�� ����
			if (inDegree[temp] == 0)
				Q.push(temp);

			//����Ű������ EST < �������� EST + �������� ����ġ�� ���
			//����Ű������ EST = �������� EST + �������� ����ġ
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

	//�����ڰ� ���� ������ ����ִ´�
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
		ansR[i] = from;//i�� ������, from�� ť���� ���� �����̴�

		//������ 0�� ���� ť�� ����, ť���� ������ ������ �� ���ļ����̴�
		for (int j = 0; j < successorR[from].size(); j++) {

			//���� ������ ����Ű�� ������ ������ �ϳ�������
			int temp = successorR[from][j];
			--inDegreeR[temp];

			//���ҵ� ������ 0�̸� ť�� ����
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
	LST.resize(N, 1000000);//LST�� ���̴� �����̹Ƿ� �ʱⰪ�� Ŀ���Ѵ�(INF)

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