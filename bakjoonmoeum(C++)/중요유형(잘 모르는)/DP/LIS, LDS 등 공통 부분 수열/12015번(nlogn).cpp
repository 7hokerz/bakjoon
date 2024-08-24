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
#include <map>
using namespace std;
typedef long long ll; typedef unsigned long long ull;
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
    }cout << '\n'; \
//3차원 map 출력
#define printmap3(row, col, select, map)      \
    for (int i = 1; i < (row) + 1; i++){   \
        for (int j = 1; j < (col) + 1; j++){  \
            cout << (map)[i][j][select] << ' ';  \
        }cout << '\n';                 \
    }cout << '\n'; \

int N, input;
vector <int> vt, LIS;

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 0;i<N;i++){
        cin >> input;
        vt.push_back(input);
    }
    LIS.push_back(vt[0]);
    for(int i = 1;i<N;i++){
        int idx = lower_bound(LIS.begin(), LIS.end(), vt[i]) - LIS.begin();
        //cout << idx << ' ';
        if(idx == LIS.size()){
            LIS.push_back(vt[i]);
        }
        else{
            LIS[idx] = vt[i];
        }
    }
    cout << LIS.size();
}
/*
DP >> O(N^2)이라 풀 수 없음.

인터넷 참고함.

대신 이분 탐색으로 활용 가능.

과정:
1. LIS 배열 첫 번째에 첫 원소 삽입
2. lower_bound()를 이용하여 처음으로 vt[i]보다 커지는 부분의 인덱스를 찾고, 해당 인덱스에 vt[i]를 삽입
3. 만약 vt[i]가 LIS배열에서 가장 큰 수면 LIS 마지막에 새로 vt[i] 삽입
4. 위의 과정을 반복하고, LIS에 있는 요소의 개수는 곧 최장 증가 부분 수열의 길이가 된다.

(하지만 위의 방식으로는 최장 증가 부분 수열 자체를 출력할 수는 없음.)

수열까지 출력하고 싶다면 14003번 풀이 참고.
*/