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

map<int, int> k[200000];

void createSparsTejbl(int _k[], int n){
    for (int i = 0; i < n; i++)
        k[i][0] = _k[i];
  
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 0; (i + (1 << j)) <= n; i++) {
            k[i][j] = min(k[i][j - 1], k[i + (1 << (j - 1))][j - 1]);
        }
    }
}
  
int GetSparsTejbl(int l, int r){
    int j = (int)log2(r - l + 1);
    return min(k[l][j], k[r - (1 << j) + 1][j]);
}

int n, q, a[1000111], c, b;

int main(){
    cin >> n >> q;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
	createSparsTejbl(a, n);
	for (int i = 0; i < q; i++){
        cin >> b >> c;
        cout << GetSparsTejbl(b-1, c-1) << "\n";
	}
}