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
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;

int N, M, input;
ll res = 0LL;
vector <int> vt;

void bisearch(){
    ll start = 0, end = vt[vt.size() - 1], mid = 0; //시작 길이, 마지막 길이, 중간 길이

    while(start <= end){
        ll sum = 0LL;//가질 수 있는 나무의 합
        mid = (start + end) / 2;

        for(int i = 0;i<vt.size();i++){
            if(vt[i] - mid > 0) sum += vt[i] - mid;
        }//cout << sum << ' ';

        if(sum >= M){//M미터 이상 가질 수 있는 경우
            start = mid + 1;//M을 만족하는 최대 높이를 구하기 위해 start 증가
            res = max(mid, res);//이 때는 조건을 만족하므로 res에 넣어준다.
        }
        else{//M미터 미만인 경우
            end = mid - 1;
        }
    }
}

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i = 0;i<N;i++){
        cin >> input;
        vt.push_back(input);
    }
    sort(vt.begin(),vt.end());
    bisearch();
    cout << res;
}
/*
start = 0; end = 최대 길이로 잡으면 mid는 그 중간 길이가 된다.
mid에서 시작하는데,

M이라는 조건을 만족하면 res에 값을 대입하고 start = mid + 1로 하고, 
만족하지 않으면 end = mid - 1로 한다.

mid라는 숫자가 조건을 만족한다, 하지 않는다로 볼 수 있으므로 그렇다.
mid가 만족하면 확인되지 않은 바로 다음 수인 mid + 1을 시작점으로 잡고,
만족하지 않으면 end = mid - 1로 시작해 수를 낮추면서 만족하는 지점을 찾게 된다.
*/



