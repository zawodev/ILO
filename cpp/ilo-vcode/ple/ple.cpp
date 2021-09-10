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

long long n, p, score;
long long w[1000111], v[1000111];
long long D[105][100005];

int main() {
    iostream::sync_with_stdio(false);
    cin >> n >> p;

    for (int i = 1; i <= n; i++){
        cin >> w[i] >> v[i];
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= p; j++){
            if (w[i] > j){
                D[i][j] = D[i - 1][j];
            }
            else{
                D[i][j] = max(D[i - 1][j], D[i - 1][j - w[i]] + v[i]);
            }
        }
    }
    /*for (int i = 1; i <= n; i++){
        for (int j = 1; j <= p; j++){
            cout << D[i][j] << ' ';
        }
        cout << '\n';
    }*/
    cout << D[n][p];
}