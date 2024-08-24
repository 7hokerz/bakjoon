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

string a, b;
int LCS[1001][1001];
vector <char> res;

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> a >> b;
    for(int i = 1;i<a.length()+1;i++){
        for(int j = 1;j<b.length()+1;j++){
            if(a[i-1] == b[j-1]){
                LCS[i][j] = LCS[i-1][j-1] + 1;
            }
            else{
                LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
            }
        }
    }
    int x = b.length(); int y = a.length();
    //printmap(a.length(), b.length(), LCS);
    cout << LCS[y][x] << '\n';

    while(LCS[y][x] != 0){
        //위쪽, 왼쪽의 우선순위를 꼭 어느 곳으로 둘 필요는 없음.
        //단 결과 값이 다를 수 있음. 어차피 같은 길이이므로 
        //큰 상관 없을 듯 함.
        if(LCS[y][x] == LCS[y-1][x]){
            y--;
        }
        else if(LCS[y][x] == LCS[y][x-1]){
            x--;
        }
        else{
            res.push_back(b[x-1]);
            y--; x--;
        }
    }
    reverse(res.begin(),res.end());
    for(int i = 0;i<res.size();i++){
        cout << res[i];
    }
}
/*
LCS: 최장 공통 부분 수열
1. 문자열 A와 B를 한 글자씩 비교한다.
2. 두 문자가 다르면 LCS[i-1][j], LCS[i][j-1]중 큰 값을 LCS[i][j]에 삽입
3. 두 문자가 같으면 LCS[i-1][j-1] + 1을 LCS[i][j]에 삽입

부분 수열은 공통 문자열과 다르게 연속될 필요가 없다.
따라서 이전에 기록된 부분 수열의 최장 거리는 유지된다.
(값이 누적된다는 뜻)

****2의 이유:
현재 공통 부분 수열을 비교하기 전 과정이 바로
LCS[i-1][j]와 LCS[i][j-1]이다.

AB와 GBC를 예시로 들면, 
A와 GBC, AB와 GB를 비교하는 것과 같다.
여기서 AB와 GB의 공통 문자가 1이므로 
이 중 최댓값인 1이 LCS[i][j]에 저장되는 것이다.

**3의 이유:
ABC와 GBC를 비교한다고 치자.
이 때 AB와 GB를 비교할 때와 달라진 점은? 
모두 뒤에 C가 추가되었다는 것이다.
따라서 길이가 모두 1 증가하면서 공통 문자가 존재하므로
LCS[i][j] = LCS[i-1][j-1] + 1의 공식이 성립한다.

예시
ACAYKP
CAPCAK

  C A P C A K
A 0 1 1 1 1 1
C 1 1 1 2 2 2
A 1 2 2 2 3 3
Y 1 2 2 2 3 3
K 1 2 2 2 3 4
P 1 2 3 3 3 4

이때 LCS[a.length()][b.length()]가 답이 된다.
*/