#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll;  typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
#define INF 1e9

int T, N;

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> T;
    for(int k = 0;k<T;k++){
        cin >> N; int arr[31];
        for(int i = 1;i<N+1;i++) cin >> arr[i];
        
        if(N % 2) cout << "YES" << '\n';
        else{
            int we = 0, wd = 0, be = 0, bd = 0;
            for(int i = 1;i<N+1;i++){
                if(arr[i]){
                    if(i % 2) bd++;
                    else be++;
                }
                else{
                    if(i % 2) wd++;
                    else we++;
                }
            }//N이 짝수일 때 다음과 같이 또 나눠줘야 함.
            if(!(we % 2)){
                if((we == wd && be == bd)) cout << "YES" << '\n';
                else cout << "NO" << '\n';
            }
            else{
                if(abs(we-wd) > 1 || abs(be-bd) > 1) cout << "NO" << '\n';
                else cout << "YES" << '\n';
            }
        }
    }
}
/*
홀수일 땐 당연히 가능하다.

결국 짝수일 땐 검정의 짝수 번호와 홀수 번호의 개수가 동일하여야 함. 
+ 그리고 검정과 하양의 개수가 홀수일 수도 있다. 이땐 even과 odd 차이가 1을 넘어가면 안됨.

결국은 arr[i]와 arr[i+2]를 바꾸는 작업을 하는 것.

짝수일 땐 짝수 위치로만 옮기기 가능하다.

1 2 4 9 11 12 14 15 16 17
5개 5개

3 5 6 7 8 10 13 18
4개 4개

1 3 2 5 4 6 7 8

1 2 5 6 7 10 11 13
4개, 3개

1 2 3 4 5 6 7 9
*/