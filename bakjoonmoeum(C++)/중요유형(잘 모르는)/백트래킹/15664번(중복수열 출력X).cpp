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

int N, M, input;
vector <int> vt;//순열을 담을 배열
vector <int> arr;//입력값 담을 벡터
bool visited[101];

void dfs(int idx, int cnt){
    if(cnt == M){
        for(int i = 0;i<vt.size();i++) {
            cout << vt[i] << ' ';
        }
        cout << '\n';
        return;
    }
    int pre = 0;
    for(int i = idx;i<N;i++){
        if(visited[i]) continue;
        if(pre != arr[i]){
            visited[i] = !visited[i];
            vt.push_back(arr[i]);
            pre = arr[i];
            
            dfs(i, cnt+1);

            visited[i] = !visited[i];
            vt.pop_back();
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M;
    for(int i = 1;i<N+1;i++){
        cin >> input;
        arr.push_back(input);
    }
    sort(arr.begin(),arr.end());
    dfs(0,0);
}
/*

*/