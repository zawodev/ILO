#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
 
long long k, pointer, n, suma, score;
long long a[1000111];

int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
 
        cin >> n >> k;
        pointer = n;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        while (suma < k) {
            suma += a[pointer];
            pointer--;
        }
        score = pointer;
        pointer++;
        for(long long i = 1; i <= n; i++){
            suma += a[i];
            while (suma - a[pointer] >= k && pointer <= n){
                suma -= a[pointer];
                score = max(score, pointer - i);
                pointer++;
            }
        }
        cout << score;
}