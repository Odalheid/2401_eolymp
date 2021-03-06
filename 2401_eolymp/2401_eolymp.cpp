#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> graph;
vector <int> dist, q;
vector<bool> used;
int start, finish, counter;

int main()
{
	int vertices;
	cin >> vertices >> start >> finish;
	--start;
	--finish;
	graph.resize(vertices);
	dist.resize(vertices, 0);
	used.resize(vertices, false);
	for (int i = 0; i < vertices; ++i) {
		vector<int> tmp(vertices);
		for (int j = 0; j < vertices; ++j) cin >> tmp[j];
		graph[i] = tmp;
	}
	q.push_back(start);
	used[start] = true;
	while (q.size() != 0) {
		int to = q.front();
		for (int i = 0; i < vertices; ++i) {
			if (graph[to][i] && !used[i]) {
				q.push_back(i);
				dist[i] = dist[to] + 1;
				used[i] = true;
			}
		}
		used[to] = true;
		q.erase(q.begin());
	}
	cout << dist[finish];
    return 0;
}

