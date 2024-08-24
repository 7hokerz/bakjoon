#include <iostream>
using namespace std;

void star(char r[1000][1000], int n, int row, int col){
    int lengthcol = 4*n-3;
    int lengthrow = lengthcol+2;
    if(lengthcol == 1){
        r[row][col] = '*';
        r[row+1][col] = '*';
        r[row+2][col] = '*';
    }else{
        for(int i = row;i<row+lengthrow;i++){
            for(int j = col;j<col+lengthcol;j++){
                if(i == row || i == row+lengthrow-1 || j == col || (j == col+lengthcol-1 && i != row+1)
                || (i == row+2 && j == col+lengthcol - 2)){
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
    if(N == 1){
        cout << '*';
        return 0;
    }
    for(int i = 0;i<4*N-1;i++){
        if(i == 1){
            cout << r[i][0];
        }else{
            for(int j = 0;j<4*N-3;j++){
                cout << r[i][j];
            }
        }
        cout << '\n';
    }
}
/*
특징: 별찍기 19와 거의 동일하나 한 부분의 별만 없음.
중요한 거: 한 줄의 마지막 별 이후에는 어떠한 출력도 없어야 함. 공백도 안됨.
그래서 틀렸다. ㅋㅋ
*/