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

/*int W(int a[3], int b[3], int c[3]) {
    return ( a[0] * b[1] * c[2] + b[0] * c[1] * a[2] + c[0] * a[1] * b[2]-(a[0] * c[1] * b[2] + b[0] * a[1] * c[2] + c[0] * b[1] * a[2]));
}*/

/*
		ifstream fin("hasla.txt");
		ofstream fout("wynik4a.txt");

		while (fin >> s) {}
		fout<<s;

		fin.close();
		fout1.close();
*/
//=======================================
/*

ifstream fin("dane.txt");
ofstream fout("wyniki4_1.txt");

int main() {

	string line;
	int x, score = 0, minn = INT_MAX, maxx = INT_MIN;

	if (fin.is_open()) {
		while (getline(fin, line)) {
			x = stoi(line);
			if (czy_pierwsza(x)) {
				score++;
			}
			if (x > maxx) maxx = x;
			if (x < minn) minn = x;
		}

		fin.close();
	}
	fout << score << ' ' << maxx << ' ' << minn;
	return 0;
}
*/

int n, x, y, a, b;
bool s[1000111];

queue<int> scores;

int main() {
    iostream::sync_with_stdio(false);

    cin >> n >> x >> y;
    for (int i = 0; i < n; i++){
        cin >> a >> b;
		for (int j = a; j <= b; j++){
            s[j] = true;
        }
    }

	if(y > x){
		for (int i = y; i >= x; i--){
        	if (!s[i]) scores.push(i);
    	}
	}
	else{
		for (int i = y; i <= x; i++){
            if (!s[i]) scores.push(i);
        }
	}

    cout << scores.size() << '\n';
    while(!scores.empty()){
		cout<<scores.front() << ' ';
        scores.pop();
    }
}