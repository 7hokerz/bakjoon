#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll; typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4;
#define INF 1e9+1
 
int N, K, bcnt = 0;
vector <char> res;

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> N >> K;
    for(int i = 0;i<N-1;i++) res.push_back('B');

    for(int j = 0;j<N;j++){
        res.push_back('A');

        for(int i = res.size() - 1;i>0;i--){ //for(char val: res) cout << val; cout << ' ' << bcnt << '\n';
            if(bcnt == K) {
                for(char val: res) cout << val; //cout << bcnt;
                return 0;
            }
            if(res[i-1] == 'A') break;

            swap(res[i], res[i-1]); bcnt++;
        } //for(char val: res) cout << val; cout << ' ' << bcnt << '\n';
        
        if(bcnt == K) {
            for(char val: res) cout << val; //cout << bcnt;
            return 0;
        }

        res.pop_back(); bcnt -= j+1;
    }
    cout << -1;
}
/*
(풀이법 봄)
처음엔 dfs로 해도 되겠네? 하고 했다고 무지성 시간초과...

결국 답지를 봄. 발상이 이걸 어떻게 떠올리냐...

처음에 B를 모두 채운다(뒤에 한 자리 빼고). bcnt = 0;
그리고 A를 넣는다. 그 후 한 자리씩 A를 전진시키면서 bcnt++한다. 
A를 만나거나 끝에 도달할 때까지 반복.

K에 도달하지 못했으면 다시 B를 하나 빼고 A 추가 및 과정 반복...
이 때 중요한 건 bcnt를 빼줘야 하는데, bcnt--가 아닌 A가 몇 개 존재하느냐에 따라
다르게 빼줘야 한다는 것이다.

이런 발상은 어케하누? 해 구성하기에 그리디 수학 애드혹 붙어있는 경우가 많으니 더욱 쉽지 않네...
*/