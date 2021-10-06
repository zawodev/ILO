#include <bits/stdc++.h>
#include <stdio.h>
#include <algorithm>
using namespace std;

#ifdef _WIN32
#define getc_unlocked _fgetc_nolock
#define putc_unlocked _fputc_nolock
#endif

int n, m, z, a, b;
int parent[1000111];

inline void putt(int n, bool first = true) {
	if (first && n == 0) putc_unlocked('0', stdout);
	if (n < 0) {
		putc_unlocked('-', stdout);
		n = -n;
	}
	if (n > 0) {  //wyłuskanie kolejnych cyfr z liczby n
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

inline int Find(int x) {
	if (parent[x] == x)
		return x;
	parent[x] = Find(parent[x]);
	return parent[x];
}
inline void Union(int x, int y) {
	register int v1 = Find(x);
	register int v2 = Find(y);
	if (v1 != v2)parent[v1] = v2;
}
int main() {
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);

	for (int i = 1; i <= 1000001; i++) {
		parent[i] = i;
	}

	gett(&n);
	gett(&m);

	for (int i = 1; i <= m; i++) {
		gett(&a);
		gett(&b);
		Union(a, b);
	}
	gett(&z);
	for (int i = 1; i <= z; i++) {
		gett(&a);
		gett(&b);
		if (Find(a) == Find(b)) {
			putc_unlocked('T', stdout);
			putc_unlocked('A', stdout);
			putc_unlocked('K', stdout);
			putc_unlocked('\n', stdout);
		}
		else {
			putc_unlocked('N', stdout);
			putc_unlocked('I', stdout);
			putc_unlocked('E', stdout);
			putc_unlocked('\n', stdout);
		}
	}
}