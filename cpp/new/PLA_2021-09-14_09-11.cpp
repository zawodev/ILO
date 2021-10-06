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

int a, b, m;

//=======================================
 
int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b >> m;
    a = abs(a);
    b = abs(b);
    if(a+b<=m && (a+b-m)%2==0){
        cout << "TAK";
    }
    else{
        cout << "NIE";
    }
}