#include <iostream>
#include <vector>
using namespace std;

int N, S, input, cnt = 0;
int arr[21];

void dfs(int idx, int sum){
    if(idx == N+1){
        if(sum == S){
            cnt++;
        }
        return;
    }
    dfs(idx+1, sum);
    dfs(idx+1, sum+arr[idx]);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> S;
    for(int i = 1;i<N+1;i++){
        cin >> input;
        arr[i] = input;
    }
    dfs(1,0);
    if(S == 0) cnt--;
    //1 0 0이라 하자. 이 때 두 dfs가 재귀호출되는데 둘다 0이어서 cnt = 2가된다. 
    //하지만 이는 틀림. 크기가 양수인 부분수열을 구해야하므로 dfs(idx+1, sum);은 포함되면 안되기 때문
    cout << cnt;
}