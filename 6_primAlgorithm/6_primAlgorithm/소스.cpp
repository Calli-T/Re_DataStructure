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
		cout << i << "���� ";
		for (int j = 0; j < graph[i].size(); j++) {
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}*/

	return 0;
}

//������ �ڵ带 ¥����
/*
����

�켱���� ť�� �ϳ� �����
�� ���� ���õǾ����� selected �迭�� �ϳ� �����

�� �ϳ��� �ִ´�(Ʈ����....... set�� ��������)
selected�� true�� �Ѵ�

Ʈ�� ������ ���� ���Ե� ��� ������ �켱����ť�� �־��ش�


���� ����ġ�� ���� ������ �ϳ� ������, �켱����ť�� �˾Ƽ� ���ٰŴ�
�� ������, Ʈ�� ������ ���� �ϳ��� ������ ���(set���� find�� �غ���)
(=����Ŭ�� �������� ������) �־��ش�

�ƴϸ� �׷� ���� ���� ������ ����

���� �־���ٸ�, selected�� true�� �ϰ� Ʈ���� set�� �� ���� �־��ش�


������ ����-1���� �� ������ �ݺ��Ѵ�

set�� ���� tree�� ������ set�� �־��ٰŸ� ���� selected�� �ǹ̴� ����?

���ͽ�Ʈ��ó��
Ʈ��(Ȥ�� ������ ����, �迭���)���� �Ÿ��� ��Ÿ�� dist[i]�迭�� ����� ���� ����ص� �ɵ� �ϴ�
*/