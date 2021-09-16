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

int n, t, a, prevA, score, best;
vector<int> V[1000111];
vector<int> Z;

//=======================================
 
int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    for (int i = 0; i < t; i++){
        cin >> n;
        cin >> a;
        V[a].push_back(a);
        prevA = a;

        for (int j = 1; j < n; j++){
            cin >> a;
            best = max(best, a);
            V[a].push_back(prevA);
            prevA = a;
        }
        for (int j = 1; j <= best; j++){
            if(V[j].empty()) Z.push_back(j);
        }
        for (int j = 1; j <= best; j++){
            if(!V[j].empty()){
                for (int k = 0; k < V[j].size(); k++){
                    for (int l = 0; l < Z.size(); l++){
                        //cout << i << " A: " << min(j, V[j][k]) << ' ' << Z[l] << ' ' << max(j, V[j][k]) << '\n';
                        if(min(j, V[j][k]) < Z[l] && Z[l] < max(j, V[j][k])){
                            score++;
                            break;
                        }
                    }
                }
            }
        }
        cout << score + 1 << '\n';
        
        Z.clear();
        for (int j = 1; j <= best; j++){
            V[j].clear();
        }
        best = 0;
        score = 0;
    }
}