#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int m, n, a, b, c, d;//만두의 종류, 현재 밀가루
vector <pair<pair<int,int>,pair<int,int>>> vt;
//남은 만두 속, 만두 하나를 만들기 위해 필요한 만두 속, 만두피를 만드는 데 필요한 밀가루 양, 판매 금액
int dp[101][1001];//만두 속 양, 밀가루 양, 값: 판매 금액의 최대 합

void calc(int pos){
    for(int i = vt[pos].first.second;i<=12;i++){
        if(i>vt[pos].first.first){
            for(int j = vt[pos].second.first;j<n+1;j++){
                dp[i][j] = dp[i-1][j];
            }
        }else{
            for(int j = vt[pos].second.first;j<n+1;j++){
                dp[i][j] = max(dp[i][j], vt[pos].second.second + dp[i-vt[pos].first.second][j-vt[pos].second.first]);
            }
        } 
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> c >> d;//c0, d0(만두 피만 가지고 만들어)
    vt.push_back({{100,0},{c,d}});//스페셜 만두
    for(int i = 1;i<m+1;i++){
        cin >> a >> b >> c >> d;
        vt.push_back({{a,b},{c,d}});
    }
    //sort(vt.begin(),vt.end());
    for(int i = 0;i<m+1;i++){
        calc(i);
    }
    for(int i = 0;i<13;i++){
        for(int j = 1;j<n+1;j++){
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
    
}   
/*
만두를 중복 가능
10 2 2 1
7 3 2 100
12 3 1 10
    쓴 밀가루 양
쓴
만두
피
    1 2 3 4 5 6 7 8 9 10 
0   0 1 1 2 2 3 3 4 4 5
1   0 1 1 2 2 3 3 4 4 5
2   0 1 1 2 2 3 3 4 4 5
3   10 10 11 11 12 12 13 13 14 14
4   10 10 11 11 12 12 13 13 14 14
5   10 10 11 11 12 12 13 13 14 14
6   20 20 21 21 22 22 23 23 24 24
7   20 20 21 21 22 22 23 23 24 24
8   20 20 21 21 22 22 23 23 24 24
9   30 30 30 30 30 30 30 30 30 30
10  30 30 30 30 30 30 30 30 30 30
11  30 30 30 30 30 30 30 30 30 30
12  40 40 40 40 40 40 40 40 40 40


*/