#include <iostream>
#include <vector>
using namespace std;
int n, c, intm, intp; double m, p;

int dp[10001];// 가지고 있는 최대 돈의 양, 값: 최대 칼로리
vector <pair<int,int>> vt;//사탕의 칼로리, 사탕의 가격

void calc(int pos){
    for(int i = vt[pos-1].second;i<intm+1;i++){//사탕의 가격부터 가지고 있는 돈의 양 만큼 순회
        //dp[i - vt[pos].second]: 현재 사탕의 비용을 빼고 남은 돈으로 얻을 수 있는 칼로리값
        dp[i] = max(dp[i], dp[i - vt[pos-1].second] + vt[pos-1].first);//이런 식을 어떻게 생각해내는건지...(1)
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while(1){
        cin >> n >> m;
        if(n == 0 && m == 0.00) break;
        intm = (int)(m*100.0 + 0.5);

        for(int i = 0;i<n;i++){
            cin >> c >> p; intp = (int)(p*100.0 + 0.5);
            vt.push_back({c,intp});//칼로리, 가격
        }

        for(int i = 1;i<n+1;i++){//모든 사탕에 대해 순회한다.
            calc(i);
        }

        cout << dp[intm] << '\n';
        
        fill(dp, dp+10001, 0);
        vt.clear();
    }
}  
/*
++ 0.5를 더하는 이유? 실수 연산은 오차 가능성이 무조건 존재하므로 적당한 작은 수를 더해 오차를 없앤다고 보면 된다.

1의 식으로 가능한 이유?
사실 원래 가능한 게 맞다. 평범한 배낭 문제는 조건이 있었기에 뒤부터 순환하면서 풀면 그것도 가능하다.
지금 처럼 물건을 중복해서 쓸 수 있다면 앞에서부터 순회하는 방법도 문제 없다.

그리고 하나 더 중요한 점은 돈을 쓸 수 있는 즉 사탕이 쓰이는 지점부터 순회하는 점이다.
쓸데없는 계산을 줄여 시간을 줄이는 데 도움이 되지 않을까...
*/