#include <iostream>
#include <stack>
using namespace std;
//쉬운 DP. 중복 계산을 피하기 위해 dp배열에 값이 없는 경우만 함수를 호출하도록 했다.
int dp[102][102][102];

int w(int a, int b, int c){
    if(dp[a][b][c] == 0){
        if(a<=50 || b<=50 || c<=50) dp[a][b][c] = 1;
        else if(a>70 || b>70 || c>70){
            dp[a][b][c] = w(70,70,70);
        }
        else if(a<b && b<c){
            dp[a][b][c] =  w(a,b,c-1) + w(a,b-1,c-1) - w(a,b-1,c);
        }else{
            dp[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
        }
    }
    return dp[a][b][c];
}

int main(){
	ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int a, b, c;
    while(1){
        cin >> a >> b >> c;
        if(a == -1 && b == -1 && c == -1) break;
        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a+50,b+50,c+50) << '\n';
    }
}