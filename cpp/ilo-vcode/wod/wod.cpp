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

string id[110011];
int memCount[110011];
string cityCode[110011];
int waterUsage[110011][20];
int yearlyWaterUsage[110011];
pair<float, int> waterPerPerson[110011];

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
            if(i > 0){
                vector<string> info = mysplit(line);

                for (int j = 0; j < 12; j++) {
                    waterUsage[i][j] = stoi(info[j+1]);
                    yearlyWaterUsage[i] += waterUsage[i][j];
                }
                id[i] = info[0].substr(0, 5);
                memCount[i] = stoi(info[0].substr(5, 7));
                cityCode[i] = info[0].substr(7, 10);
                
                waterPerPerson[i].first = round(yearlyWaterUsage[i] / memCount[i] * 100.0) / 100.0;
                waterPerPerson[i].second = i;

                fout << id[i] << ' ' << memCount[i] << ' ' << cityCode[i] << ' ' << waterUsage[i][0] << '\n';
            }
            i++;
        }
        fin.close();
    }
    int n = sizeof(waterPerPerson) / sizeof(waterPerPerson[0]);
    sort(waterPerPerson, waterPerPerson + n, greater<pair<float, int>>());
    for (int j = 0; j < 10; j++) {
        cout << waterPerPerson[j].first << ' ' << id[waterPerPerson[j].second] << '\n';
    }
    return 0;
}

