#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n,k,input;
    vector <int> vt;
    cin >> n >> k;
    priority_queue<int, vector<int>, greater<int>>pq;
    for(int i = 0;i<n;i++){
        cin >> input;
        pq.push(input);
    }
    
    for(int i = 1;i<n+1;i++){
        while(pq.top() < i){
            int val = pq.top() + k;
            pq.pop();
            pq.push(val);
        }
        if(pq.top() == i){
            pq.pop();
        }
        else{
            cout << 0; 
            return 0;
        }
    }
    cout << 1;
}
/*

*/