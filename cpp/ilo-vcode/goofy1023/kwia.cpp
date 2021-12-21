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



//=======================================

int n, m, a[1000111], t[1000111], b, c, score;

//=======================================
 
int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        t[i] = t[i - 1] + a[i];
    }
    for (int i = 1; i <= m; i++){
        cin >> b >> c;
        score += max(0, t[c] - t[b-1]);
    }
    cout << score;
}