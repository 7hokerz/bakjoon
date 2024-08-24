#include <iostream>
using namespace std;

void star(char r[1000][1000], int n, int row, int col){
    int length = 4*n-3;
    if(length == 1){
        r[row][col] = '*';
    }else{
        for(int i = row;i<row+length;i++){
            for(int j = col;j<col+length;j++){
                if(i == col || i == row+length-1 || j == row || j == col+length-1){
                    r[i][j] = '*';
                }
                else{
                    r[i][j] = ' ';
                }
            }
        }
        star(r, n-1, row+2, col+2);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    char r[1000][1000];

    star(r, N, 0, 0);
    for(int i = 0;i<4*N-3;i++){
        for(int j = 0;j<4*N-3;j++){
            cout << r[i][j];
        }
        cout << '\n';
    }
}
/*
특징: 
1. n에 따른 길이는 4n-3씩 증가한다.
2. n-1의 첫 배열 좌표는 항상 [a+2,a+2]이다.
*/