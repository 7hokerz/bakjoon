#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string input; 
    cin >> input;
    if(input[0] == '0' && input[1] != 'x'){//8진수이면 
        char octa[input.length()];
        for(int i = 0;i<input.length();i++){
            octa[i] = input[i];//strtol 함수를 쓰기 위해 char배열에 담음
        } 
        cout << strtol(octa, NULL, 8);
    }else if(input[1] == 'x'){//16진수이면
        char hexa[input.length()-2];
        for(int i = 2;i<input.length();i++){
            hexa[i-2] = input[i];//strtol 함수를 쓰기 위해 char배열에 담음(단 0x부분을 제외하고)
        }
        cout << strtol(hexa, NULL, 16);
    }else{//10진수
        cout << stoi(input);
    }
}
/*
입력값으로 들어온 8,10,16진수를 10진수로 바꾸어 출력하는 방법
strtol 함수 이용
strtol(변환하려고 하는 문자열, NULL, 해당 문자열의 진법)
*/