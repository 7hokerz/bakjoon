#include <iostream>
#include <algorithm>
using namespace std;

int dp[101][10];//a:길이 b:마지막 자리수, 값: 계단의 수

int calc(int n, int num){//길이, 마지막 자리수
    if(n == 1 || dp[n][num] != 0) return dp[n][num]%1000000000;

    if(num == 9) 
        dp[n][num] = calc(n-1,num-1);
    else if(num == 0) 
        dp[n][num] = calc(n-1,num+1);
    else 
        dp[n][num] = calc(n-1,num-1) + calc(n-1,num+1);

    return dp[n][num]%1000000000;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N, input;
    cin >> N;
    for(int i = 1;i<10;i++) dp[1][i] = 1;
    //길이가 1일 때는 수가 1개밖에 들어올 수 없으므로 
    for(int i = 2;i<N+1;i++){
        for(int j = 0;j<10;j++){
            calc(i,j);
        }
    }
    int res = 0;
    for(int i = 0;i<10;i++){
        res += (dp[N][i])%1000000000;
        res %= 1000000000;
    }
    cout << res;
}   
/*
이리저리 하다 모르겠어서 방법 봄.
dp[a][b] a:길이 b:마지막 자리의 수, 값: 계단수를 만족하는 총 개수
우선 a가 1일 땐 항상 총 개수는 1만 나오므로 dp[1][i] = 1로 초기화하고 나머진 0으로 초기화한다.
a가 2일 때부터 재귀함수를 반복문으로 호출한다.

중요한 조건: num = 0, num = 9일 땐 2가지의 경우를 호출할 수 없다. 1가지만 호출하도록 한다.
나머지의 경우 (n-1, num-1) 과 (n-1, num+1)로 가능한 수의 재귀함수를 호출한다.
그리고 n==1이라면 저장된 dp값을 리턴해준다. 이 조건을 추가하지 않으면 오류 발생

모든 과정이 끝나면 dp[N]에 최종적인 값이 담기게 되는데, 자릿수마다의 값을 모두 합해주면 된다.

**오버플로가 쉽게 발생하므로 조건에 있는 10억으로 나누는 모듈러 연산을 잘 쓰자.
*/