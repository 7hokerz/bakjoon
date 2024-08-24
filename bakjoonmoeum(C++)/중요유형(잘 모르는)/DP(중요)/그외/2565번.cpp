#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<int,pii> rpii;//오른쪽 pii
typedef pair<pii,int> lpii;//왼쪽 pii
typedef pair<pii,pii> piiii;//더블 pii
typedef pair<ll, ll> pll;//long long pair
#define mod 1'000'000'007 
#define INF 1'999'990
//2차원 map 출력
#define printmap(row, col, map)      \
    for (int i = 1; i < (row) + 1; i++){   \
        for (int j = 1; j < (col) + 1; j++){  \
            cout << (map)[i][j] << ' ';  \
        }cout << '\n';                 \
    }\

int n, one, two, dp[10001][2];
vector <pair<int,int>> vt;

void LIS(int num){
    if(dp[vt[num].first][0] == 0){
        dp[vt[num].first][0] = 1;

        for(int i = num - 1;i>=0;i--){
            if(vt[i].second < vt[num].second){
                dp[vt[num].first][0] = max(dp[vt[num].first][0], dp[vt[i].first][0] + 1);
            }
        }
    }
}

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> one >> two;
        vt.push_back({one,two});
    }
    sort(vt.begin(),vt.end());

    for(int i = 0;i<n;i++) LIS(i); 
    
    int maxi = 0;

    for(int i = 0;i<vt.size();i++){
        maxi = max(maxi, dp[vt[i].first][0]);
        //cout << dp[vt[i].first][0] << ' ';
    }//cout << '\n';
    cout << n - maxi;
}
/*

LIS를 이용한 문제.
먼저 입력값 first를 기준으로 정렬
8 2 9 1 4 6 7 10

LIS를 이용하는데 이때 단순히 i라는 인덱스를 쓰면 안된다.
대신 vt[i].first를 이용해야 한다.
이유는 i는 입력값에서 없을 수도 있기 때문에 입력값인 vt를 이용해야 한다.

LIS의 길이를 구한 후, 전체 개수에서 LIS의 길이를 빼주면 된다.

*/