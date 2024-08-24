#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    string str;
    vector <string> vt;
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> str;
        string tmp = str.substr(str.find('.')+1);//확장자만 받음
        vt.push_back(tmp);
    }
    sort(vt.begin(),vt.end());
    vt.push_back("1");//범위 초과 방지용
    int cnt = 1;
    for(int i = 0;i<vt.size()-1;i++){
        if(vt[i] == vt[i+1]){//같으면 개수++
            cnt++;
        }else{//다르면 출력 및 개수 초기화
            cout << vt[i] << ' ' << cnt << '\n';
            cnt = 1;
        }
    }
}
/*
첫 코드는 시간초과
이유?
우선 입력이 들어올 때마다 vt를 확인하는 즉 이중 포문을 썼는데 결국 시간초과가 났다.

두 번째 코드
이중 포문을 지우고, 입력을 모두 받은 후에 알파벳순으로 소트시켰다.
그렇게 하면 같은 스트링에 대해 개수를 셀 수 있으므로 
같은 스트링일 동안은 개수를 세고 다른 스트링이 나올 시 스트링 및 개수를 출력했다.

중요한 점! 정렬 후 마지막에 하나를 더 넣었는데, 이건 인덱스가 범위를 넘어가는 걸
막기 위한 것이다. 즉 아무거나 넣어도 상관없다는 뜻
*/