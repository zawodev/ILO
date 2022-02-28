#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

int endd(string a, string b){
    int alen = a.length();
    int blen = b.length();
    int n = 0;
    while(n<alen && n<blen && a[alen-1-n]==b[blen-1-n])
        n++;
    return n;
} 

int main(){
    fstream data;
    data.open("napisy.txt");
        
    int lenn = 0;
    string firstt[209], scnd[209];
    int wspolna[209];
    for(int i=0; i<200; i++){
        data >> firstt[i] >> scnd[i];
        wspolna[i] = endd(firstt[i], scnd[i]);
        if (wspolna[i] > lenn)
        lenn = wspolna[i];
    }
    cout << "Max: " << lenn << '\n';
    for(int i=0; i<200; i++)
        if (wspolna[i]==lenn)
            cout << firstt[i] << " " << scnd[i] << '\n';
}