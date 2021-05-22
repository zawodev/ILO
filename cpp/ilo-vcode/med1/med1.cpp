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

int n, t[1000111];

int main() {
    ios_base::sync_with_stdio(0);

    cin>>n;

    for(int i = 1; i <= n*2; i++) cin >> t[i];
    sort(t, t + n*2);

    cout<<t[n+1]-t[n];
}

