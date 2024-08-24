#include <iostream>
#include <cmath>
using namespace std;

void visit(int length, int row, int col, int *cnt, int r, int c){
    if(length == 2){
        for(int i = row;i<row+length;i++){
            for(int j = col;j<col+length;j++){
                if(i == r && j == c) {
                    cout << *cnt;
                    break;
                }
                (*cnt)++;
            }
        }
    }else{
        if(r < row+length/2 && c < col+length/2){
            visit(length/2, row, col, cnt, r, c);
        }else if(c < col+length/2){
            (*cnt) += (length/2)*(length/2)*2;
            visit(length/2, row + length/2, col, cnt, r, c);
        }else if(r < row+length/2){
            (*cnt) += (length/2)*(length/2);
            visit(length/2, row, col + length/2, cnt, r, c);
        }else{
            (*cnt) += (length/2)*(length/2)*3;
            visit(length/2, row + length/2, col + length/2, cnt, r, c);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, r, c;
    int cnt = 0;
    cin >> N >> r >> c;
    visit(pow(2,N), 0, 0, &cnt, r, c);
}