#include <iostream>
#include <string>
using namespace std;
int chk[5][14];//P,K,H,T, 카드의 번호

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string input;
    cin >> input;
    
    for(int i = 0;i<input.length();i+=3){//카드의 번호를 확인해 개수를 추가
        int num = stoi(input.substr(i+1,2));
        if(input[i] == 'P'){
            chk[1][num]++;
        }
        else if(input[i] == 'K'){
            chk[2][num]++;
        }
        else if(input[i] == 'H'){
            chk[3][num]++;
        }
        else if(input[i] == 'T'){
            chk[4][num]++;
        }
    }
    int numarr[4];
    for(int i = 1;i<5;i++){
        int cnt = 0;
        for(int j = 1;j<14;j++){
            if(chk[i][j] > 1){//2개 이상인 카드
                cout << "GRESKA";
                return 0;
            }else if(chk[i][j] == 0){//없는 카드
                cnt++;
            }
        }
        numarr[i-1] = cnt;
    }
    for(int i = 0;i<4;i++){
        cout << numarr[i] << ' ';
    }
}
/*
입력값이 패턴이 3개씩으로 정해져 있으므로 단순히 3개씩 끊으면 된다.
*/