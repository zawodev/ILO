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

int n, m, score = INT_MAX;
map<int, map<int, int>> t;
int best[1000111];
string s[1000111];

//=======================================
 
int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> s[i];
        for (int j = 0; j < m; j++){
            int chr = (int)(s[i][j] - 'a');
            t[chr][j]++;
            //best[j] = max(best[j], t[chr][j]);
        }
    }
    for (int i = 0; i < n; i++){
        int suma = 0;
        for (int j = 0; j < m; j++){
            int chr = (int)(s[i][j] - 'a');
            suma += n - t[chr][j];
        }
        score = min(score, suma);
    }
    cout << score;
}