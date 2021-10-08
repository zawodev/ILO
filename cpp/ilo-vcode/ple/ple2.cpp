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

long long p, w[103];
int n, v[103];
map<long long, int> D;

//jak lecisz od tylu to kazdy przedmiot tylko raz
//jak lecisz od przodu to kazdy przedmiot nieskonczenie wiele razy

int main() {
    iostream::sync_with_stdio(false);
    cin >> n >> p;

    for (int i = 1; i <= n; i++){
        cin >> w[i] >> v[i];
    }
    for (int i = 1; i <= n; i++){
        for (int j = p; j >= w[i]; j--){
            D[j] = max(D[j], D[j - w[i]] + v[i]);
        }
    }
    for (int j = 1; j <= p; j++){
        cout << D[j] << ' ';
    }
    cout << D[p];
}