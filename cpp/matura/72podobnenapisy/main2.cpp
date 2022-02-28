#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

int main(){
    fstream data;
    data.open("napisy.txt");
    for(int i=0; i<200; i++){
        string a,b;
        data >> a >> b;
        if (a.length() >= b.length())
            continue;
        bool right = true;
        for(int j=0; j<a.length(); j++)
            if (a[j]!=b[j])
                right = false;
        if (right){
            cout << a << " " << b << " ";
            for(int j=a.length(); j<b.length(); j++)
                cout << b[j];
            cout << '\n';
        } 
    } 
}