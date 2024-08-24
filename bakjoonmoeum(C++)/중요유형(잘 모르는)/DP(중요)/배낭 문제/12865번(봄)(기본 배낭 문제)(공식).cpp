#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[101][100001];//물품 수(물품의 번호), 무게(최대 무게), 값: 최대 가치
vector <pair<int,int>> vt;//물건의 무게, 가치

int calc(int pos, int weight){//넣을 짐의 번호(위치), 넣을 수 있는 최대 무게
    
    if(vt[pos-1].first <= weight){//넣을 수 있는 무게인 경우
        dp[pos][weight] = max(dp[pos-1][weight], vt[pos-1].second + dp[pos-1][weight-vt[pos-1].first]);
        //넣는 경우와 넣지 않는 경우 중 더 가치가 큰 경우를 가져온다.
        //1. 넣지 않는 경우(pos-1의 경우를 가져옴.) 2. 넣는 경우(넣었을 경우 넣기 가능한 무게는 줄어드므로 그 넣기 가능한 때 무게의 최대 가치를 더해준다.)
        //2번의 경우 dp[pos]가 아닌 dp[pos-1]로 하는 게 중요! dp[pos]로 하면 넣었던 짐을 다시 넣을 수 없는데 넣어버려 누적되는 경우 발생
    }
    else{//넣을 수 없는 경우
        dp[pos][weight] = dp[pos-1][weight];
    }
    return dp[pos][weight];
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, k, w, v;//물품의 수, 최대 무게, 물품의 무게, 물품의 가치
    cin >> n >> k;//물품의 수, 최대 무게
    for(int i = 0;i<n;i++){
        cin >> w >> v;
        vt.push_back({w,v});
    }
    for(int i = 1;i<n+1;i++){
        for(int j = 1;j<k+1;j++){
            calc(i,j);
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << dp[n][k];
}   
/*

*/