#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;

int N, first, cnt, input;
int map[101], visited[101];
bool ans[101];

void dfs(int x){
    visited[x] = true;

    if(!visited[map[x]]){//방문한 적 없는 경우 방문
        //cout << x << ' ' << map[x] << ' ';
        dfs(map[x]);
    }
    else{//방문 처리된 곳에 도착 시
        //cout << x << ' ' << map[x] << '\n';
        if(map[x] == first){
            cnt++;
            ans[first] = true;
        }
    }
    visited[x] = false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 1;i<N+1;i++){
        cin >> input;
        map[i] = input;
    } 
    for(int i = 1;i<N+1;i++){
        first = i;
        dfs(i);
    }
    cout << cnt << '\n';
    for(int i = 1;i<N+1;i++){
        if(ans[i]) cout << i << '\n';
    }
}
/*
숫자를 노드로 보고, 사이클을 구하는 문제
결국 어떤 사이클의 시작점과 끝 점이 같아야 한다. 그런 경우를 체크한다.

1>3 3>1 O >> 1
2>1 1>3 3>1 X
3>1 1>3 O >> 1
4>5 5>5 X
5>5 O >> 1
6>4 4>5 5>5 X
7>6 6>4 4>5 5>5 X
*/