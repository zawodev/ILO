#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

int main(){
    fstream data;
    data.open("napisy.txt");
    int score = 0;
    bool done = false;
    for(int i=0; i<200; i++){
        string a,b;
        data >> a >> b;
        if (a.length() >= 3*b.length() || a.length()*3 <= b.length()) {
            score++;
            if (!done){
                done = true;
                cout << "Pierwsza para: " << '\n' << a << " " << b << '\n';
            } 
        } 
    }
    cout << "Ilosc par: " << score;
}