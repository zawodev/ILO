#include <bits/stdc++.h>
using namespace std;
int a, n, t[500500], b[500500];
int main ()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i=1; i<=n; i++)
    {
        cin >> t[i];
    }
    for (int i=2; i<=n; i++)
    {
        for (int j=i-1; j>=1; j--)
        {
            if (t[j]>t[i])
            {
                b[i]=j;
                break;
            }
        }
    }
    for (int i=1; i<=n; i++)
    {
        if (b[i]==0)
        {
            cout << "-1" << endl;
        }
        else cout << b[i] << endl;
    }
}
