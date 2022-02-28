#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

int main(){
    int tab[1000];
    int i = 0;
    ifstream dane("dane4.txt");
    int x;
    while (dane >> x) tab[i++] = x;
    int n = i;
    cout << n << '\n';
    int luka[1000];
    for (int i = 1; i < n;i++){
        luka[i] = abs(tab[i] - tab[i - 1]);
    }
    int maxlu, minlu;
    maxlu = minlu = luka[1];
    for(int i = 2; i < n; i++){
        if (luka[i] > maxlu) maxlu = luka[i];
        if (luka[i] < minlu) minlu = luka[i];
    }

    cout << "Najwieksza luka: " << maxlu << '\n';
    cout << "Najmniejsza luka: " << minlu << '\n';

    int maxdl, dl, maxil, il;
    dl = maxdl = 1;
    il = maxil = 1;
    for (int i = 2; i < n; i++){
        if(luka[i] != luka[i]){
            if(dl > maxdl){
                maxdl = dl;
                maxil = il;
            }
            dl = 0;
            il = i;
        }
        dl++;
    }
    if(dl > maxdl){
        maxdl = dl;
        maxil = il;
    }
    cout << "Dlugosc maksymalnego ciagu regularnego:" << maxdl + 1 << '\n';
    cout << "Poczatek: " << tab[maxil - 1] << '\n';
    cout << "Koniec: " << tab[maxil - 1 + maxdl] << '\n';
}