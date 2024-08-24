#include <iostream>
#include <stack>
using namespace std;

void div(int **arr,int row, int col, int length, int *w, int *b){
    bool cnt = false;
    if(length == 1){
        if(arr[row][col] == 0) (*w)++;
        else (*b)++;
    }else{
        for(int i = row;i<row + length - 1;i++){
            for(int j = col;j<col + length - 1;j++){
                if(arr[i][j] != arr[i][j+1] || arr[i][j] != arr[i+1][j] 
                || (arr[row+length-1][col+length-1] != arr[row+length-2][col+length-1])) {
                    div(arr, row, col, length/2, w, b);
                    div(arr, row+length/2, col, length/2, w, b);
                    div(arr, row, col+length/2, length/2, w, b);
                    div(arr, row+length/2, col+length/2, length/2, w, b);
                    cnt = true;
                }
                if(cnt) break;
            }
            if(cnt) break;
        }
    }
    if(!cnt && length != 1){
        if(arr[row][col] == 0) (*w)++;
        else (*b)++;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, val, cntw = 0, cntb = 0;
    cin >> N;
    int **paper = new int* [N];
    for(int i = 0;i<N;i++){
        paper[i] = new int [N];
    }

    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            cin >> val;
            paper[i][j] = val;
        }
    }
    
    div(paper, 0 , 0, N, &cntw, &cntb);
    
    cout << cntw << '\n' << cntb << '\n';
    for(int i = 0;i<N;i++){
        delete [] paper[i];
    }
    delete [] paper;
}
/*
패턴을 찾는 게 중요한 문제.
정사각형 안에 모두 같은 색이면 해당 색깔을++ 하고, 아니면 재귀 함수를 호출해야 하는 문제다.
중요한 건 어떻게 재귀함수를 짜냐인데, 정사각형이 각각 1/4씩 나눠진다.
즉 총 4개의 재귀함수가 필요하다.

함수의 입력값으로 배열, 행 위치, 열 위치, 길이, 하얀(포인터), 파란(포인터)을 잡았다.
행 위치, 열 위치는 스캔을 시작할 첫 위치고, 길이는 몇 칸이나 스캔할 지 기준이 된다.
그럼 어떻게 짜야할까?

총 4개의 재귀 호출이 필요한데
1. 행 위치, 열 위치가 0이고 길이는 n/2
2. 행 위치, 열 위치가 0, 0+n/2이고 길이는 n/2
3. 행 위치, 열 위치가 0+n/2, 0이고 길이는 n/2
4. 행 위치, 열 위치가 0+n/2, 0+n/2이고 길이는 n/2
이다. 
어차피 처음에 호출 시 0, 0으로 주니까 0일 땐 row, col 변수를 그대로 주면 된다.
*/