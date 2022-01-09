#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>
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
bool czyPierwsza(int n) {
    int s = sqrt(n);
    for (int i = 2; i < s; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}
 
pair<int, int> goldbach(int n) {
    if(n % 2 != 0){
        return {-1, -1};
    }
    int num1 = 0; 
    int num2 = 0;
    for(int i = 3; i <= n; i++){
        int r = n - i;
        if((czyPierwsza(i) && czyPierwsza(r)) && (num2 - num1 <= r - i)){
            num2 = r;
            num1 = i;
        }
    }
    return {num1, num2};
    //cout << n << " " << num1 << " " << num2 << "\n";
}
bool czyMniejszy(string s1, string s2) {
	
	int num1 = stoi(s1.substr(0, s1.find(" "))); //wybieramy liczbe z pierwszej pary
	string word1 = s1.substr(s1.find(" ")+1, s1.length()-1); //wybieramy slowo z pierwszej pary
	int num2 = stoi(s2.substr(0, s2.find(" "))); //wybieramy liczbe z pierwszej pary
	string word2 = s2.substr(s2.find(" ")+1, s2.length()-1); //wybieramy slowo z pierwszej pary
	if(num2> num1){ // porownujemy najpierw liczby
		return true;
	}
	else if(num1 == num2 && word2>word1){ // jezeli sa rowne to porwonujemy wyrazy
		return true;
	}
	return false; // jezeli w zadnym wypadku wyraz nie byl mniejszy to zwroc falsz
}
int main(){

    vector<string> data = readFile("pary.txt");

    //zad 4.1
    cout << "4.1\n";

    int num1;
    for(string d : data){
        num1 = stoi(d.substr(0, d.find(" ")));
        pair<int, int> p = goldbach(num1);
        if(p.first != -1){
            cout << p.first << ' ' << p.second << '\n';
        }
    }

    //zad 4.2
    cout << "\n4.2\n";
    string word1;
    for(string d : data){
        word1 = d.substr(d.find(" ") + 1, d.length() - 1); 
        string longest = ""; 
        string current = ""; 
        for (int i = 0; i < word1.length();i++) {
            if(current.length() == 0 || current[0] == word1[i]){ 
                current += word1[i];
            }
            else{
                if(current.length() > longest.length()){
                    longest = current;
                }
                current = "";
                current += word1[i]; 
            }
        }
        if(current.length() > longest.length()){ 
            longest = current; 
        }
        if(longest.length() == 0){ 
            longest = current;
        }
        cout << longest << " " << longest.length() << '\n';
    }

    //zad 4.3
    cout << "\n4.3\n";
    string word; 
	int num; 
	vector<string> slowa; 
 
	for(string d : data){	
		num = stoi(d.substr(0, d.find(" ")));
		word = d.substr(d.find(" ")+1, d.length()-1);
				
		if(num == word.length()){ 
			slowa.push_back(d); 
		}
	}
	string para = slowa[0]; 
	for (int i = 1; i < slowa.size(); i++){ 
		if(czyMniejszy(slowa[i], para)){ 
			para = slowa[i]; 
		}
	}
 
	cout << para << '\n';
}