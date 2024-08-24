#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, input, start, end, prefixsum = 0;
    cin >> N >> M;
    int nums[N];
    for(int i = 0;i<N;i++){
        cin >> input;
        prefixsum += input;
        nums[i] = prefixsum;
    }
    for(int i = 0;i<M;i++){
        cin >> start >> end;
        cout << nums[end-1] - nums[start-2] << '\n';
    }
}
/*
단순 구간의 합을 누적해서 더하는 방식으로는 시간초과가 뜬다.
대신 배열에 수를 넣는 과정에서 수를 그대로 넣는 게 아닌
누적된 합을 배열에 넣어주면 쉽게 풀린다.
즉 구간 합을 구하려면
nums[end-1] - num[start-2]
합이 미리 계산되어 있으므로 저 식만 넣어주면 합이 나온다.
*/