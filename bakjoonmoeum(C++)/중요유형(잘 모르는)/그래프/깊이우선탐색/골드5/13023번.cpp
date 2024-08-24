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

int N,M,one,two;
vector <int> gr[2001];
bool visited[2001];

void dfs(int x, int cnt){
    if(cnt >= 5){
        cout << 1;
        exit(0);
    }
    
    visited[x] = true;
    for(int i = 0;i<gr[x].size();i++){
        if(!visited[gr[x][i]]){
            dfs(gr[x][i],cnt+1);
        }
    }
    visited[x] = false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i = 1;i<M+1;i++){
        cin >> one >> two;
        gr[one].push_back(two);
        gr[two].push_back(one);
    }
    for(int i = 0;i<N;i++){
        dfs(i,1);
        //visited[i] = false 이거 금지! 예제 2를 보면 알 수 있음. 
    }
    cout << 0;
}
/*


즉 최대 연결 노드 개수가 5 이상인 경우 1을 출력
8 8
1 7
3 7
4 7
3 4
4 6
3 5
0 4
2 7

0 >> 4
1 >> 7
2 >> 7
3 >> 4,5,7
4 >> 0,3,6,7
5 >> 3
6 >> 4
7 >> 1,2,3,4
*/