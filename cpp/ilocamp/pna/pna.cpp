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

int n, m, score;
map<int, int> t[100];
int best[1000111];
string s;

//=======================================
 
int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> s;
        for (int j = 0; j < m; j++){
            int chr = (int)(s[j] - 'a');
            t[chr][j]++;
            best[j] = max(best[j], t[chr][j]);
        }
    }
    for (int j = 0; j < m; j++){
        score += n - best[j];
    }
    cout << score;
}