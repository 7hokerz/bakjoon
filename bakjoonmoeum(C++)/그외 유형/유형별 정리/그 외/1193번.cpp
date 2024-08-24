#include <iostream>
using namespace std;

int main(){
    int X = 0;
    int i = 0;
    int max = 0, min = 0;
    cin >> X;

    while(max<X){//max 및 min 구하기
        max += i++;
        if(max>=X){
            min = max - --i;
        }
    }
    if(i%2 == 0){//지그재그라서 홀수 짝수 구분으로 구해야 함
        cout << X - min << '/' << max - X + 1;
    }else{
        cout << max - X + 1 << '/' << X - min;
    }

}
