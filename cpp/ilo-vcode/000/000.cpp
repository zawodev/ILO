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
    
    for(int i = 1; i<= n; i++){
        for (int j = 1; j <= n; j++){
            cout << max(abs(n/2+n%2 - i), abs(n/2+n%2 - j)) + 1 << ' ';
        }
        cout << '\n';
    } 

}