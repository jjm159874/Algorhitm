# DFS

```c++
#include<iostream>
#include<vector>
using namespace std;

#define N 6
vector<int> v[N];
int visited[N];
void dfs(int u) {
	visited[u] = 1;
	cout << u << "\n";
	for (int k : v[u]) {
		if (visited[k]==0)
			dfs(k);
	}
	cout << u << "종료" << endl;
	return;
}

int main() {
	int k;
	cin >> k;
	while (k--) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	 dfs(1);

	return 0;
}
```

# BFS
```c++
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define N 10
vector<int> v[N],nodelist;
int visited[N];

void bfs(int here) {
	queue<int> q;
	nodelist.push_back(here);
	visited[here] = 1;
	q.push(here);
	
	while (q.size()) {
		int here = q.front(); q.pop();
		for (int there : v[here]) {
			if (visited[there])
				continue;
			visited[there] = visited[here] ++;
			q.push(there);
		}
	}
}

int main() {
	int k;
	cin >> k;
	while (k--) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	 bfs(1);

	 int last = 0;
	 for (int i :nodelist) {
		 cout << i << endl;
		 last = i;
	 }

	 cout << visited[last] - 1;

	return 0;
}
```
