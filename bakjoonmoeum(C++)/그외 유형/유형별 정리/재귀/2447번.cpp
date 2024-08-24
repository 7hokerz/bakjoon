#include <iostream>
using namespace std;

void star(char r[10000][10000], int length, int row, int col){
    for(int i = row+length/3;i<row+length/3*2;i++){
        for(int j = col+length/3;j<col+length/3*2;j++){
            r[i][j] = ' ';
        }
    }
    if(length == 3){
        for(int i = row;i<row+length;i++){
            for(int j = col;j<col+length;j++){
                if(i == row+1 && j == col+1) r[i][j] = ' ';
                else r[i][j] = '*';
            }
        }
    }
    else{
        star(r, length/3, row, col);
        star(r, length/3, row+length/3, col);
        star(r, length/3, row+(length/3*2), col);
        star(r, length/3, row, col+length/3);
        star(r, length/3, row, col+(length/3*2));
        star(r, length/3, row+length/3, col+(length/3*2));
        star(r, length/3, row+(length/3*2), col+length/3);
        star(r, length/3, row+(length/3*2), col+(length/3*2));
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    char r[10000][10000];
    star(r, N, 0, 0);
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            cout << r[i][j];
        }
        cout << '\n';
    }
}
/*

*/