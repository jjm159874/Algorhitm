# 연결된 컴포넌트

<img src= "https://media.geeksforgeeks.org/wp-content/uploads/20200421194558/Count-of-Connected-Components.png" />

## 1012예제(BFS)
```c++
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
#define max_n 101
int tx[] = { -1,0,0,1 };
int ty[] = { 0,-1,1,0 };

int visited[max_n][max_n],a[max_n][max_n],x,y,n,m,k;


void dfs(int p, int q) {
	visited[p][q] = 1;
	for (int i = 0; i < 4; i++) {    
		int ny = p + ty[i];
		int nx = q + tx[i];
		if (nx < 0 or ny < 0 or nx >= m or ny >= n) continue;
		else if (visited[ny][nx]==0 and a[ny][nx]) 
			dfs(ny, nx);
	}
	return;
}


int main() {
	int t,cnt=0;

	cin >> t;
	while (t--) {
		cnt = 0;
		cin >> n >> m >> k;
		fill(&a[0][0], &a[max_n-1][max_n], 0);
		fill(&visited[0][0], &visited[max_n-1][max_n], 0);
		
		while (k--) {
			int r, t;
			cin >> r >> t;
			a[r][t]=1;

		}
	
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (visited[i][j] == 0 and a[i][j]) {
					cnt++;

					dfs(i, j);
				}
			}
		}
		printf("%d\n", cnt);

	}

	return 0;
}
```
x,y 점을 기준으로 상하좌우 탐색.
- 언더플로우,오버플로우->continue
- visited==0이고 맵에 1이면 dfs탐색.

`테스트 케이스 문제`: fill(시작주소, 끝주소,0)로 초기화.
a[5][5]->를 초기화.
ex) fill(&a[0][0],&a[`4`][5],0);
