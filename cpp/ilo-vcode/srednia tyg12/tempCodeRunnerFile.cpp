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

int n, m, a, b;
vector<int> t;
int score;

//=======================================

int kkk(vector<int> V){
    int scr = 0;
    int h[1000111];
    for (int i = 0; i < V.size()/2; i++){
        scr += V[i];
        h[V[i]] = 1;
    }
    return scr;
}

//=======================================
 
int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        int x = 0;
        cin >> x;
        t.push_back(x);
    }
    score = kkk(t);
    for (int i = 1; i <= m; i++){
        cin >> a >> b;
    }
}