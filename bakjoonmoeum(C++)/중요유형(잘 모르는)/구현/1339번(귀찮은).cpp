#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll, ll> pll;  typedef tuple<int,int,int> t3;
typedef unsigned long long ull; typedef tuple<int,int,int,int> t4; typedef tuple<int,int,int,int,int> t5;
#define INF (1 << 30)
#define mod 1'000'000'009

int dx[] = {-1, 0, 1, 0}; int dy[] = {0, -1, 0 ,1};

int T, N, M, Q, P, L, K, inp;
ll ret = 0;
string str;
int num[26], score[26];

vector <string> st;
vector <pair<int, char>> vt;
map<char,int> m;

int main(){ cin.tie(0)->sync_with_stdio(0); cout.tie(0);
    cin >> N;
    for(int i = 1;i<N+1;i++){
        cin >> str;
        for(int j = 0;j < str.length();j++) {
            int val = 1;
            for(int k = 0;k < str.length() - j - 1;k++) val *= 10;
            num[str[j] - 65] += val;
        }
        st.push_back(str);
    }//우선순위를 정할 수 있게 미리 값을 저장한다.

    for(int i = 0;i<26;i++) vt.push_back({num[i], i + 65});
    
    sort(vt.rbegin(),vt.rend());
    //값 순서대로 정렬 및 알파벳에 수 부여
    int s = 9;
    for(int i = 0;i<vt.size() && vt[i].first;i++) m[vt[i].second] = s--;

    for(int i = 0;i<st.size();i++){//수를 계산
        int num = 0;
        for(int j = 0;j<st[i].length();j++){
            num *= 10; num += m[st[i][j]];
        }
        ret += num;
    }
    cout << ret;
}
/*
    


*/