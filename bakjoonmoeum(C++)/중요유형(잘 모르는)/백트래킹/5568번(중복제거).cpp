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
vector <int> vt, arr;
vector <string> res;
bool visited[101];

void dfs(int idx, int cnt){
    if(cnt == M){
        res.push_back("");
        for(int i = 0;i<vt.size();i++) {
            res.back() += to_string(vt[i]);
        }
        return;
    }
    int pre = 0;
    for(int i = idx;i<N;i++){
        if(visited[i]) continue;
        if(pre != arr[i]){
            visited[i] = !visited[i];
            vt.push_back(arr[i]);
            pre = arr[i];
            
            dfs(0, cnt+1);

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


    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());//중복제거 함수
    cout << res.size();
}
/*
for(int i = 0;i<res.size();i++){
        cout << res[i] << '\n';
    }
*/