//od tylu do przodu, 
//snippet
#include <bits/stdc++.h>
#include <stdio.h>
#include <algorithm>
#include <fstream>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#include <bitset>
using namespace std;

#ifdef _WIN32
#define getc_unlocked _fgetc_nolock
#define putc_unlocked _fputc_nolock
#endif

//=======================================

//=======================================

int n, a, b, c;
int t[100111][3], d[100111][3];

int main() {
    iostream::sync_with_stdio(false);
    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> t[i][0] >> t[i][1] >> t[i][2];
    }
    for (int i = 0; i < 3; i++){
        d[0][i] = t[0][i];
    }
    for (int i = 1; i < n; i++){
        d[i][0] += t[i][0] + max(d[i - 1][1], d[i - 1][2]);
        d[i][1] += t[i][1] + max(d[i - 1][0], d[i - 1][2]);
        d[i][2] += t[i][2] + max(d[i - 1][0], d[i - 1][1]);
    }

    cout << max(d[n-1][0], max(d[n-1][1], d[n-1][2]));
}