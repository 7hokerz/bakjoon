#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

int main() {
    string input;
    string tmp;
    string res;
    cin >> input;
    if(input == "0"){
        cout << 'W';
        return 0;
    }
    for(int i = 0;i<input.length();i++){
        if(input[i] == 'x'){
            tmp += input.substr(0,i);
            if(stoi(tmp)/2 == -1) res += '-';
            else if(stoi(tmp)/2 != 1) res += to_string(stoi(tmp)/2);
            res += "xx";
        }else if(input[i] == '+' || (input[i] == '-' && i != 0)){
            res += input[i];
            if(stoi(input.substr(i,input.length()-1)) == -1)  res += input.substr(i+2,input.length()-1);
            else if(stoi(input.substr(i,input.length()-1)) != 1) res += input.substr(i+1,input.length()-1);
            res += 'x';
        }
    }
    if(res == ""){
        if(stoi(input) == -1) res += input.substr(0,1);
        else if(stoi(input) != 1) res += input;
        res += 'x';
    }
    res += "+W";
    cout << res;
}