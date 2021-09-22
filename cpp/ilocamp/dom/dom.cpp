#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
 
long long k, p2, p, n, suma1, suma2;
long long a[1000111];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin >> n >> k;
    p2 = n;
    p = 1;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    while (suma1 < k) {
        suma1 += a[p2];
        p2--;
    }
    while (suma2 < k) {
        suma2 += a[p];
        p++;
    }
    cout << max(n-p, n-p2);
}