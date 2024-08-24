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

ll N, K, input, res = 0;
vector <int> vt;

void bisearch(){
    ll start = 1, end = vt[vt.size()-1], mid = 0;//랜선의 최소 최대 길이

    while(start <= end){
        ll sum = 0;
        mid = (start + end) / 2;
        if(mid == 0){//mid가 0이 될 수도 있으므로 예외 조건 걸기
            start = mid + 1; continue;
        }
        for(int i = 0;i<vt.size();i++){ 
            sum += vt[i] / mid;
        }
        if(sum >= N){//조건을 만족하는 경우
            start = mid + 1;
            res = max(res, mid);
        }
        else{
            end = mid - 1;
        }
    }
}

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> K >> N;
    for(int i = 0;i<K;i++){
        cin >> input;
        vt.push_back(input);
    }
    sort(vt.begin(),vt.end());
    bisearch();
    cout << res;
}
/*
N개 이상을 만들 수 있는 랜선의 길이 중 최대가 되는 것

mid값은 랜선의 중간 값이 될 것이고 sum은 랜선을 mid로 나눈 몫이다.
이때 sum이 N 이상이면 조건을 만족하므로 start를 증가
*/



