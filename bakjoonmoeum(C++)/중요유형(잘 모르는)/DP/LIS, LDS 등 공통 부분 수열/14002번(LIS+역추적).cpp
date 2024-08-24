#include <iostream>
#include <vector>
using namespace std;
/*
11053 문제와 똑같은 문제지만 다른 점은 모든 요소를 출력해야하는 점이다.

재귀함수부: dp배열을 2차원으로 만들고 첫 번째에는 최장 길이, 두 번째에는 inp[i]보다 작은 가장 가까운 인덱스를 저장한다.
(초기값은 0이고, LIS에 의하여 처음 호출되면 자기 자신 n을 저장한다.)
LIS를 한 번 호출하여 len에 값을 저장하고, 큰 경우에만 이전 인덱스를 갱신시킨다.

메인부:
길이를 구하는 법은 똑같고, 요소를 구할 땐 인덱스가 자기 자신을 가리킬 때 까지 과정을 반복한다.
dp 2번째엔 이전 인덱스가 저장되어 있으므로 idx를 매번 dp[idx][1]로 갱신시킨다.
이 때 인덱스가 자기 자신을 가리키는 경우 출력이 되지 않으므로 반복문 탈출 후 한 번 출력시켜준다.
탑 다운 방식이라 역순으로 들어가므로 반대로 출력시키면 된다.
*/
int LIS(int n, int dp[][2], int inp[]){
    if(dp[n][0] == 0){
        dp[n][0] = 1; dp[n][1] = n;

        for(int i = n-1;i>=0;i--){
            if(inp[i] < inp[n]){
                int len = LIS(i, dp, inp) + 1;
                if(len > dp[n][0]){
                    dp[n][0] = len;
                    dp[n][1] = i;
                }
                //dp[n][0] = max(dp[n][0], LIS(i, dp, inp) + 1);
            }
        }
    }
    return dp[n][0];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, input;
    cin >> n;
    int dp[n][2], inp[n];
    for(int i = 0;i<n;i++){
        cin >> input;
        inp[i] = input;
        dp[i][0] = 0;//최장 길이 저장
        dp[i][1] = 0;//idx 저장
    }
    for(int i = 0;i<n;i++) LIS(i, dp, inp);
    
    int max = dp[0][0], idx = 0;
    for(int i = 1;i<n;i++){
        if(dp[i][0]>max){
            max = dp[i][0];
            idx = i;
        }
    }
    cout << max << '\n';
    vector <int> vt;//일반 배열도 상관없지만 벡터가 조작하는 데에는 더 편리하다.
    while(idx != dp[idx][1]){
        vt.push_back(inp[idx]);
        idx = dp[idx][1];
    }
    if(idx == dp[idx][1]) vt.push_back(inp[idx]); 
    for(int i = vt.size()-1;i>=0;i--) cout << vt[i] << ' ';
}
