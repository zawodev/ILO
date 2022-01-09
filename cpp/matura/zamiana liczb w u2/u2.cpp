#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

int main(){
    int input;
    string output = "00000000";
    cin >> input;

    if (input < 0) {
        output[0] = '1';
        input += 128;
    }
    int bitCount = 8;
    int num = pow(2, bitCount - 2);
    int i = 1;
    while(num >= 1){
        cout << input << ' ' << num << '\n';
        if (input >= num){ 
            input -= num;
            output[i] = '1';
        }
        i++;
        num /= 2;
    }
    cout << output;
}