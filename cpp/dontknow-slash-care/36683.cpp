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

string s, score;

int main() {
    iostream::sync_with_stdio(false);

	cin >> s;

    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] != '<') {
            score += s[i];
        }
		else{
            score.erase(score.begin() + (int)score.size() - 1);
        }
	}
    cout << score;

        //if(wynik == -1)cout << "BRAK";
        //else cout << wynik;
}