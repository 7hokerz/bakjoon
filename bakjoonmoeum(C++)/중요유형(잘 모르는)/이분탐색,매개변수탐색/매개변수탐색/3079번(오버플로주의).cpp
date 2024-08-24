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
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;

ll N, M, input, res = 1e18;
vector <ll> vt;

void bisearch(){
    ll start = 1, end = vt[N-1] * M, mid = 0;
    while(start <= end){
        mid = (start + end) / 2;
        ll sum = 0;
        for(int i = 0;i<N;i++){
            sum += (mid / vt[i]);
            if(sum > M) break;
            //중요. 이 구문을 추가하지 않으면 sum값이 한계를 넘어 오버플로가 발생할 수 있음.
        }

        if(sum >= M){
            res = min(res, mid);
            end = mid - 1;
        }
        else{
            start = mid + 1;
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

 

*/



