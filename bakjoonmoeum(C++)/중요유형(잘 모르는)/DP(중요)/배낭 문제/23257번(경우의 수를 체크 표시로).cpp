#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int N,M,A;//이전 월봉의 개수, 고른 월봉의 개수
vector <int> vt;
int dp[101][1024];
//월봉의 번호, 가능한 수에 대해 1로 표시
//해당 번호에서 몇 개를 뽑았을 때 그 수가 존재하는가?

void calc(int pos){
    dp[1][vt[pos-1]] = 1;
    for(int i = 1;i<M+1;i++){//고른 월봉에 대한 개수 부분. pos에 대한 고른 월봉의 개수 부분이 M까지 반복하면서 자동으로 누적된다.
        if(pos == 1){
            for(int j = 0;j<=1023;j++){
                if(dp[i-1][j]){
                    dp[i][vt[pos-1] ^ j] = 1;
                }      
            }
        }
        else{
            for(int k = 0;k<=1023;k++){
                if(dp[i-1][k]){
                    dp[i][vt[pos-1] ^ k] = 1;
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i = 0;i<N;i++){
        cin >> A;
        vt.push_back(abs(A));
    }
    for(int i = 1;i<N+1;i++){
        calc(i);
    }
    
    int res = 0;
    for(int k = 1023;k>=0;k--){
        if(dp[M][k]){
            res = max(k, res);
        }
    } 
    cout << res;
}   
/*
결국 방법을 보았다.
우선 내가 실수한 것은 "XOR연산의 최댓값 ^값 이 최대가 아닐 수 있다는 점"이다.
그래서 중요한 건 XOR연산의 모든 경우의 수를 XOR연산하고 해야한다는 점.

"제일 핵심은 [1024]의 배열을 만들어 단순히 check해주는 것이다." 그렇게 안하면 경우의 수를 일일이 나열하면 개수가 너무 많아지기 때문
그렇게 하면 2차원 배열로도 XOR연산을 수행하면서 결국 dp[최댓값 k] =1 인 지점이 존재할 것이고,
그 k가 답이 된다.

2차원 배열로 할 경우 고른 월봉의 개수에 대한 부분이 생략되는데, 어차피 함수에서 자동으로 연산하고 저장된다.

    고른 월봉의 개수
월봉    값:고른 월봉의 절댓값들을 xor한 것 중 가능한 
번호

그러면 3차원 배열 생각해보자

4 4
1 5 100 20
나올 수 있는 모든 XOR연산의 값
1   0   1   0 1*1
5   0,4     1,5, 5,1 2*2
100 0,97,101    100,5,1, 5,100,96, 1,96,100 3*3
20  0,112,97,101    20,100,5,1, 100,20,117,113, 117,5,100,96, 113,1,96,100 4*4
*/