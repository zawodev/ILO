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

int n, a;
int t[1000111];

//=======================================
 
int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    
    for (int i = 1; i < n; i++){
        cin >> a;
        t[a]++;
        if(t[a] > 2) {
            cout << i + 1;
            return 0;
        }
    }
    cout << -1;
}