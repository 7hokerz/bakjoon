#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
#define mod 1'000'000'007;

int N, Q, one, two;
string map[1001];
vector <int> gr[1001];
bool visited[1001];
vector <string> res;
string result = "";

void dfs(int x){
    res.push_back(map[x]);
    visited[x] = true;
    if(x == two){
        for(int i = 0;i<res.size();i++) result += res[i];
        //최종 노드에 도착하면 res에 저장된 문자열들을 result에 담는다.
    }
    
    for(int i = 0;i<gr[x].size();i++){
        if(!visited[gr[x][i]]) dfs(gr[x][i]);
    }
    visited[x] = false;
    res.pop_back();
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> Q;
    for(int i = 1;i<N+1;i++){//집에 쓰여있는 번호
        string tmp; cin >> tmp;
        map[i] = tmp;
    }
    for(int i = 3;i<=N+1;i++){//도로의 정보(간선)
        cin >> one >> two;
        gr[one].push_back(two);
        gr[two].push_back(one);
    }
    for(int i = N+2;i<=N+Q+1;i++){//놀이에 대한 정보(문자열을 붙이는 순서)
        cin >> one >> two;//순서 하나하나마다 dfs를 호출
        dfs(one);

        long long ret = 0LL;//**중요! 긴 문자열의 모듈러 연산
        for(int j = 0;j<result.length();j++){
            //ret = 수를 저장할 변수, 결국은 문자열을 한 개씩 정수로 변환하여 
            //ret의 마지막 자리에 추가하고 모듈러 연산을 수행한다.
            ret = (ret * 10 + (int)result[j] - '0') % mod;
        }
        //cout << result << '\n';
        cout << ret << '\n';
        result = "";
    }
}
/*
모듈러 연산을 처음으로 배움. 나머지 구현은 어렵지 않았음.

과정:
처음에는 one 노드에서 시작하여, dfs로 탐색하면서 노드의 문자열을 res벡터에 저장하고,
마지막에 two를 만나면 문자열 변수에 모든 문자열을 붙여준다.

그 후 문자열에 대한 변환 및 모듈러 연산을 실시하여 값을 구한다.
*/