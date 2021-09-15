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

int n, t[1000111], p;
vector<pair<int, int>> V;

//=======================================
 
int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> t[i];
    }
    for (int i = 1; i <= n; i++){
        p = 0;
        for (int j = 1; j <= t[i]; j++){
            if(p == 0){
                V.push_back(make_pair(i, (i + j + p - 1) % n + 1));
                if(t[(i + j - 1) % n + 1] > 0) p += t[(i + j - 1) % n + 1];
            }
            else{
                if(t[(i + j - 1) % n + 1] > 0) p += t[(i + j - 1) % n + 1];
                V.push_back(make_pair(i, (i + j + p - 1) % n + 1));
            }
        }
    }
    sort(V.begin(), V.end());
    int siz = V.size();
    for (int i = 1; i <= siz; i++){
        pair<int, int> a = V.front();
        V.erase(V.begin());
        cout << a.one << ' ' << a.two << '\n';
    }
}