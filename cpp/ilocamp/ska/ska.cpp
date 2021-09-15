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

long long n, m, a, b, c, score;
long long t[1000111];
map<pair<int, int>, vector<long long>> M;
map<pair<int, int>, bool> preffed;

//=======================================
 
int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> t[i];
    }
    for (int i = 1; i <= m; i++){
        cin >> a >> b >> c;
        int d = (a-1) % c + 1;
        if(!preffed[{d, c}]){
            M[{d, c}].push_back(0);
            for (int j = 0; j <= (n-d)/c; j++){
                M[{d, c}].push_back(M[{d,c}][j] + t[j*c+d]);
            }
            preffed[{d, c}] = true;
        }
        /*cout << d << ' ';
        for (int i = 0; i <= d+c+10; i++){
            cout << M[{d, c}][i] << ' ';
        }*/
        /*for (auto i : M[{d,c}]){
            cout << i << ' ';
        }*/
        //cout << '\n';
        cout << M[{d, c}].back() << ' ' << M[{d, c}][a-d] << '\n';      
        cout << M[{d, c}][b+1] - M[{d, c}][a-d] << '\n';      
    }
}