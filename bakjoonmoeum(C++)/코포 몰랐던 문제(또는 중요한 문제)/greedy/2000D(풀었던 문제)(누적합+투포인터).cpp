#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll;  typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
 
int dx[] = {-1, 0, 1, 0}; int dy[] = {0, -1, 0 ,1};

int T, N, M;
 
int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> T;
    while(T--){
        string str;
        cin >> N;
        ll arr[N+1];
        arr[0] = 0;
        for(int i = 1;i<N+1;i++){
            cin >> arr[i];
            arr[i] += arr[i-1];//누적 합
        }
        cin >> str;
        int l = 0, r = N-1;
        ll ret = 0;

        while(l < r){
            if(str[l] == 'L' && str[r] == 'R'){
                ret += arr[r+1] - arr[l];
                l++; r--;
            }
            else{
                if(str[l] == 'R') l++; 
                if(str[r] == 'L') r--;
            }
        }
        cout << ret << '\n';
    }
}
/*
l, r(l < r)을 선택하는 데, l L, r, R이어야 하고

l과 r 사이의 모든 값을 더하고 l과 r만 선택 불가 조치

4번 예제:
1과 5 선택
15
.RLR.
15 + 7 == 22
.R...

최대한 끝 쪽끼리 선택하는 게 유리?

양쪽에서 좁혀오는 투 포인터를 사용해야할 듯

풀이 설명:
L과 R을 선택할 때 L은 가장 왼쪽 R은 가장 오른쪽에서 선택하는 게 유리하다.
L과 R 사이에 있는 모든 점수를 얻기 때문이다.

누적 합을 사용한 이유? N은 최대 20만 >> 
모든 점수를 브루트포스로 일일이 더한다고 쳤을 때, 최악의 경우: 10만 * (20만 + 199998 + ...) >> 시간 초과

누적 합을 쓰면, arr[r+1] - arr[l] >> O(1)에 해결 가능

추가적으로, 결과 및 누적 합 배열의 요소는 int 범위를 초과할 수 있으므로 long long 자료형은 필수!


문제 설명: 
1부터 n까지의 번호가 매겨진 n개의 정수가 주어지고, 
길이 n의 문자열이 주어집니다. ("L" 또는 "R")

n개의 정수는 점수로 보고, 같은 위치의 문자와 매칭됩니다.

하나의 연산에서 두 인덱스 l과 r (l < r)을 선택할 수 있으며
l은 "L", r은 "R"의 문자가 선택되어야 합니다.

그리고 l과 r 포함 l과 r 사이에 있는 모든 문자의 점수를 더한 값을 현재 점수에 추가합니다.
그 후 선택했던 l과 r의 문자 자리에 .으로 대체하여 다시 선택할 수 없도록 합니다.

예시: 
3 5 1 4 3 2
L R L L L R

= 18 

먼저 l=1, r=2를 선택하여 점수 3+5=8을 추가할 수 있습니다.

3 5 1 4 3 2
. . L L L R

그 다음 l=3, r=6을 선택하여 점수 1+4+3+2=10을 추가할 수 있습니다.

3 5 1 4 3 2
. . . L L .

추가적인 연산을 수행할 수 없으므로 최종 점수 = 18입니다.
모든 연산을 수행해서 얻을 수 있는 최대 점수는?
*/