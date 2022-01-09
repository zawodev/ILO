#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    fstream data;
    data.open("dane.txt");
    int rr;
    
    //zad6.1
    int minn = 256;
    int maxx = 0;
    
    for(int i=0; i<200;i++){
        for(int j=0; j<320;j++){
            data >> rr;
            if(rr > maxx) maxx = rr;
            if(rr < minn) minn = rr;
        }
    }
    
    cout << "6.1 Min: " << minn << ", Max: " << maxx << "\n";
    
    
    //zad6.2
    
    fstream data2;
    data2.open("dane.txt"); 
    int rr2;
    int T [205][325];
    
    for(int i = 0; i < 200; i++){
        for(int j = 0; j < 320; j++){
            data2 >> rr2;
            T[i][j] = rr2; 
        }
    }
  
    int k;
    int s = 1;
    int score2 = 0;

    for(int i = 0; i < 200; i++){
        s = 1;
        for(int j = 0; j < 160; j++){
            k = 319 - j;
            if(T[i][j] != T[i][k]){
                s = 0;
            }            
        }
        if(s == 0) score2++;
    }
       
    cout << "6.2 Nalezy usunac " << score2 << " wierszy.\n";

    // zad6.3 
    
    int konCount = 0;
    int konn;
    int diff;
    
    for(int i=0; i<200;i++){
        for(int j=0; j<320;j++){
            
            konn = 0;
            if(j > 0){
                diff = T[i][j] - T[i][j-1];
            }
            if(j < 319){
                diff = T[i][j] - T[i][j+1];
            }
            if(i > 0){
                diff = T[i][j] - T[i-1][j];
            }
            if(i < 199){
                diff = T[i][j] - T[i+1][j];
            }

            if(diff < 0) diff = -diff;
            if(diff > 128) konn = 1;

            if(konn == 1) konCount++;            
        }
    }
    
    cout << "6.3 Ilosc pikseli kontrastujacych wynosi: " << konCount << "\n";

    //zad6.4
    
    int longest = 1;
    int longesttmp = 1;
    int last;
    
    for(int j = 0; j < 320; j++) {
        for(int i = 0; i < 200; i++) {
            if(i == 0) {
                last = T[i][j];
                longesttmp = 1;
            }
            else{
                if(T[i][j] == last) {
                    longesttmp++;
                }
                else {
                    if(longesttmp > longest) longest = longesttmp;
                    longesttmp = 1;
                }
            }
        }
    }
    
    cout << "6.4 Najdluzszy ciag: " << longest << "\n";
}