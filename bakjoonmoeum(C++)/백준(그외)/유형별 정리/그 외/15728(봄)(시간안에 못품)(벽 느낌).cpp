#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(int a, int b){
    return a < b;
}

int N, K, input;
vector <int> sh;
vector <int> team, rem;
vector <pair<int,int>> arr;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;
    for(int i = 1;i<N+1;i++){
        cin >> input;
        sh.push_back(input);
    }
    sort(sh.begin(),sh.end());
    for(int i = 1;i<N+1;i++){
        cin >> input;
        team.push_back(input);
    }
    sort(team.begin(),team.end());

    for(int i = 0;i<team.size();i++){
        for(int j = 0;j<N;j++){
            arr.push_back({team[i]*sh[j],team[i]});//값, 카드
        }
    }
    sort(arr.begin(),arr.end());
    long int maxn = -100000000;
    for(int k = 0;k<K+1;k++){
        maxn= -100000000;
        int idx = 0;
        for(int i = 0;i<sh.size();i++){
            for(int j = 0;j<team.size();j++){
                if(maxn < team[j]*sh[i]){
                    maxn = team[j]*sh[i];
                    idx = j;
                }
            }
        }
        if(k<K) team.erase(team.begin()+idx);
    }
    
    cout << maxn;

    
}   
/*
최선의 방법? 
*/