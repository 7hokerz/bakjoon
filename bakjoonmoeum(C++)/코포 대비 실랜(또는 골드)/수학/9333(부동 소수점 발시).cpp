#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll;  typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
#define INF 0x7F7F7F7F7F

int T;
double R, B, M;

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> T;
    while(T--){
        cin >> R >> B >> M;
        int cnt = 0; ll iR = (R + 1e-8) * 100, iB = (B + 1e-8) * 100, iM = (M + 1e-8) * 100, preiB = iB;//이 새끼 맞어?!
        
        while(cnt < 1201){
            ll i;
            if((iB * iR) % 10000 >= 5000)  i = (iB * iR) / 10000 + 1;
            else i = (iB * iR) / 10000;

            iB += i - iM; cnt++;
            if(iB <= 0) break;
            if(preiB < iB){cnt = 1201; break;}
            preiB = iB;
        }
        
        if(cnt == 1201) cout << "impossible" << '\n';
        else cout << cnt << '\n';
    }
}
/*
앞으로는 단순 변환에서도 오차가 발생할 수 있다는 걸 잊지 말자...뭐 이런 어이없는 경우가
*/