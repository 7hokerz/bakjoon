#include <iostream>
using namespace std;

int dp[10001];//1~k원의 경우의 수
int inp[101];//동전의 가치
/*
못 풀고 본 문제. 이런 문제는 어떠한 수(inp)로 어떤 수(dp)를 만들 수 있는 경우부터 생각해보자
*/
int calc(int n, int k){
    //if(dp[n] != 0) return dp[n];이거 빼줘야한다.
    for(int j = inp[n];j<k+1;j++){
        //j원(inp[n]원)으로 동전을 만들 수 있다면 dp[j]는 dp[j-inp[n]]에서 j원을 더해 만든 경우로 생각하자.
        //즉, 가능한 경우의 수가 dp[j-inp[n]]만큼 있을 수 있다는 얘기
        dp[j] += dp[j-inp[n]]; 
    }

    return dp[n];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    dp[0] = 1;//동전을 아예 선택하지 않는 경우도 하나의 경우의 수이다.(0원을 만들 수 있는 경우를 생각해보자)
    int n, k, input;
    cin >> n >> k;

    for(int i = 1;i<n+1;i++){
        cin >> input;
        inp[i] = input;
    }
    for(int i = 1;i<n+1;i++){
        calc(i, k);
    }
    cout << dp[k];
}   
/*
dp[k] k원이 될 수 있는 경우의 수
inp[n] n가지 동전의 가치를 담은 배열

1원:1 1
2원:11 2 2
3원:111 12 2
4원:1111 112 22 3
5원:5 11111 1112 122 3
...
*/