#include <bits/stdc++.h>
using namespace std;

long long n, m;
 
int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    if(m * 2 < n){
        cout << m + 1;
    }
    else{
        cout << m - 1;
    }
}