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
ofstream fout("wyniki2.txt");

int main() {

    pair<string, int> best2;
    string last = "";
    int current = 0;
    int i = 0;

    string line = "", score = "";
    int c[50];

    if (fin.is_open()) {
	    while (getline(fin, line)) {
            vector<string> words = mysplit(line);
            if(i==0)last = words[0];
            i++;

            if(last == words[0]){
                current++;
                best2 = {words[0], max(best2.second, current)};
            }
            else{
                current = 1;
            }
            last = words[0];

            if(words[0] == "DOPISZ"){
                score += words[1];
                c[(int)(words[1][0] - 'A')]++;
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
    /*pair<int, char> best = {0, 'A'};
    for (int i = 0; i < 50; i++) {
        cout << c[i] << '\n';
        if(c[i] > best.first){
            best.first = c[i];
            best.second = 'A' + i;
        }
    }*/
    fout << best2.first << ' ' << best2.second;
    return 0;
}

