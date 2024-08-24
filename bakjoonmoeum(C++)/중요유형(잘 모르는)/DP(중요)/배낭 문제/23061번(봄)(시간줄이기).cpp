#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int K[101];
int n, m, w, v, k, maxk = 0;
int dp[1000001];//가방의 수(번호), 무게(물품의 수는 1차원 배열로도 해결 가능)
vector <pair<int,int>> vt;//물품의 무게, 가치
void calc(int pos){
    for(int i = maxk;i >= vt[pos-1].first;i--){
        dp[i] = max(dp[i], vt[pos-1].second + dp[i-vt[pos-1].first]);
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0;i<n;i++){
        cin >> w >> v;
        vt.push_back({w,v});
    }

    for(int i = 1;i<m+1;i++){//제일 큰 K를 구한다.
        cin >> k;
        maxk = (maxk>k)?maxk:k;
        K[i] = k;//나중에 효율성 계산을 위해 저장해둔다.
    }
    for(int j = 1;j<n+1;j++) calc(j);//어차피 물품의 개수가 변하지 않으므로 한 번만 돌려도 된다.
    
    double maxsum = 0.0, idx = 0;
    for(int i = 1;i<m+1;i++){
        if((dp[K[i]]*1.0)/(K[i]*1.0)+0.5>maxsum){//각각 무게일 때의 최댓값으로 효율성을 구해서 최대의 효율성을 갖는 값을 구해준다.
            maxsum = (dp[K[i]]*1.0)/(K[i]*1.0)+0.5;
            idx = i;
        }  
    }
    cout << idx;
}   
/*
그래도 푸는 듯 했으나 결국 봄....ㅅㅂ

중요한 점: 평범한 베낭 문제와 다를 거 없지만 가방의 개수가 추가되었다.
이때 단순히 가방의 개수만큼 더 반복문을 도는 순간 시간초과다.

블로그로 보면서 얻은 팁은 어차피 가방의 개수와 상관없이 어떤 가방보다 큰 인덱스 dp에 저장되는 값은 물품이 같으면 같다.
**그러므로 최대 가방 무게를 기준으로 삼고 평범한 배낭처럼 똑같이 돌리면 된다.
그리고 dp[K]의 값이 가방의 최대 무게가 K일 때 최대 가치가 된다.

효율성의 경우는 실수로 만들지 않을 수도 있지만 나는 실수 형태로 계산 후에 0.5를 더해 오차를 줄이는 방식을 택했다.

(배낭 문제는 그냥 기본부터 다진 후에 더 풀자...)
알아낸 것: 배낭의 최대 무게와 상관 없이 물품들이 동일하면 W에 따른 최대 가치는 같다.
*/