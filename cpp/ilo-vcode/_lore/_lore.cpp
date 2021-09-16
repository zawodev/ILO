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

pair<int, int> t[65535*2+10];
int BASE = 65535;
int n, m, z, p, k, l;

//=======================================

void change(int a, int k) {
	if (!a) return;
	change(a / k, k);
	cout<< "ABCDEFGHIJKLMNOPRSTUVWYZ"[a % k];
}
inline void putt(int n, bool first = true) {
	if (first && n == 0) putc_unlocked('0', stdout);
	if (n < 0) {
		putc_unlocked('-', stdout);
		n = -n;
	}
	if (n > 0) {
		putt(n / 10, false);
		putc_unlocked(n % 10 + 48, stdout);
	}
}
inline void gett(int* n)  //ujemne i dodatnie
{
	register char c = 0,
		znak_liczby = 1;  //1 - liczba dodatnia, -1 - liczba ujemna
	while (c < 33) c = getc_unlocked(stdin);

	if (c == 45) {
		znak_liczby = -1;
		c = getc_unlocked(stdin);
	}  //jesli napotkamy minus
	(*n) = 0;

	while (c > 32) {
		(*n) = (*n) * 10 + c - 48;
		c = getc_unlocked(stdin);
	}

	(*n) *= znak_liczby;
}
float minTmaxF(float a, float b, bool c = true) {
	return (c != a > b ? a : b);
}
void przedzial(int a, int b, int w, int lo, int hi) {
	if (b<lo || a>hi) return;
	if (a <= lo && b >= hi) {
		cout << "w: " << lo << " " << hi << "\n";
		return;
	}
	int mid = (lo + hi) / 2;
	przedzial(a, b, w * 2, lo, mid);
	przedzial(a, b, w * 2, mid + 1, hi);
	//aktualizacja czegos lokalnego, wykona sie gdy wyjdzie z danej rekurencji
}
int gcd(int a, int b) {
	if (a == 0) return b;
	else if (b == 0 || a == b) return a;
	else if (a > b) return gcd(a - b, b);
	else return gcd(a, b - a);
}

/*void kakka(int a, int b) {
	int l = BASE + a;
	int p = BASE + b;

	int score = t[l] + t[p];
	while (l / 2 != p / 2) {
		if (p % 2 == 1)score += t[p - 1];
		if (l % 2 == 0)score += t[l - 1];

		l /= 2;
		p /= 2;
	}
}*/

void kakka2(int a, int b, int x, int w = 1, int lo = 0, int hi = BASE) {
	cout << a << ' ' << b << ' ' << x << ' ' << w << ' ' << lo << ' ' << hi << '\n';
	if (a > hi || b < lo)return;
	cout << "prr\n";
	if (a <= lo && b >= hi) {
		t[w].one += x;
		if (w < BASE + 1) {
			int w0 = w;
			while (w >= 1) {
				t[w].two = max(t[w * 2].one + t[w * 2].two, t[w * 2 + 1].one + t[w * 2 + 1].two);
			}
		}
	}
	if (lo != hi) {
		int mid = (lo + hi) / 2;
		kakka2(a, b, x, w * 2, lo, mid);
		kakka2(a, b, x, w * 2 + 1, mid + 1, hi);
	}
}
/*
pair<int, int> kakka3(int a, int b, int *c) {
	if (a == 0 || b == 0)return{ 1, 0 };
	else {
		(*c) = b;
		pair<int, int> xy = kakka3(b, a % b, c);
		xy.one = ((*c) - xy.two * a) / b;
		return{ xy.two, xy.one };
	}
}
*/


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
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	
	cin >> n >> m >> z;
	while (z--) {
		cin >> p >> k >> l;
		kakka2(p, k, l);
		if (t[1].second > m) {
			cout << "N\n";
			kakka2(p, k, -l);
		}
		else cout << "T\n";
	}
	/*
	cin >> a >> b;
	int c;
	score = kakka3(max(a, b), min(a, b), &c);
	cout << score.one << ' ' << score.two;
	*/
}