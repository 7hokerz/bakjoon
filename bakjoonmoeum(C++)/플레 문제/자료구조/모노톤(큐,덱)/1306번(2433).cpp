#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N, M, input;
    deque <int> dq;
    vector <int> vt, max;
    cin >> N >> M;
    for(int i = 0;i<N;i++){
        cin >> input;
        vt.push_back(input);
    }
    for(int i = 0;i<vt.size();i++){
        while(!dq.empty() && vt[dq.back()] <= vt[i]){
            dq.pop_back();
        }

        dq.push_back(i);

        if(dq.front() == i-(2*M-1)){
            dq.pop_front();
        }

        if(i >= 2*M-2){
            max.push_back(dq.front());
        }
    }
    for(int i = 0;i<max.size();i++){
        cout << vt[max[i]] << ' ';
    }
}
/*



*/