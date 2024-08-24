#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef unsigned long long ull; typedef pair<ll, ll> pll;
typedef tuple<int,int,int> t3; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
typedef tuple<int,int,int,int,int,int> t6;

int dx[] = {0, 1, 0, -1}; int dy[] = {-1, 0, 1, 0};

int M, N, L, X, res = 0;

vector <int> locc;

void bisearch(int X){
    int left = 0, right = L;
    while(left <= right){
        int cnt = X;
        int mid = (left + right) / 2;//자르는 최소 길이 기준
        int prev = 0;//이전 자른 지점

        for(int i = 0;i<locc.size();i++){
            if(locc[i] - prev >= mid){//잘라야 하는 길이인 경우
                cnt--;
                prev = locc[i];
            }
        }

        if(cnt < 0){//정해진 횟수보다 많이 자른 경우(더 크게 자를 수 있다는 뜻)
            left = mid + 1;
            res = max(res, mid);
        }
        else{//정해진 횟수보다 적게 자른 경우(더 작게 잘라야 한다는 뜻)
            right = mid - 1; 
        }
    }
}

int main(){cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> N >> M >> L;
    locc.push_back(0);
    for(int i = 1;i<M+1;i++){
        cin >> X;
        locc.push_back(X);
    } 
    locc.push_back(L);

    for(int i = 1;i<N+1;i++){
        cin >> X;
        bisearch(X);
        cout << res << '\n';
        res = 0;
    }
}
/*




*/