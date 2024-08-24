#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <pair<int,int>> vt;//드는 비용, 얻는 고객의 수
int C, N, a, b;//고객의 수, 도시의 수, 도시의 홍보 비용, 얻을 수 있는 고객
int dp[100001];//돈, 값: 최대 고객의 수

void calc(int pos){
    for(int i = vt[pos-1].first;i<100001;i++){
        dp[i] = max(dp[i], vt[pos-1].second + dp[i-vt[pos-1].first]);
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> C >> N;
    for(int i = 0;i<N;i++){
        cin >> a >> b;
        vt.push_back({a,b});
    }
    for(int i = 1;i<N+1;i++){
        calc(i);
    }
    int minnum = 0;
    for(int i = 1;i<100001;i++){
        if(dp[i]>=C){
            cout << i;
            break;
        }
    } 
}   
/*
중복 가능함.
20*100 =2000? 노노 
최대 경우를 생각해보자.
1000 1 천명의 고객을 채워야하고
100 1 1명의 고객을 얻는 데 100의 돈이 들 수 있다.
이때 최대값은 1000*100 = 100000<<최대값
그러므로 배열의 최대 dp[100001]로 잡자.

   돈
도
시   최대 고객의 수
의
번
호
*/