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

int n;
long long x1, b, x2, y2;
pair<int, int> a[1000111];
long long z1, z2;
vector<pair<int, int>> V;

//=======================================

long long dist(int xx1, int yy1, int xx2, int yy2){
    long long f1 = (long long)(xx1 - xx2);
    long long f2 = (long long)(yy1 - yy2);
    return f1 * f1 + f2 * f2;
}

//=======================================

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> x1 >> b >> x2 >> y2;
    for (int i = 1; i <= n; i++){
        cin >> a[i].one >> a[i].two;
        long long d1 = dist(a[i].one, a[i].two, x1, b);
        long long d2 = dist(a[i].one, a[i].two, x2, y2);

        if (d1 < d2 && z2 < d2) z1 = max(d1, z1);
        else if (d2 < d1 && z1 < d1) z2 = max(d2, z2);
        else V.push_back(a[i]);
    }
    //cout << z1 << ' ' << z2;
    for (int i = 0; i < V.size(); i++){
        //pair<int, int> c = ;  //V.erase(V.begin());
        long long d = dist(V[i].one, V[i].two, x1, b);
        //cout << d;

        if (z1 < z2) z2 = max(d, z2);
        else if (z2 < z1) z1 = max(d, z1);
        else z1 = max(d, z1);
    }
    cout << z1 + z2;
}