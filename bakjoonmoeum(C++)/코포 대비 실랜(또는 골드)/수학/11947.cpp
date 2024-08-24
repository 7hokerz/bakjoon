#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll;  typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
#define INF (1 << 30)

int dx[] = {-1, 0, 1, 0}; int dy[] = {0, -1, 0 ,1};

int T, N, M, inp, ret = 0;

ll arr[11];

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    arr[1] = 4;
    arr[2] = 49;//4,49,499,4999...
    for(int i = 3;i<11;i++){//누적 합
        arr[i] = arr[i-1] * 10 + 9;
    }

    cin >> T;
    while(T--){
        string str;
        cin >> str;

        //str로 받아 길이를 구하고 수로 변환
        ll num = 0, mx = 9;
        for(int i = 0;i<str.length();i++){
            int val = str[i] - 48;

            if(i != 0) { 
                mx *= 10; mx += 9;
            }
            num *= 10; num += val;
        }
        
        //배열에 저장된 수 보다 작으면 따로 최댓값을 구하고 그렇지 않으면 배열에 저장된 수로 값을 구하면 됨.
        if(arr[str.length()] <= num){
            cout << (mx - arr[str.length()]) * arr[str.length()] << '\n';
        }else{
            cout << (mx - num) * num << '\n';
        }
    }
}
/*
1 이상 N 이하인 수들 중 N * F(N)의 최댓값을 구하자.

이 특징을 알아야 함. 
두 수의 차이가 가장 적어야 두 수의 곱이 가장 크다.
*/