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



//=======================================

int n, t, a, score;
vector<int> V;

//=======================================
 
int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    for (int i = 0; i < t; i++){
        cin >> n;
        score = 1;
        for (int j = 1; j <= n; j++){
            cin >> a;
            V.push_back(a);
        }
        sort(V.begin(), V.end());
        for (int j = 1; j < n; j++){
            if(abs(V[j] - V[j-1]) > 1) score++;
        }
        cout << score << '\n';
        V.clear();
    }
}