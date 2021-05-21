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


//=======================================

struct graf {
	bool viz = false;
	vector <int> connects;
	int odl;
}*G;
void StartUp(int n) {
	G = new graf[n];
}
void Connect(int a, int b) {
	G[a].connects.push_back(b);
}
void DFS(int x, int y) {
	G[x].viz = 1;

	for (int i = 0; i < G[x].connects.size(); i++) {
		if (!G[G[x].connects[i]].viz) {
			DFS(G[x].connects[i], y + 1);
		}
	}
}
void BFS(int x) {

	queue<int> kolejka;
	kolejka.push(x);
	G[x].odl = 0;
	G[x].viz = 1;

	while (!kolejka.empty()) {
		x = kolejka.front();
		kolejka.pop();
		for (int i = 0; i < G[x].connects.size(); i++) {
			int y = G[x].connects[i];
			if (!G[y].viz) {
				kolejka.push(y);
				G[y].viz = 1;
				G[y].odl = G[x].odl + 1;
			}
		}
	}
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
inline void gett(long long* n)  //ujemne i dodatnie
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

bool isPrime(int n) {
	if (n <= 3) return n > 1;
	if (n % 2 == 0 || n % 3 == 0) return false;
	for (int i = 5; i * i <= n; i += 6) {
		if (n % i == 0 || n % (i + 2) == 0) return false;
	}
	return true;
}
void change(int a, int k) {
	if (!a) return;
	change(a / k, k);
	cout << "ABCDEFGHIJKLMNOPRSTUWYZ"[a % k];
}
float maxx(float a, float b) {
	if (a > b)return a;
	else return b;
}
float minn(float a, float b) {
	if (a < b)return a;
	else return b;
}

vector<int> FindPrimeFactors(int n) {
	int k = 2;
	int ns = sqrt(n);
	vector<int> score;
	while (n > 1 && k <= ns) {
		while (n % k == 0) {
			score.push_back(k);
			n /= k;
		}
		++k;
	}
	if (n > 1)score.push_back(n);

	return score;
}
void WritePrimeFactors(vector<int> a) {
	while (!a.empty()) {
		cout << a.back() << ' ';
		a.pop_back();
	}
}
vector<int> RCP(int n) {
	vector<int> v;
	int k = 2;
	while (n > 1) {
		while (n % k == 0) {
			v.push_back(k);
			n /= k;
		}
		++k;
	}
	return v;
}
double RPN(stack<string>& tks) {
	double x, y;
	string tk = tks.top(); tks.pop();
	int n = tk.size();

	if (n == 1 && string("+-*/").find(tk) != string::npos) {

		y = RPN(tks);
		x = RPN(tks);

		if (tk[0] == '+')  x += y;
		else if (tk[0] == '-')x -= y;
		else if (tk[0] == '*')x *= y;
		else x /= y;
	}
	else x = stod(tk);

	return x;
}

void sito(bool* tab, unsigned int n) {
	for (int i = 2; i * i <= n; i++) {
		if (!tab[i]) {
			for (int j = i * i; j <= n; j += i) {
				tab[j] = 1;
			}
		}
	}
}
int IloczynCyfr(int x) {
	if (x > 0) {
		return IloczynCyfr(x / 10) * (x % 10);
	}
	return 1;
}
bool czy_pierwsza(int n){
	if (n < 2)
		return false;

	for (int i = 2; i * i <= n; i++)
		if (n % i == 0)
			return false;
	return true;
}

/*
		ifstream fin("hasla.txt");
		ofstream fout("wynik4a.txt");

		while (fin >> s) {}
		fout<<s;

		fin.close();
		fout1.close();
*/
//=======================================

ifstream fin("dane.txt");
ofstream fout("wyniki4_1.txt");

int main() {

	string line;
	int x, score = 0, minn = INT_MAX, maxx = INT_MIN;

	if (fin.is_open()) {
		while (getline(fin, line)) {
			x = stoi(line);
			if (czy_pierwsza(x)) {
				score++;
			}
			if (x > maxx) maxx = x;
			if (x < minn) minn = x;
		}

		fin.close();
	}
	fout << score << ' ' << maxx << ' ' << minn;
	return 0;
}