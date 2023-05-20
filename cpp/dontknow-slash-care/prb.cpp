#include <bits/stdc++.h>
#include <stdio.h>
#include <algorithm>
using namespace std;

#ifdef _WIN32
#define getc_unlocked _fgetc_nolock
#define putc_unlocked _fputc_nolock
#endif

int n, m, temp, val[1000111], czk1, czk2;

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

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	gett(&n);
	gett(&m);
	while (m--) {

		gett(&temp);
		if (n + 1 == temp) {
			czk2 = czk1;
		}

		else {
			val[temp] = max(val[temp] + 1, czk2 + 1);
			czk1 = max(czk1, val[temp]);
		}
	}

	for (int i = 1; i <= n; i++) {
		putt(max(val[i], czk2));
		putc_unlocked(' ', stdout);
	}
}

