#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll;  typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
#define INF 1e9

int N, ans = 0;
int arr[1'000'001];

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> N;
    for(int i = 1;i<N+1;i++) cin >> arr[i];

    for(int j = 0;j<21;j++){
        int cnt = 0;
        for(int i = 1;i<N+1;i++){
            if(arr[i] & (1 << j)) cnt++;//비트가 1인 경우
        }
        ans = max(ans, cnt);
    }

    cout << ans;
}
/*
비트마스킹 개념의 중요성...

** AND연산 후 0이 되지 않으려면? 0이 존재하면 절대 안됨. 항상 1과 1끼리만 연산해야 함.
== 즉 AND 연산 시 결과가 1이 되려면 0이 존재하면 절대로 안된다.

즉 이 말은 어느 자리에서의 비트가 1인 수의 개수를 구하면 그 개수가 조건을 만족하는 가장 긴 부분 수열이라고 할 수 있다. (1인 경우만을 뽑은 것)

자릿수가 다르면 서로 독립적임.

각 자릿수마다 1인 비트의 개수를 구하고, 그 중 max 값이 답이 된다.
*/