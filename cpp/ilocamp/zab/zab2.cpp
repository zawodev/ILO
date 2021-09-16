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

int n, t[1000111];
bool dead[1000111];
queue<int> Q;
vector<pair<int, int>> V;

//=======================================

void Show(int n){
    for (int i = 1; i <= n;i++){
        cout << t[i] << ' ';
    }
    cout << '\n';
    for (int i = 1; i <= n;i++){
        cout << (dead[i]?"d":"a") << ' ';
    }
    cout << '\n';
    cout << '\n';
}

void Kill(int x, int y, int n){
    //if(t[x] == 0) return;
    if(t[y] > 0) {
        Kill(y, y % n + 1, n);
        Q.push(x);
    }
    else if(dead[y]){
        Kill(x, y % n + 1, n);
    }
    else if(t[x] > 0){
        t[x]--;
        if(t[x] > 0) Q.push(x);
        dead[y] = true;
        V.push_back({x, y});
        //cout << x << ' ' << y << '\n';
        //Show(n);
    }
}

//=======================================
 
int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> t[i];
        if(t[i] > 0) Q.push(i);
    }
    while(!Q.empty()){
        int killer = Q.front(); Q.pop();
        Kill(killer, killer % n + 1, n);
    }
    sort(V.begin(), V.end());
    int siz = V.size();
    for (int i = 1; i <= siz; i++){
        pair<int, int> a = V.front();
        V.erase(V.begin());
        cout << a.one << ' ' << a.two << '\n';
    }
}