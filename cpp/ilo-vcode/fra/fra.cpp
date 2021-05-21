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

int n, c, f, score;

int main() {
    iostream::sync_with_stdio(false);

    cin >> n;

    for (int i = 0; i <= n; i++){
        int a = __builtin_popcount(i);
        if (a % 2 == 1) score++;
    }
    cout << score;

}