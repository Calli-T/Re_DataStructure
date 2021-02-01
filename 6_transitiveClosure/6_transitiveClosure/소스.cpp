#include <iostream>
#include <vector>

using namespace std;

#define INF 100000000

int n, m;

void transitiveClosure(vector<vector<bool>>& dist);
void makeAStar(vector<vector<bool>>& dist);

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int s, d;

	cin >> n >> m;

	vector<vector<bool>> dist(n);
	for (int i = 0; i < n; i++) {
		dist[i].resize(n, false);
	}

	for (int i = 0; i < m; i++) {
		cin >> s >> d;
		dist[s][d] = true;
	}

	cout << "A" << '\n';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << dist[i][j] << " ";
		}
		cout << '\n';
	}

	transitiveClosure(dist);
	cout << "A+" << '\n';

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << dist[i][j] << " ";
		}
		cout << '\n';
	}

	makeAStar(dist);
	cout << "A*" << '\n';

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << dist[i][j] << " ";
		}
		cout << '\n';
	}


}

void transitiveClosure(vector<vector<bool>> &dist){
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dist[i][j] = dist[i][j] || dist[i][k] && dist[k][j];
			}
		}
	}
}

void makeAStar(vector<vector<bool>>& dist) {
	for (int i = 0; i < n; i++)
		dist[i][i] = true;
}

/*
5 5
0 1
1 2
2 3
3 4
4 2
*/