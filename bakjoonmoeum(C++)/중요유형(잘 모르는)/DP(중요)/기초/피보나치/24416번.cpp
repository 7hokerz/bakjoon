#include <iostream>
#include <stack>
using namespace std;
/*
fib코드를 결국 바꿔서 풀어야 하는데 이게 DP를 이용한 풀이인지 잘은 모르겠다.
DP를 이용한 풀이는 아니었다. 
DP를 이용하려면 dp배열을 만들고 거기다 계산한 값을 저장하고 값이 저장되어있으면 호출하는 것으로 풀 수 있다.
*/

int n, f[41] = {0}, cntfib = 0;

void fib(int n) {
    if (n == 1 || n == 2) {
        cntfib++;
    }
    else{
        fib(n - 1);
        fib(n - 2);
    }
}

void fibonacci(int n) {
    f[1] = f[2] = 1;
    int cnt = 0;
    for(int i = 3;i<=n;i++){
        cnt++;
        f[i] = f[i - 1] + f[i - 2]; 
    }
    cout << cnt;
}

int main(){
	ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    fib(n);
    cout << cntfib << '\n';
    fibonacci(n);
}