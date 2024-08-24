#include <iostream>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M, cntW = 0, cntB = 0, res = -1;
    cin >> N >> M;
    char chessW[8][8] = {
        {'W','B','W','B','W','B','W','B'}, 
        {'B','W','B','W','B','W','B','W'},
        {'W','B','W','B','W','B','W','B'}, 
        {'B','W','B','W','B','W','B','W'},
        {'W','B','W','B','W','B','W','B'}, 
        {'B','W','B','W','B','W','B','W'},
        {'W','B','W','B','W','B','W','B'}, 
        {'B','W','B','W','B','W','B','W'}
    };
    char chessB[8][8] = {
        {'B','W','B','W','B','W','B','W'},
        {'W','B','W','B','W','B','W','B'},
        {'B','W','B','W','B','W','B','W'},
        {'W','B','W','B','W','B','W','B'},
        {'B','W','B','W','B','W','B','W'},
        {'W','B','W','B','W','B','W','B'},
        {'B','W','B','W','B','W','B','W'},
        {'W','B','W','B','W','B','W','B'},
    };
    char input[N][M];

    for(int i = 0;i<N;i++){
        cin >> input[i];
    }

    for(int k = 0;k<N-7;k++){
        for(int h = 0;h<M-7;h++){
            int countN = 0, countM = 0;
            for(int i = k;i<k+8;i++){
                for(int j = h;j<h+8;j++){
                    if(input[i][j] != chessW[countN][countM]) cntW++;
                    if(input[i][j] != chessB[countN][countM]) cntB++;
                    countM++;
                }
                countN++; countM = 0;
            }
            cntW = (cntW<cntB)?cntW:cntB;
            if(res == -1) res = cntW;
            else res = (res<cntW)?res:cntW;
            cntW=0; cntB=0;
        }
    }
    cout << res;
}
/*
    BWBW
    WBWB
    BWBW
    WBWB
*/