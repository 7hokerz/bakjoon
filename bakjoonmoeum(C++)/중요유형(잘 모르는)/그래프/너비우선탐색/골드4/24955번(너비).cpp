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
#define mod 1'000'000'007

int N, Q, one, two;
ll map[1001], input;
vector <int> gr[1001];
bool visited[1001];

int bfs(int start){
    queue <pll> q;//노드 번호, 값
    q.push({start,map[start] % mod});
    visited[start] = true;
    
    while(!q.empty()){
        int x = q.front().first;
        ll val = q.front().second;
        q.pop();

        if(x == two) return val;
        //최종 노드에 도달한 경우에만 값을 리턴하므로 도달하지 않은 경우는 영향을 미치지 않음.
        
        for(int i = 0;i<gr[x].size();i++){
            if(!visited[gr[x][i]]){
                q.push({gr[x][i],stoull(to_string(val) + to_string(map[gr[x][i]]))%mod});
                //기존 문자열에 새로운 문자열을 더한 후 이를 ull타입으로 변경 및 모듈러 연산
                visited[gr[x][i]] = true;
            }
        }
    } return 0;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> Q;
    for(int i = 1;i<N+1;i++){
        cin >> input;
        map[i] = input;
    }
    for(int i = 3;i<=N+1;i++){
        cin >> one >> two;
        gr[one].push_back(two);
        gr[two].push_back(one);
    }
    for(int i = N+2;i<=N+Q+1;i++){
        cin >> one >> two;
        cout << bfs(one) << '\n';
        for(int i = 1;i<N+1;i++) visited[i] = false;
        //**모든 visited가 true이므로 false로 변경 
    }
}
/*
같은 문제를 너비 탐색 우선으로 도전.

깊우탐과 달라진 점이 좀 있음.

크게 달라진 점은 문자열 구현이 아닌 계속 수를 mod로 나눠줌.
그 과정은
1. 기존 값은 숫자이므로 문자열로 바꾸고, 새로운 수도
문자열로 바꾼 후 합치기를 수행한다.
그 후 ull로 바꾼 후 mod연산을 수행한다.
*/