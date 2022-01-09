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
int silnia(int n) {
    if(n==0){
        return 1;
    }
    return silnia(n-1)*n;
}
int NWD(int a, int b) {
    int k;
    while (b != 0){ 
        k = b;
        b = a%b;
        a = k;
    }
    return a;
}
int main(){
    vector<string> data = readFile("liczby.txt");

    //zad 4.1
    cout << "4.1 ";

    int count1 = 0;
    for(string d : data){
        int a = stoi(d); 
        float l = log(a)/log(3);
        if(l == (int)l){ 
            count1++;
        }
    }
 
    cout <<"Ilosc poteg liczby 3 wynosi: " << count1 << "\n";

    //zad 4.2
    cout << "4.2 ";

    vector<int> liczby2;
    for(string d : data){
        int a = stoi(d);
        //const char* cyfry = d.c_str(); 
        int suma = 0; //suma silni
        for(int i = 0; i < d.length();i++){
            int n = d[i] - '0';
            suma += silnia(n);
        }
        if(suma == a){
            liczby2.push_back(a); 
        }
    }
    bool done = false;
    for(auto i : liczby2){
        if(done) cout << ", " << i;
        else{
            done = true;
            cout << i;
        }
    }

    //zad 4.3
    cout << "\n4.3 ";
    vector<int> numbers;
    vector<int> finalNumbers; 
    int all[500]; 
    int count = 0;
    for(string d : data){
        all[count] = stoi(d);
        count++;
    }
    int n = all[0];
    int dzielnik;
    for(int i = 1; i < 500; i++){
        
        int nwd = NWD(n, all[i]); 
        if(nwd != 1){
            if(numbers.empty()){
                numbers.push_back(n);
            }
            numbers.push_back(all[i]);
            n = nwd;
        }
        else {
            if(numbers.size() > finalNumbers.size()){ 
                finalNumbers = numbers;
                dzielnik = n;
            }
            if(!numbers.empty()){
                
                if(NWD(numbers[numbers.size()-1], all[i]) > 1){ 
                    int a = numbers[numbers.size()-1]; 
                    numbers.clear(); 
                    numbers.push_back(a);
                    numbers.push_back(all[i]);
                }
                else{   
                    numbers.clear(); 
                }
            }
                
            n = all[i]; 
        }
    }
 
    cout << "Pierwsza liczba z ciagu: " << finalNumbers[0] << ", dzielnik: " << dzielnik << ", dlugosc ciagu: " << finalNumbers.size();
    return 0;
}