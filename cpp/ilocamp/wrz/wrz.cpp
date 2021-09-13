#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
 
long long n, m, k, a, timed, dostawa;
int magazyn[1000005];
 
void kkk()
{
        timed++;
 
        if (timed % k == 0)dostawa++;
        if (magazyn[a] + dostawa > 0) {
                magazyn[a]--;
        }
        else {
                timed = ((timed / k) + 1) * k;
                dostawa++;
                magazyn[a]--;
        }
}
int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
 
        cin >> n >> m >> k;
        timed = k - 1;
        dostawa = 0;
        for (int i = 0; i < n; i++)
        {
                cin >> a;
                kkk();
        }
        cout << timed;
}