#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <stdlib.h>
using namespace std;

int N, M, T, input;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);
    cin >> T;
    for(int j = 0;j<T;j++){
        cin >> N >> M;
        vector <int> A, B;
        for(int i = 0;i<N;i++){//A
            cin >> input; A.push_back(input);
        }
        for(int i = 0;i<M;i++){//B
            cin >> input; B.push_back(input);
        }
        sort(B.begin(), B.end());
        int sum = 0;
        for(int i = 0;i<N;i++){
            //cout << lower_bound(B.begin(), B.end(), A[i]) - B.begin() << ' ';
            sum += lower_bound(B.begin(), B.end(), A[i]) - B.begin();
        }
        cout << sum << '\n';
    }
}
/*
lower_bound를 사용하여 A의 값이 같거나 큰 인덱스 지점을 찾는다.
*/