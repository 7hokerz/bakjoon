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

int N, M,input, one, two;
vector <int> gr[100001];
int score[100001], res[100001];

//서, 북, 동, 남, 남동, 북동, 북서, 남서 8방향
//int dx[] = {-1, 0, 1, 0};
//int dy[] = {0, -1, 0 ,1};

void dfs(int x, int sum){
    sum += score[x];//합을 더해준다.
    res[x] = sum;
    //cout << x << '\n';

    for(int i = 0;i<gr[x].size();i++){
        dfs(gr[x][i], sum);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i = 1;i<N+1;i++){
        cin >> input; if(input == -1)continue;
        gr[input].push_back(i);
    }
    for(int i = 1;i<M+1;i++){
        cin >> one >> two;
        score[one] += two;//**같은 사람이 칭찬을 여러 번 받을 수 있댄다...
    }

    dfs(1, 0);
    for(int i = 1;i<N+1;i++){
        cout << res[i] << ' ';
    }
}
/*
칭찬점수가 자식 노드에도 누적되도록 합을 score[x]를 더했다.
*/