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
    str += ' ';
    for (auto x : str){
        if (x == ' '){
            words.push_back(word);
            word = "";
        }
        else {
            word.push_back(x);
        }
    }
    return words;
}

//=======================================

ifstream fin("instrukcje.txt");
ofstream fout("wyniki3.txt");

int main() {

    string line = "", score = "";
    pair<string, int> best;
    map<int, int>c;

    if (fin.is_open()) {
	    while (getline(fin, line)) {
            vector<string> words = mysplit(line);
            if(words[0] == "DOPISZ"){
                score += words[1];
                int j = (int)(words[1][0]);
                c[j]++;
                if(c[j] > best.second){
                    best = {words[1], c[j]};
                }
            }
            else if(words[0] == "ZMIEN"){
                if (!score.empty()) score.erase(std::prev(score.end()));
                score += words[1];
            }
            else if(words[0] == "USUN"){
                int x = stoi(words[1]);
                if(x>0 && x<score.size())score.erase(std::prev(score.end()) - x + 1);
            }
            else if(words[0] == "PRZESUN"){
                for (int i = 0; i < score.size(); i++){
                    if(score[i] == words[1][0]){
                        if(score[i] == 'Z') score[i] = 'A';
                        else score[i]++;

                        break;
                    }
                }
            }
        }
		fin.close();
	}
    fout << best.second << ' ' << best.first;
    return 0;
}

