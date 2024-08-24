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

int N;
vector <int> vt;//순열을 담을 배열
int arr[101];//1~N까지의 수를 담을 배열
bool visited[101];//방문 표시

void print(){
    for(int i = 0;i<vt.size();i++){
        cout << vt[i] << ' ';
    }
    cout << '\n';
}

void dfs(int idx, int sum){
    if(sum == N){
        print();
        return;
    }
    for(int i = idx;i<N+1;i++){
        if(sum + arr[i] <= N){
            if(visited[i]) continue;
            visited[i] = !visited[i];
            vt.push_back(arr[i]);
            
            dfs(1 ,sum + arr[i]);

            visited[i] = !visited[i];
            vt.pop_back();
        }  
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    for(int i = 1;i<N+1;i++) arr[i] = i;
    dfs(1,0);
}
/*
순열. 
N을 입력받아 1~N까지의 수 중 적당히 선택하여 합이 N을 만족하는 경우를 구한다.
*/