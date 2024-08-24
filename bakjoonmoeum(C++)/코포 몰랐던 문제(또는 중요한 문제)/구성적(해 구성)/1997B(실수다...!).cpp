#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll;  typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
#define INF 1e9

int T, N;
string str;

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> T;
    for(int i = 0;i<T;i++){
        cin >> N;
        int sum = 0;
        char arr[3][200005];

        for(int j = 1;j<3;j++) { cin >> str;
            for(int k = 1;k<N+1;k++){
                arr[j][k] = str[k-1];
            }
        }

        for(int j = 1;j<3;j++){
            for(int k = 2;k<N;k++){
                if(j == 1){
                    if(arr[1][k] == '.' && arr[2][k] == '.'  && arr[2][k-1] == 'x' && arr[2][k+1] == 'x' && arr[1][k-1] == '.' && arr[1][k+1] == '.') sum++;
                }
                else{
                    if(arr[2][k] == '.' && arr[1][k] == '.' && arr[1][k-1] == 'x' && arr[1][k+1] == 'x' && arr[2][k-1] == '.' && arr[2][k+1] == '.') sum++;
                }
            }
        }
        cout << sum << '\n';
    }
}
/*
... x.x
x.x ...

x와 y는 변을 공유한다. 

답: 조건을 충족하는 모든 셀의 개수를 출력하는 것이다.

셀은 한 번에 한 개만 막을 수 있다는 것

어떤 위치 .에서 i = 0일 때 arr[i-1][j-1]과 arr[i-1][j+1]이 막혀있고, 
arr[i][j-1]과 arr[i][j+1]이 막혀있지 않은 경우 가능하다는 것이다.
*/