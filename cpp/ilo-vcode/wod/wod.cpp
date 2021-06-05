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

vector<string> mysplit(string str){
    vector<string> words;
    string word = "";
    str += ';';
    for (auto x : str){
        if (x == ';') {
            words.push_back(word);
            word = "";
        } else {
            word.push_back(x);
        }
    }
    return words;
}

//=======================================

ifstream fin("wodociagi.txt");
ofstream fout("wyniki1.txt");

int main() {

    string line = "";

    if (fin.is_open()) {
	    while (getline(fin, line)) {
            vector<string> inp = mysplit(line);
        }
		fin.close();
	}
    return 0;
}

