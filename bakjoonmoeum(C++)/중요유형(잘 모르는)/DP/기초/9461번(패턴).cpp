#include <iostream>
using namespace std;
//값이 기하급수적으로 커지니 long long 타입을 써야함.
//패턴을 찾는 문제. 잘 찾아보면 P(N) = P(N-1) + P(N-5)임을 알 수 있다.
long long dp[102];

long long P(long long n){
    if(dp[n-1] != 0 && dp[n-5] != 0) return dp[n-1]+dp[n-5];
    if(n == 1 || n == 2 || n == 3){
        return 1;
    }else if(n == 4 || n == 5){
        return 2;
    }else{
         dp[n] = P(n-1)+P(n-5);
    }
    return dp[n];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T;
    long long N;
    cin >> T;
    for(int i = 0;i<T;i++){
        cin >> N;
        cout << P(N) << '\n';
    }
}