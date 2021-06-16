#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
 
long long n, m, kukku, kakka, kikki;
long long a[1005][1005];
 
int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
 
        cin >> n >> m;
 
        for (int i = 0; i < n; i++){
                for (int j = 0; j<m; j++){
                        cin >> a[i][j];
                }
        }
        for (int i = 0; i < m; i++){
                kakka = kukku = 0;
                for (int j = n; j >= 0; j--){
                        kukku += a[j][i];
                        kakka = max(kakka, kukku);
                }
                kikki += kakka;
        }
        cout << kikki;
}