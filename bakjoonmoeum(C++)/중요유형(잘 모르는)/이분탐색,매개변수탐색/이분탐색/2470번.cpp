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

ll N, input, one = 0, two = 0, res = (1 << 31) - 1;
vector <int> vt;

void bisearch(ll idx){
    ll start = idx + 1, end = N - 1, mid = 0;

    while(start <= end){
        mid = (start + end) / 2;
        ll val = vt[idx] + vt[mid];//두 용액의 합

        //cout << vt[idx] << ' ' << vt[mid] << ' ' << val << '\n';
            
        if(val > 0){//합이 0  초과면 낮추기
            end = mid - 1;
        }
        else if(val < 0){//합이 0 미만이면 올리기
            start = mid + 1;
        }

        if(res > abs(val)){
            res = abs(val); one = idx; two = mid;
        }
        if(val == 0) return;
    }
}

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 0;i<N;i++){
        cin >> input;
        vt.push_back(input);
    }
    sort(vt.begin(),vt.end());
    for(int i = 0;i<vt.size()-1;i++){//한 용액을 정하고 다른 용액은 이분 탐색으로 정하기
        bisearch(i);
    }

    cout << vt[one] << ' ' << vt[two];
}
/*
두 숫자를 합해서 0에 가장 가까운 경우를 만드는 경우
-99 -2 -1 4 98

 

*/



