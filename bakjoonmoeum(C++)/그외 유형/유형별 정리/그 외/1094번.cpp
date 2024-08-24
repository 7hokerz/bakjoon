#include <iostream>
using namespace std;

int main(){
    int stick = 64;
    int stickSum = 0;
    int res = 0;//결과값
    cin >> stickSum;

    while(1){
        if(stickSum < stick){//X보다 작을 때까지 절반으로 자른다
            stick /= 2;
        }

        if(stickSum >= stick){//조건을 만족하면 sticksum에서 stick의 길이와 가장 가까운 값을 빼준다.
            stickSum -= stick;
            stick /= 2;
            res++;
        }

        if(stickSum == 0){
            cout << res << endl;
            break;
        }

    }
}
