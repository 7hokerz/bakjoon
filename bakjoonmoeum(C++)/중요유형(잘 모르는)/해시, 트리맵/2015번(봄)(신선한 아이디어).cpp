#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll;  typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
#define INF (1 << 30)

int dx[] = {-1, 0, 1, 0}; int dy[] = {0, -1, 0 ,1};

int T, N, M, Q, P, L, K, inp; ll ret = 0;

unordered_map<ll,ll> m;//또는 트리맵

ll arr[200'001];

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> N >> K;
    for(int i = 1;i<N+1;i++){
        cin >> arr[i];
        arr[i] += arr[i-1];
        if(arr[i] == K) ret++;//1 ~ i 부분합
    }
    //arr[i] - arr[j-1] >> j부터 i까지의 부분합
    //arr[i] - arr[j-1] == K >> 부분합이 K
    //arr[i] - K == arr[j-1] >> 부분합 K를 만족하는 arr[j-1]

    for(int i = 1;i<N+1;i++){
        ll cur = arr[i];//1 ~ i 

        //arr[i]에 대하여 부분합 K를 만족시킬 수 있는 arr[j-1]의 개수를 더해준다.
        ret += m[cur - K];
        m[cur]++;
    }
    //요약: 현재 누적 합 - 이전 누적 합 == K가 되는 경우를 구하는 문제
    //중요 포인트: 누적 합이 나온 개수를 해시맵/트리맵에 증가시켜준다.

    cout << ret;
}
/*
누적합을 이용하여 1~i까지의 합을 미리 배열에 저장한다.

원래대로면 부분합을 구하는 데 O(N^2)이 걸려 시간 초과.
하지만 해시맵(트리맵)을 사용하면 그렇지 않다고 한다.

map<합, 개수> m >> 해당 합이 나온 개수를 저장하는 것
(사실은 배열을 이용해도 무리는 없을 것 같다.)

cur >> 1 ~ i의 합

cur - K >> cur에 대해 부분합 K를 만족시킬 수 있는 수 (arr[j-1]의 개수)

즉, m[cur - K]: cur에 대해 부분합 K를 만족시킬 수 있는 수의 개수

m[cur]++: 1 ~ i의 합이 나왔으므로 개수를 증가시키는 것이다.

6 5

1 3 6 10 15 15

1 1-5 = -4 
m[1]++ 0

3 3-5 = -2
m[3]++ 0

6 6-5 = 1
m[6]++ 1

10 10-5 = 5
m[10]++ 0

15 15-5 = 10
m[15]++ 1

15 15-5 = 10
m[15]++ 1

3
*/