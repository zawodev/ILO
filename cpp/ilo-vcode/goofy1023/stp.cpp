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

int s1, s2;

struct graf
{
	bool viz = false;
	vector<int> connects;
	int odl;
} * G;
void StartUp(int n)
{
	G = new graf[n];
}
void Reset(int n){
    for (int i = 0; i <= n; i++){
        G[i].viz = false;
        G[i].odl = 0;
    }
}
void Connect(int a, int b)
{
	G[a].connects.push_back(b);
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
		for (int i = 0; i < (int)G[x].connects.size(); i++)
		{
			int y = G[x].connects[i];
			if (!G[y].viz)
			{
				kolejka.push(y);
				G[y].viz = 1;
				G[y].odl = G[x].odl + 1;
                if(G[y].odl > s1){
                    s1 = G[y].odl;
                    s2 = y;
                }
			}
		}
	}
}

//=======================================

int n, m, b, c, score;

//=======================================
 
int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    StartUp(n + 10);
    for (int i = 1; i <= m; i++){
        cin >> b >> c;
        Connect(b, c);
        Connect(c, b);
    }
    BFS(1);
    Reset(n + 10);
    int s3 = s2;
    //cout << s3;
    s1 = 0;
    s2 = 0;
    BFS(s3);
    if (s1 % 2) cout << s1 / 2 << ".5";
    else cout << s1 / 2 <<  ".0";
}