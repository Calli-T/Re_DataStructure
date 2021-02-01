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

	vector<int> inDegree(N + 1);//����
	vector<vector<int>> successor(N + 1);//����
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

	//�����ڰ� ���� ������ ���� �־��ش�
	queue<int> Q;
	for (int i = 1; i <= N; i++) {
		if (inDegree[i] == 0)
			Q.push(i);
	}

	for (int i = 0; i < N; i++) {
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
	// ���� ������ 0�� ��带 ť�� �����մϴ�. 
	for (int i = 0; i < n; i++) {
		if (inDegree[i] == 0) q.push(i);
	}
	// ������ ������ ����Ƿ��� ��Ȯ�� n���� ��带 �湮�մϴ�. 
	for (int i = 0; i < n; i++) {
		// n���� �湮�ϱ� ���� ť�� �������� ����Ŭ�� �߻��� ���Դϴ�. 
		if (q.empty()) {
			printf("����Ŭ�� �߻��߽��ϴ�.");
			return;
		}
		int x = q.front();
		q.pop();
		result[i] = x;
		for (int i = 0; i < a[x].size(); i++) {
			int y = a[x][i];
			// ���Ӱ� ���������� 0�� �� ������ ť�� �����մϴ�. 
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