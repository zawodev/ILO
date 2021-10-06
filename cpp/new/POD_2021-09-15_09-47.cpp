#include <bits/stdc++.h>
#include <stdio.h>
#include <algorithm>
#include <bitset>
#include <fstream>
using namespace std;
 
#ifdef _WIN32
#define getc_unlocked _fgetc_nolock
#define putc_unlocked _fputc_nolock
#endif
 
#define one first
#define two second
 

//=======================================

struct graf
{
	bool viz = false;
	vector<int> connects;
    int odl = INT_MAX;
} * G;
void StartUp(int n)
{
	G = new graf[n];
}
void Reset(int n){
    for (int i = 0; i <= n; i++){
        G[i].viz = false;
        G[i].odl = INT_MAX;
    }
}
void Connect(int a, int b)
{
	G[a].connects.push_back(b);
}
void DFS(int a, int b, int x, int odl){
	G[a].viz = 1;
    G[a].odl = min(G[a].odl, odl);
    //if(G[a])

    for (int i = 0; i < G[a].connects.size(); i++){
		if (!G[G[a].connects[i]].viz){
			DFS(G[a].connects[i], b, x, odl + 1);
		}
	}
}
void BFS(int x)
{
	queue<int> kolejka;
	kolejka.push(x);
	G[x].odl = 0;
	G[x].viz = 1;

	while (!kolejka.empty())
	{
		x = kolejka.front();
		kolejka.pop();
		for (int i = 0; i < G[x].connects.size(); i++)
		{
			int y = G[x].connects[i];
			if (!G[y].viz)
			{
				kolejka.push(y);
				G[y].viz = 1;
				G[y].odl = G[x].odl + 1;
			}
		}
	}
}

//=======================================

int n, m, a, b, x, ab, xa, xb;

//=======================================
 
int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    StartUp(n + 5);
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        Connect(a, b);
        Connect(b, a);
    }
    cin >> a >> b >> x;
    BFS(a);
    ab = G[b].odl;

    Reset(n + 3);
    BFS(x);
    xa = G[a].odl;
    xb = G[b].odl;

    //cout << ab << ' ' << xb << ' ' << xa << '\n';
    if(G[a].viz && G[b].viz && ab >= xb + xa)cout << "TAK";
    else cout << "NIE";
}