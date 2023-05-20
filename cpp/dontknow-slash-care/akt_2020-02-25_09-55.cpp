#include <bits/stdc++.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
//#define getc_unlocked _fgetc_nolock
//#define putc_unlocked _fputc_nolock

int n, m, cel, score, score2;
char c;
int odw[1000001];
int odl[1000001];
vector<int> G[1000001];
queue<int> Q;

bool entrys[1000001];
bool przeszkoda[1000001];

priority_queue <int> pq;

void BFS(int x) {
	int y;
	Q.push(x);
	odw[x] = 1;
	odl[x] = 0;
	while (!Q.empty()) {
		x = Q.front(); Q.pop();
		if (entrys[x]) {
			pq.push(-odl[x]);
		}
		for (int i = 0;i < (int)G[x].size();i++) {
			y = G[x][i];
			if (!odw[y]) {
				Q.push(y);
				odw[y] = 1;
				odl[y] = min(odl[x] + 1, odl[y]);
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n * m + 3; i++) {
		odl[i] = INT_MAX;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> c;
			switch (c) {
			case 'A':
				cel = i * m + j;
				break;
			case 'S':
				entrys[i * m + j] = true;
				break;
			case 'P':
				przeszkoda[i * m + j] = true;
				break;
			}
		}
	}
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			if (!przeszkoda[y * m + x]) {
				if (x < m - 1) {
					G[y * m + x].push_back(y * m + x + 1);
				}
				if (x > 0) {
					G[y * m + x].push_back(y * m + x - 1);
				}
				if (y < n - 1) {
					G[y * m + x].push_back((y + 1) * m + x);
				}
				if (y > 0) {
					G[y * m + x].push_back((y - 1) * m + x);
				}
			}
		}
	}
	BFS(cel);
	score = -pq.top();
	pq.pop();
	score2 = -pq.top();
	cout << score + score2 + 1;
}