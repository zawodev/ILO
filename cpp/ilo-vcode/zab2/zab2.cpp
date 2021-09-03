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

int n, k;
int a[1000111], b[1000111];

int main() {
    iostream::sync_with_stdio(false);
    cin >> n >> k;
    
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < n; i++){
        b[i] = INT_MAX;
    }
    b[0] = 0;

    for (int i = 0; i < n; i++){
        for (int j = 1; j <= k; j++){
            b[i + j] = min(b[i + j], b[i] + abs(a[i] - a[i + j]));
        }
    }

    cout << b[n - 1];
}