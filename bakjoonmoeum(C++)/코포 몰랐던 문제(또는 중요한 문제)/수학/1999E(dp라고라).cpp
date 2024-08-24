#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll;  typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;

int T;
ll arr[27];

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> T;
    ll val = 1;
    for(int i = 1;i<27;i++){//미리 값 다 채워넣기
        arr[i] = val; val *= 3;
    }

    while(T--){
        ll l, r, ret = 0;
        cin >> l >> r;
        ll tmpl = l, tmpr = r;

        while(l > 0){
            l /= 3; r *= 3; ret++;
        }
        ll k = tmpl + 1;

        while(k < tmpr){
            for(int j = 0;j<26;j++){
                if(k >= arr[j] && k < arr[j+1]) {//범위에 속하는 경우
                    if(tmpr > arr[j+1]) ret += j * (arr[j+1] - k);
                    else ret += j * (tmpr - k);
                    
                    k = arr[j+1];
                    break;
                }
            }
        }

        for(int j = 0;j<26;j++){
            if(r >= arr[j] && r < arr[j+1]) {ret += j; break;}
        }

        cout << ret << '\n';
    }
}
/*
3으로 나뉘지 않는 수를 처음에 먼저 나눠주는 게 가장 좋음.
곱하는 건 0을 곱한다(없으면 3의 배수를 곱한다.)
즉 먼저 가장 작은 수를 0으로 만든 후
나머지 수들을 0으로 만드는 횟수를 고려하면 된다.

요약: 가장 작은 수를 0으로 만들자. 곱하는 건 아무거나(0이 만들어지기 전까지는)

아래와 같은 패턴에 따라 최소 연산 횟수가 부여된다.
0 1 3 9 27 ...
0 1 2 3 4 ...
즉 1~2는 1, 3~8은 2...가 최소 연산 횟수라는 것

이전 풀이
for(int i = tmpl + 1;i<tmpr;){ 
    for(int j = 0;j<26;j++){
        if(i >= arr[j] && i < arr[j+1]) {//범위에 속하는 경우
            if(tmpr > arr[j+1]) ret += j * (arr[j+1] - i);
            else ret += j * (tmpr - i);
            //전처럼 일일이 +1 대신 바로 값을 다음 수 이전으로 옮겨준다.(시간 초과 해결)
            i = arr[j+1];
            //이 새끼 arr[j+1]에서 arr[j+1] - 1로 하니까 답 나오네...ㅋㅋㅋ 왜지?
            //왜냐면 i = arr[j+1] - 1로 부여한 후 i++이 되기 때문이다.
            //따라서 i = arr[j+1]로 하고 싶으면 반복문의 i++을 없애줘야 함.
            break;
        }
    }
}
*/