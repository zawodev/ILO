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

string a, b;
int D[3000][3000];

int main() {
    iostream::sync_with_stdio(false);
    cin >> a >> b;

    int n = a.size();
    int m = b.size();
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if(a[i]==b[i]) D[i+1][j+1] = D[i][j] + 1;
            else D[i+1][j+1] = max (D[i+1][j], D[i][j+1]);
        }
    }
    //https://eduinf.waw.pl/inf/alg/001_search/0057.php
}