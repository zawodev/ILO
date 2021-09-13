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

int n, t[1000], best;
char bestVal;
string s, score;

//=======================================

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	cin >> s;
	bestVal = s[0];
	for (int i = 0; i < n; i++){
		t[(int)(s[i])]++;
		if(t[(int)(s[i])] > best || (t[(int)(s[i])] == best && (int)(bestVal) > (int)(s[i])) ){
			bestVal = s[i];
			best = t[(int)(s[i])];
		}
		score += bestVal;
	}
	cout << score;
}