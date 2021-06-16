#include <bits/stdc++.h>
#include <stdio.h>
#include <algorithm>
#include <fstream>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>
using namespace std;
 
#ifdef _WIN32
#define getc_unlocked _fgetc_nolock
#define putc_unlocked _fputc_nolock
#endif
 
//=======================================
 
//=======================================
inline void putt(int n, bool first = true)
{
        if (first && n == 0)
                putc_unlocked('0', stdout);
        if (n < 0)
        {
                putc_unlocked('-', stdout);
                n = -n;
        }
        if (n > 0)
        {
                putt(n / 10, false);
                putc_unlocked(n % 10 + 48, stdout);
        }
}
inline void gett(int *n) //ujemne i dodatnie
{
        register char c = 0,
                                  znak_liczby = 1; //1 - liczba dodatnia, -1 - liczba ujemna
        while (c < 33)
                c = getc_unlocked(stdin);
 
        if (c == 45)
        {
                znak_liczby = -1;
                c = getc_unlocked(stdin);
        } //jesli napotkamy minus
        (*n) = 0;
 
        while (c > 32)
        {
                (*n) = (*n) * 10 + c - 48;
                c = getc_unlocked(stdin);
        }
 
        (*n) *= znak_liczby;
}
inline void gett(long long *n) //ujemne i dodatnie
{
        register char c = 0,
                                  znak_liczby = 1; //1 - liczba dodatnia, -1 - liczba ujemna
        while (c < 33)
                c = getc_unlocked(stdin);
 
        if (c == 45)
        {
                znak_liczby = -1;
                c = getc_unlocked(stdin);
        } //jesli napotkamy minus
        (*n) = 0;
 
        while (c > 32)
        {
                (*n) = (*n) * 10 + c - 48;
                c = getc_unlocked(stdin);
        }
 
        (*n) *= znak_liczby;
}
 
bool isPrime(int n)
{
        if (n <= 3)
                return n > 1;
        if (n % 2 == 0 || n % 3 == 0)
                return false;
        for (int i = 5; i * i <= n; i += 6)
        {
                if (n % i == 0 || n % (i + 2) == 0)
                        return false;
        }
        return true;
}
void change(int a, int k)
{
        if (!a)
                return;
        change(a / k, k);
        cout << "ABCDEFGHIJKLMNOPRSTUWYZ"[a % k];
}
float maxx(float a, float b)
{
        if (a > b)
                return a;
        else
                return b;
}
float minn(float a, float b)
{
        if (a < b)
                return a;
        else
                return b;
}
 
vector<int> FindPrimeFactors(int n)
{
        int k = 2;
        int ns = sqrt(n);
        vector<int> score;
        while (n > 1 && k <= ns)
        {
                while (n % k == 0)
                {
                        score.push_back(k);
                        n /= k;
                }
                ++k;
        }
        if (n > 1)
                score.push_back(n);
 
        return score;
}
string WriteVector(vector<int> a){
        string s;
        while (!a.empty()) {
                s+= to_string(a.back());
                s+=' ';
                a.pop_back();
        }
        return s;
}
 
void sito(bool *tab, unsigned int n)
{
        for (int i = 2; i * i <= n; i++)
        {
                if (!tab[i])
                {
                        for (int j = i * i; j <= n; j += i)
                        {
                                tab[j] = 1;
                        }
                }
        }
}
int IloczynCyfr(int x)
{
        if (x > 0)
        {
                return IloczynCyfr(x / 10) * (x % 10);
        }
        return 1;
}
bool czy_pierwsza(int n)
{
        if (n < 2)
                return false;
 
        for (int i = 2; i * i <= n; i++)
                if (n % i == 0)
                        return false;
        return true;
}
int nwd(int x, int y)
{
    if (x < y)
        return nwd(y,x);
    if (y == 0)
        return x;
    return nwd(y,x%y);
}

int n, m, k;
int x[1000111];
int y[1000111];
long long score;
int groups;
map<pair<int, int>, pair<int, int>> R;
map<pair<int, int>, bool> M;

map<pair<int,int>, int> V;

pair<int, int> Find(pair<int,int> w) {
    if (R[w] == w) return w;
    pair<int,int> rep = Find(R[w]);
    R[w] = rep;
    return R[w];
}
void Union(pair<int,int> w, pair<int,int> v) {
    pair<int,int> rw = R[Find(w)];
    pair<int,int> rv = Find(v);
    if (rw != rv) {
        R[rv] = rw;
        //V[rw]++;
        groups--;
    }
}
unsigned long long silnia(unsigned int n) {
    if(n > 1) return n * silnia(n - 1);
    else return 1;
}
int main() {
    iostream::sync_with_stdio(false);

    cin >> n >> m >> k;
    groups = k;
    for (int i = 1; i <= k; i++){
        cin >> x[i] >> y[i];
        R[{x[i], y[i]}] = {x[i], y[i]};
        
        M[{x[i], y[i]}] = true;
        if(M[{x[i] + 2, y[i] + 1}]) Union({x[i], y[i]}, {x[i+2],y[i+1]});
        if(M[{x[i] + 2, y[i] - 1}]) Union({x[i], y[i]}, {x[i+2],y[i-1]});
        if(M[{x[i] - 2, y[i] + 1}]) Union({x[i], y[i]}, {x[i-2],y[i+1]});
        if(M[{x[i] - 2, y[i] - 1}]) Union({x[i], y[i]}, {x[i-2],y[i-1]});

        if(M[{x[i] + 1, y[i] + 2}]) Union({x[i], y[i]}, {x[i+1],y[i+2]});
        if(M[{x[i] - 1, y[i] + 2}]) Union({x[i], y[i]}, {x[i-1],y[i+2]});
        if(M[{x[i] + 1, y[i] - 2}]) Union({x[i], y[i]}, {x[i+1],y[i-2]});
        if(M[{x[i] - 1, y[i] - 2}]) Union({x[i], y[i]}, {x[i-1],y[i-2]});
    }
    for (int i = 1; i <= k; i++){
        V[R[{x[i], y[i]}]]++;
        //cout << R[{x[i], y[i]}].first << ' ' << R[{x[i], y[i]}].second << '\n';
    }
    for(auto v : V){
        score += silnia(v.second);
        score %= 1000000007;
        cout << v.first.first << ' ' << v.first.second << ' ' << v.second << '\n';
    }
    for(auto m : M){
        //cout << m.first.first << ' ' << m.first.second << ' ' << m.second << '\n';
    }
    cout << score;
}