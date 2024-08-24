#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string input;
    cin >> input;
    while(1){
        bool errcnt = false;
        for(int i = 1;i<input.length()+1;i++){//i는 셀 글자 수
            string tmp = "";
            for(int j = 0;j<input.length()+1-i;j++){
                tmp = "";
                for(int h = j;h<j+i;h++){
                    tmp += input[h];
                }
                //cout << sqrt(stoi(tmp)) << ' ';
                double val = sqrt(stod(tmp));
                if(val - (long long)val == 0){
                    //cout << "제곱 ㄷㄷ수가 아님" << '\n'; 
                    errcnt = true;
                    break;
                }
            }
            if(errcnt){
                input = to_string(stol(input)+1); i = 1;
                break;
            }
        }
        if(!errcnt){
            cout << input;
            break;
        }
    }
}
/*
1. 어떤 수를 루트했을 때 정수가 나오면 제곱 ㄷㄷ수가 아님
2. 문자열에 1,4,9가 포함되면 아니다.
22,23,26,27,28...(25는 5의 제곱)
쉽게 보면 부분 문자열이 루트값을 취했을 때 정수가 나오는지 확인하자.

*/