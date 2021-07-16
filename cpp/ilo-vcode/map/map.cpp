#include <bits/stdc++.h>
#include <stdio.h>
#include <algorithm>
#include <fstream>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>
using namespace std;

#ifdef _WIN32
#define getc_unlocked _fgetc_nolock
#define putc_unlocked _fputc_nolock
#endif

//=======================================

int score = INT_MAX, n, m, k, STA, END, a, b, st, en;

//=======================================
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
void UnVisitAll(){
	for (int i = 1; i <= m; i++){
		G[i].viz = false;
		G[i].odl = 0;
	}
}
void Connect(int a, int b)
{
	G[a].connects.push_back(b);
}
void BFS(int x){
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
/*
void Djikstra (int x){
	odl[x]=0;  mojset.insert({0,x});
	while (!mojset.empty()){
    akt = *mojset.begin(); mojset.erase(mojset.begin());
    int w = akt.second;
    if (zrobiony[w]==0) {
        zrobiony[w]=1;
        for (int i=0; i < G[w].connects.size() ;i++) {
            int v = G[w].connects[i].second;
			//if(G[w].connects[i].first == 0) 
            if (zrobiony[v]==0){
                odl[v] = min(odl[v], odl[w]+G[w].connects[i].first);
                mojset.insert({odl[v],v});
            }
        }
    }
	}
}
*/
inline void putt(int n, bool first = true)
{
	if (first && n == 0)
		putc_unlocked('0', stdout);
	if (n < 0)
	{
		putc_unlocked('-', stdout);
		n = -n;
	}
	if (n > 0)
	{
		putt(n / 10, false);
		putc_unlocked(n % 10 + 48, stdout);
	}
}
inline void gett(int *n) //ujemne i dodatnie
{
	register char c = 0,
				  znak_liczby = 1; //1 - liczba dodatnia, -1 - liczba ujemna
	while (c < 33)
		c = getc_unlocked(stdin);

	if (c == 45)
	{
		znak_liczby = -1;
		c = getc_unlocked(stdin);
	} //jesli napotkamy minus
	(*n) = 0;

	while (c > 32)
	{
		(*n) = (*n) * 10 + c - 48;
		c = getc_unlocked(stdin);
	}

	(*n) *= znak_liczby;
}
inline void gett(long long *n) //ujemne i dodatnie
{
	register char c = 0,
				  znak_liczby = 1; //1 - liczba dodatnia, -1 - liczba ujemna
	while (c < 33)
		c = getc_unlocked(stdin);

	if (c == 45)
	{
		znak_liczby = -1;
		c = getc_unlocked(stdin);
	} //jesli napotkamy minus
	(*n) = 0;

	while (c > 32)
	{
		(*n) = (*n) * 10 + c - 48;
		c = getc_unlocked(stdin);
	}

	(*n) *= znak_liczby;
}

bool isPrime(int n)
{
	if (n <= 3)
		return n > 1;
	if (n % 2 == 0 || n % 3 == 0)
		return false;
	for (int i = 5; i * i <= n; i += 6)
	{
		if (n % i == 0 || n % (i + 2) == 0)
			return false;
	}
	return true;
}
void change(int a, int k)
{
	if (!a)
		return;
	change(a / k, k);
	cout << "ABCDEFGHIJKLMNOPRSTUWYZ"[a % k];
}
float maxx(float a, float b)
{
	if (a > b)
		return a;
	else
		return b;
}
float minn(float a, float b)
{
	if (a < b)
		return a;
	else
		return b;
}

vector<int> FindPrimeFactors(int n)
{
	int k = 2;
	int ns = sqrt(n);
	vector<int> score;
	while (n > 1 && k <= ns)
	{
		while (n % k == 0)
		{
			score.push_back(k);
			n /= k;
		}
		++k;
	}
	if (n > 1)
		score.push_back(n);

	return score;
}
string WriteVector(vector<int> a){
	string s;
	while (!a.empty()) {
		s+= to_string(a.back());
		s+=' ';
		a.pop_back();
	}
	return s;
}

void sito(bool *tab, unsigned int n)
{
	for (int i = 2; i * i <= n; i++)
	{
		if (!tab[i])
		{
			for (int j = i * i; j <= n; j += i)
			{
				tab[j] = 1;
			}
		}
	}
}
int IloczynCyfr(int x)
{
	if (x > 0)
	{
		return IloczynCyfr(x / 10) * (x % 10);
	}
	return 1;
}
bool czy_pierwsza(int n)
{
	if (n < 2)
		return false;

	for (int i = 2; i * i <= n; i++)
		if (n % i == 0)
			return false;
	return true;
}
int nwd(int x, int y)
{
    if (x < y)
        return nwd(y,x);
    if (y == 0)
        return x;
    return nwd(y,x%y);
}

int main() {
    iostream::sync_with_stdio(false);
	cin >> n >> m >> k;
    cin >> STA >> END;

	StartUp(500050);
	//for (int i=0;i<600000;i++) odl[i] = INT_MAX;
	for (int i = 0; i < m; i++){
		cin>>a>>b;
		Connect(a, b);
		Connect(b, a);
	}
	for (int i = 0; i < k; i++){
		cin>>a>>b;

		BFS(a);
		int f1 = G[STA].odl;
		int f2 = G[END].odl;
		UnVisitAll();
		BFS(b);
		int f3 = G[STA].odl;
		int f4 = G[END].odl;
		UnVisitAll();

		//cout << f1 << f2 << f3 << f4 << '\n';
		score = min(score, min(f1 + f4, f2 + f3));
	}
	cout << score;
}