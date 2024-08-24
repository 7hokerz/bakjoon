#include <iostream>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string input;
    string res = "";

    while(1){
        cin >> input;
        if(input == "E-N-D")break;

        for(int i = 0;i<input.length();i++){
            if(!isalnum(input[i]) && input[i] != '-'){//숫자, 알파벳이나 하이픈이 아닌 경우는 끊어야 하므로
                if(res.length() < input.substr(0,i).length()){//부분 문자열에 대한 비교
                    res = input.substr(0,i);
                }
                input.erase(0,i+1);//비교한 문자열은 지우기
                i=-1;//-1로 해야 인덱스 0부터 다시 조사한다.
            }
        }
        if(res.length() < input.length()){//더 길이가 긴 경우에만 삽입시킨다.
            res = input;
        }
    }
    for(int i = 0;i<res.length();i++){
        res[i] = tolower(res[i]);//소문자로
    }
    cout << res;
}
/*
실수했던 부분
1. 결과를 소문자로 출력하지 않은 것
2. 받은 문자열 중 조건을 제외한 다른 문자가 있는 경우 없애는 것 까진 좋았으나 그 후에 부분 문자열에 대한 비교 및 삽입을 하지 않은 점
*/