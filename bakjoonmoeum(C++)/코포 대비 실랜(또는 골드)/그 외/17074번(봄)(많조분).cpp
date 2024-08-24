#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll;  typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
#define INF 1e9
 
int dx[] = {-1, 0, 1, 0}; int dy[] = {0, -1, 0, 1};
 
int N, inp;

vector <int> num;

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> N;
    num.push_back(-1e9-1);//조건 성립을 위한 값
    for(int i = 0;i<N;i++){
        cin >> inp;
        num.push_back(inp);
    }
    int cnt = 0, pos = -1;
    num.push_back(1e9+1);//조건 성립을 위한 값

    for(int i = 2;i<N+1;i++){
        if(num[i-1] > num[i]){
            cnt++; pos = i;
        }
    }

    if(!cnt) cout << N;
    else if(cnt == 1){
        int ans = 0;
        if(num[pos-1] <= num[pos+1]) ans++;
        if(num[pos-2] <= num[pos]) ans++;
        cout << ans;
    }
    else cout << 0;
}
/*
어느 정도까지는 비슷하게 풀이를 따라갔으나 왜 5%틀 계속 나서 결국 풀이 봄...

내림차순이 2개 이상인 경우: 0
내림차순이 0개인 경우: N

내림차순이 1개인 경우:
1. 위치 저장
2. 조건 분기
조건:

예시: 4 6 5 7
1. pos-1 <= pos+1인 경우
5를 없애면 비내림차순인가?

2. pos-2 <= pos인 경우
6을 없애면 비내림차순인가?

결국은 조건을 확인해보면 조건 사이에 있는 수를 없애도 비내림차순이 가능한 지 확인하는 걸로 볼 수 있다.

실버1 랜덤은 역시 어려워...이거는 태그를 봤으면 더 못풀고 자빠졌을 듯.
*/