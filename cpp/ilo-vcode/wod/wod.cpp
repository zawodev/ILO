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

int id[110011];
short memCount[110011];
string cityCode[110011];
int waterUsage[20][110011];

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
        int i = 0;
        while (getline(fin, line)) {
            vector<string> info = mysplit(line);
            for (int j = 0; j < 12; j++) waterUsage[i][j] = stoi(info[i+1]);
            id[i] = stoi(info[0].substr(0, 5));
            memCount[i] = stoi(info[0].substr(5, 7));

            cout << id[i] << ' ' << memCount[i] << ' ' << waterUsage[0] << '\n';
            i++;
        }
		fin.close();
    }
    return 0;
}

