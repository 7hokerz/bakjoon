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

int n, one, dp[1001], LISarr[1001];
vector <int> vt;

void LIS(int num){
    if(dp[num] == 0){
        dp[num] = 1;

        for(int i = num - 1;i>=0;i--){
            if(vt[i] < vt[num]){
                dp[num] = max(dp[num], dp[i] + 1);
            }
        }
    }
}

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int maxnum = 0;
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> one;
        vt.push_back(one);
    }

    for(int i = 0;i<n;i++) LIS(i);
    for(int i = 0;i<n;i++) LISarr[i] = dp[i];
    fill(dp, dp+1001, 0);

    reverse(vt.begin(),vt.end());//벡터 뒤집기
    for(int i = 0;i<n;i++) LIS(i);//역 LIS(LDS 값을 반대로 누적시켜 LIS + LDS의 값을 현 인덱스에서 바로 구하기)

    reverse(dp, dp+n);//이때 dp는 원 배열 순서와 반대이므로 뒤집어야 한다.

    for(int i = 0;i<n;i++) maxnum = max(maxnum, LISarr[i] + dp[i]);
    
    cout << maxnum - 1;
}
/*
분명 아이디어까지 비슷하게 떠올리고 했는데 반례가 계속나와서 고전한 문제...

아이디어
바이토닉 부분 수열? 수열 S가 어떤 수 Sk를 기준으로 S1 < S2 < ... Sk-1 < Sk > Sk+1 > ... SN-1 > SN을 만족 시, 그 수열은 바이토닉 수열
쉽게 말해 증가하다가 감소, 증가하기만, 감소하기만 하는 3가지 경우가 존재할 수 있다는 거다.

한 줄 요약: LIS + LDS의 최댓값을 구하는 문제(분명 떠올렸는데, 구현 실수가 있었던 걸까)

과정:
1. LIS를 이용하여 모든 dp에 가장 긴 증가하는 부분 수열의 최대 값을 기록해준다.
2. dp값을 LISarr에 저장하여 기록하고 초기화한다. 역 LIS(LDS)를 구해야 하기 때문
3. 벡터를 뒤집고 LIS를 이용해 구한다.
이때 단순히 LDS로 하지 않은 이유? 최댓값을 구하려면 LIS최대 + LDS 최대를 구해야하는데, 
정방향으로 LDS 시 값이 이전 LIS와 동일 위치에 있지 않아 구하기 까다롭다.
따라서 역 LIS로 LDS를 구하면 이 때 해당 위치의 LIS 및 LDS의 값을 바로 구할 수 있기 때문이다.

요약: LIS + LDS의 값을 현 위치에서 바로 구하기 위해서(LIS 및 LDS는 뒤로 갈수록 값이 누적되는 성질이 있기 때문)

4. LIS + LDS의 모든 값을 구하여 최댓값을 찾는다.
5. 최댓값 - 1을 출력한다.
빼는 이유? 
1 2 3 2 1을 예로 들자. 이때 LIS는 123 3이고, LDS 321 3이다. 3이 중복되는 문제가 생기는데 이 때의 -1을 빼주는 것이다.
*/
