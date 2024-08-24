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

int dx[] = {1,-1, 0, 0}; int dy[] = {0, 0, 1, -1};

int A, B, K, visited[4'000'001][2], accu[4'000'001];
int minnum = INF, repmin = INF; 
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

void repdfs(int x){
    repmin = min(repmin, x);

    if(!accu[x]){
        accu[x] = repmin;
        repdfs(visited[x][1]);
    }
    else repmin = min(repmin, accu[x]);
}

void dfs(int x){
    minnum = min(minnum, x);
    int sum = calc(x);
    
    if(!visited[sum][0]){
        visited[sum][0] = 1; /*if(!visited[x][1])*/visited[x][1] = sum;//nxt
        dfs(sum);
        visited[sum][0] = 0;
    }
    else{ 
        visited[x][1] = sum;
        repdfs(sum);
    }
}

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> A >> B >> K;
    for(int i = A;i<B+1;i++){
        dfs(i);
        res += min(minnum, repmin);
        minnum = repmin = INF;
    }
    cout << res;
}
/*
구현 및 시간적인 부분에서 많이 애를 먹었던 문제.





반복되는 부분에 대한 최솟값을 기록하는 방법?


1 5 2
1 ~ 5 를 2제곱

1 >> 1 >> 1..
2 >> 4 >> 16 >> 1+36=37 >> 9+49=58 >> 25+64=89
64+81=145 >> 1+16+25=42 >> 16+4=20 >> 4...부터 반복

int po(int val, int K){이거나 저거나 거기서 거기...어차피 K가 작기 때문이다.
    int tmp = val;
    for(int i = 1;i<K;i++){
        val *= tmp;
    }
    return val;
}
*/