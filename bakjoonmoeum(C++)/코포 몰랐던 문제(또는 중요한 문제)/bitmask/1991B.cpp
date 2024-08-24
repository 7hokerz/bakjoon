#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll;  typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
#define INF 1e9

int T, N;

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> T;
    for(int i = 0;i<T;i++){
        cin >> N;

        int a[200001], b[200001];

        b[0] = b[N] = 0;

        for(int j = 1;j<N;j++) cin >> b[j];

        vector <int> ret;

        for(int j = 1;j<N+1;j++) a[j] = b[j] | b[j-1];
        
        bool chk = true;
        for(int j = 1;j<N;j++){
            if((a[j] & a[j + 1]) != b[j]) {
                chk = false; break;
            }
        }

        if(chk){
            for(int j = 1;j<N+1;j++) cout << a[j] << ' ';
            cout << '\n';
        }
        else cout << -1 << '\n';
    }
}
/*
전제 조건: b0 = bn = 0;(or 연산에서 0은 연산에 영향을 끼치지 않기 때문에?)
bi = ai & ai+1; bi+1 = ai+1 & ai+2;

ai = bi-1 | bi ?
위 공식이 성립 가능한 이유?

bi = ai & ai+1, bi+1 = ai+1 & ai+2를 보면 하나의 a는 2개의 b에 영향을 끼친다.

즉 쉽게 말하면 
bi의 비트와 bi+1의 비트가 ai+1의 모든 비트를 포함해야 한다는 것이다.
그렇지 않으면 올바르지 않은 것이고.

그러므로 ai에다가 = bi-1 | bi를 먼저 삽입해두고, 
나중에 ai & ai+1 == bi인지 확인하여 같지 않은 경우 식을 만들 수 없다고 보면 된다는 것이다.

이해는 겨우 했는데 이걸 어떻게 생각해내??? 허허...
*/