#include <iostream>
#include <string>
using namespace std;

//x는 1~4 2~5 3~6 7~8
//y는 2~4 3~7 1~5 3~6

//다른 질문 참고했음: 2차원 배열로 도형이 차지하는 곳에 1, 아니면 0 표시
//겹쳐도 어차피 0인 곳은 1이 되고, 1인 곳은 1 그대로다.

int main(){
    int arr[101][101];//직사각형이 들어가는 배열
    int mix, miy, max, may;
    int res = 0;

    for(int k = 0;k < 4;k++){
        cin >> mix >> miy >> max >> may;

        for(int i = miy;i < may;i++){
            for(int j = mix;j < max;j++){
                if(arr[i][j] == 0){
                    arr[i][j] = 1;
                    res++;
                }
            }
        }
    }   
    cout << res;
}