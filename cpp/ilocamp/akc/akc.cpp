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

long long got;
int z, n, a, prevA;

//=======================================
 
int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> z;

    for (int i = 0; i < z; i++){
        cin >> n >> got;
        cin >> prevA;
        for (int j = 1; j < n; j++){
            cin >> a;
            if(a > prevA) got = got / prevA * a + got % prevA;
            prevA = a;
        }
        cout << got << '\n';
    }
}