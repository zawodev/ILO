#include <bits/stdc++.h>
#include <stdio.h>
#include <algorithm>
using namespace std;

#ifdef _WIN32
#define getc_unlocked _fgetc_nolock
#define putc_unlocked _fputc_nolock
#endif

int n, a[1000011], R[1000011], score;

int Find(int w) {
    if (R[w] == w) return w;
    int rep = Find(R[w]);
    R[w] = rep;
    return R[w];
}
void Union(int w, int v) {
    int rw = R[Find(w)];
    int rv = Find(v);
    if (rw != rv) {
        R[rv] = rw;
        score--;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    score = n;

    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) R[i] = i;

    for (int i = 1; i <= n; i++) {
        Union(a[i], i);
    }
    cout << score;
}