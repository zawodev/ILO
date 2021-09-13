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

int parent[1000111];

int Find(int i)
{
    if (parent[i] == -1)
        return i;
    return Find(parent[i]);
}
 
void Union(int x, int y)
{
    int xset = Find(x);
    int yset = Find(y);
    parent[xset] = yset;
}

void SetUp(int n){
    for (int i = 0; i < n; i++){
        parent[i] = -1;
    }
}

void DFS (int x){
    if (pom[x][1] == 0){
        pom[x][1] = 1;

        if(pom[x][0] == 1){
            jed++;
        }
        else{
            dwa++;
        }
        if (x % 2 == 0){
            kob++;
        }
        else{
            men++;
        }
        
        for (int i = 0; i < (int)(t[x].size()); i++){
            DFS(t[x][i]);
        }
    }
}

//=======================================

int n,m,a,b;
int jed,dwa,men,kob;
vector <int> t[1000000];
int pom[1000000][2];

//=======================================
 
int main(){
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> pom[i][0];
    }
    for (int i = 0; i < m; i++){
        cin >> a >> b;
        t[a].push_back(b);
        t[b].push_back(a);
    }
    for (int i = 1; i <= n; i++){
        if (pom[i][1] == 0){
            DFS(i);
        }
        if (jed != men || dwa != kob){
            cout<<"NIE";
            return 0;
        }
        jed=0;
        dwa=0;
        men=0;
        kob=0;
    }
    cout<<"TAK";
}