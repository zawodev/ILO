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

int n, a[1000111];
int score;

//=======================================

//=======================================

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        for (int j = 1; j < i; j++){
            if (a[j] - a[i] == j - i) score++;
        }
    }
    cout << score;
}