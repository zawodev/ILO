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
long long w[1000003], v[1000003];
long long D[2][1000003];

int main() {
    iostream::sync_with_stdio(false);
    cin >> n >> p;

    for (int i = 1; i <= n; i++){
        cin >> w[i] >> v[i];
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= p; j++){
            if (w[i] > j){
                D[i%2][j] = D[(i - 1)%2][j];
            }
            else{
                D[i%2][j] = max(D[(i - 1)%2][j], D[(i - 1)%2][j - w[i]] + v[i]);
            }
        }
    }
    /*for (int i = 1; i <= n; i++){
        for (int j = 1; j <= p; j++){
            cout << D[i][j] << ' ';
        }
        cout << '\n';
    }*/
    cout << D[n%2][p];
}