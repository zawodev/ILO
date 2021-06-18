#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
 
long long n, k, c, score;
map<long long, vector<long long>> v;
 
int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
 
        cin >> n >> k;
        for (int i = 0; i < n; i++)
        {
                cin >> c;
                v[c % k].push_back(c);
        }
        for (auto &m : v)
        {
                sort(m.second.begin(), m.second.end());
                c = 1;
                for (long long j = 1; j < (long long)m.second.size(); j++)
                {
                        if ((m.second[j] - m.second[j - 1]) == k)
                        {
                                c++;
                        }
                        else if (m.second[j] != m.second[j - 1])
                        {
                                c = 1;
                        }
                        score = max(score, c);
                }
                score = max(score, c);
        }
        cout << score;
        /*for (int i = 0; i < n; i++)
        {
                cout << "Reszta: " << i << " - ";
                for (auto j : v[i])
                {
                        cout << j << ' ';
                }
                cout << "\n";
        }/*/
}