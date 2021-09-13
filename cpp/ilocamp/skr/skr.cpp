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

int n, a[1000111], anus, score[1000111], f1, l1;

//=======================================
 
int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] == 0){
            if(a[i-1] == 1) score[i] = score[i - 1] + 1;
            else score[i] = score[i-1];
        }
        else{
            if(f1 == 0) f1 = i;
            score[i] = score[i - 1] + 1;
            l1 = i;
        }
        //cout << score[i] << '\n';
    }
    cout << score[l1] - score[f1] + 1;
}