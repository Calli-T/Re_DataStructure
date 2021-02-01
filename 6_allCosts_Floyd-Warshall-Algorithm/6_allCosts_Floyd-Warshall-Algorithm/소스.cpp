#include <iostream>
#include <vector>

using namespace std;

#define INF 10000000

int n, m;
int dist[101][101] = { 0 };

void reset();
void Floyd();

int  main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int s, d, c;
	cin >> n >> m;
	reset();

	for (int i = 0; i < m; i++) {
		cin >> s >> d >> c;
		if (dist[s][d] > c)
			dist[s][d] = c;
	}

	Floyd();

	for (int i = 1; i <= n; i++) {

		for (int j = 1; j <= n; j++) {
			if (dist[i][j] != INF)
				cout << dist[i][j] << ' ';
			else
				cout << '0' << ' ';
		}

		cout << '\n';

	}
}

void reset() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (i != j)
				dist[i][j] = INF;
}

void Floyd() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
				if (dist[j][k] > dist[j][i] + dist[i][k])
					dist[j][k] = dist[j][i] + dist[i][k];
}

/*#include <iostream>
#include <vector>

#define INF 100000000

using namespace std;

void Floyd_Warshall(vector<vector<int>> &dist, vector<vector<int>> &cost, int v) {

	dist = cost;

	for (int k = 0; k < v; k++) {

		for (int i = 0; i < v; i++) {
			for (int j = 0; j < v; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
					//i = k, j = i ,k = j

				}
			}
		}
	}

}

int main() {

	int v, e;
	cin >> v >> e;
	vector<vector<int>> cost(v);
	for (int i = 0; i < v; i++)
		cost[i].resize(v, INF);
	int a, b, c;
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		cost[a][b] = c;
	}
	for (int i = 0; i < v; i++)
		cost[i][i] = 0;

	vector<vector<int>> dist;
	Floyd_Warshall(dist, cost, v);

	for (int i = 0; i < v; i++) {
		for (int j = 0; j < v; j++) {
			if (dist[i][j] != INF)
				cout << dist[i][j] << " ";
			else
				cout << "INF" << " ";
		}
		cout << endl;
	}

	return 0;

}*/

/*
5
14
0 1 2
0 2 3
0 3 1
0 4 10
1 3 2
2 3 1
2 4 1
3 4 3
2 4 10
2 0 8
0 3 2
4 0 7
2 3 2
4 1 4
*/

/*
3 5
0 1 4
0 2 11
1 0 6
1 2 2
2 0 3
*/

/*
3 3
0 1 1
1 0 -2
1 2 1
*/