#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <stdlib.h>
#include <map>
#include <set>
using namespace std;
typedef long long ll; typedef unsigned long long ull;
typedef pair<int,int> pii; typedef pair<int,pii> rpii;//오른쪽 pii
typedef pair<pii,int> lpii;//왼쪽 pii
typedef pair<pii,pii> piiii;//더블 pii
typedef pair<ll, ll> pll;//long long pair
#define mod 1'000'000'009
#define INF 2'000'000'001

int A, B, K, visited[4'000'001][2], minnum = INF; 
ll res = 0;

int po(int val, int n){
    if(n == 0) return 1;
    if(n == 1) return val;

    int tmp = po(val, n/2);

    if(n % 2 == 0) return (tmp * tmp);
    else return (tmp * tmp) * val;
}

int calc(int x){
    if(visited[x][1]) return visited[x][1];//요놈이 큰 역할하네...ㅋㅋ
    int cnt = to_string(x).length();
    int sum = 0;
    int num = po(10, cnt-1);
    while(x > 0){  
        sum += po(x / num, K);
        x %= num;
        num /= 10;
    }
    return sum;
}

void dfs(int x){
    minnum = min(minnum, x);
    int sum = calc(x);
    
    if(!visited[sum][0]){
        visited[sum][0] = 1; visited[x][1] = sum;//nxt
        dfs(sum);
        visited[sum][0] = 0;
    }
    else{visited[x][1] = sum;}
}

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> A >> B >> K;
    for(int i = A;i<B+1;i++){
        dfs(i);
        res += minnum; //cout << minnum << ' ' << repmin << '\n';
        minnum = INF;
    }
    cout << res;
}
/*
(이전 풀이 참고)
visited를 기준으로 dfs 방문하므로 accu에 원하지 않는 값이 들어있어도 
이미 1번 dfs에서 수색하여 최솟값이 구해진 상태라서...

다시 검토해보니 accu값 자체가 필요가 없었다. 
단순 dfs를 돌리고 반복되는 부분이 존재하면 dfs를 돌리지 않음.
중요한 건 사이클이 길~게 반복되는 게 없는 듯하여, 이렇게 해도 되는듯? 

시간이 많이 걸렸던 큰 문제는 
자연수 N이 주어졌을 때, N의 각 자리수를 K제곱 한 후에 그 합을 구하는 함수를 SK(N)
위 부분에서 중복 계산이 많았던 게 문제라는거지.
그래서 visited[][1]에 기록을 시켜놓았고 값이 존재하면 바로 그 값을 반환시키게 하니까 되더라...

더 좋은 건 구간 최솟값을 저장시키는 거? 도 좋을 듯 하지만 아직 생각은 안난다.
*/