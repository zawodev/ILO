#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

vector<string> readFile(string fileName) {
    vector<string> readen;
    ifstream file;
    file.open(fileName);
    while(file.peek() != -1) {
        string line;
        getline(file,line);
        readen.push_back(line);
    }
    return readen;
}
int calculateNumberOfDiffLetters(bool exists[]) {
    int diff = 0;
    for(int i = 0;i<26;i++) {
        if(exists[i]==true) diff++;
    }
    return diff;
}
pair<string,int> getTheMostDifferentWords(vector<string> data) {
    pair<string,int> theMostDifferent("",0);
    for(string word : data) {
        bool exist[26];
        for(int i = 0;i<26;i++) exist[i] = false;
        for(int i = 0;i<word.size();i++) {
            exist[word.at(i)-'A'] = true;
        }
        if(calculateNumberOfDiffLetters(exist)>theMostDifferent.second) {
            theMostDifferent = make_pair(word,calculateNumberOfDiffLetters(exist));
        }
    }
    return theMostDifferent;
}
vector<string> selectWordsDiffLessThan10(vector<string> data) {
    vector<string> wordToReturn;
    for(string word : data) {
        bool add = true;
        int minn = INT_MAX;
        int maxx = INT_MIN;
        for(int i = 0;i<(word.size());i++) {
            maxx = max(abs(word.at(i)), maxx);
            minn = min(abs(word.at(i)), minn);
        }
        if(maxx - minn < 10) wordToReturn.push_back(word);
    }
    return wordToReturn;
}
int main(){

    vector<string> fileData = readFile("sygnaly.txt");

    //zad 4.1
    cout << "4.1 ";

    string result1;
    for(int i = 39; i < fileData.size(); i += 40) {
        result1 += fileData[i][9];
    }
    cout << result1 << "\n";
    
    //zad 4.2
    cout << "4.2 ";

    pair<string,int> result2 = getTheMostDifferentWords(fileData);
    string resultString = result2.first;
    int letterNumber = result2.second;

    cout << letterNumber << " " << resultString << "\n";

    //zad 4.3
    cout << "4.3\n";

    vector<string> result3 = selectWordsDiffLessThan10(fileData);
    for(string word : result3) {
        cout<<word<<"\n";
    }
}