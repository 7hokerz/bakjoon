#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    stack <pair<long long,pair<long long,int>>> st;//합,(값,인덱스)
    int n;
    long long input = 0LL, res = 0LL;
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> input;
        if(!st.empty()){
            if(st.top().second.first < input){
                st.push({input,{input,i}});
            }else{
                int idx;//탑의 인덱스값
                while(!st.empty() && st.top().second.first > input){//이 부분이 중요하다.
                    st.top().first = (i-st.top().second.second)*st.top().second.first;//탑의 넓이를 갱신시켜준다.
                    //너비 값은 i-1부터 st.top().second.second까지이므로 사실상 아래 공식을 적용한 결과가 저거다.
                    res = (st.top().first>res)?st.top().first:res;
                    idx = st.top().second.second;//탑의 인덱스 값을 저장하여 나중에 탑이 더 작은 경우를 찾았을 때 넓이를 구하는 데 쓰인다.
                    st.pop();
                }
                if(!st.empty()){
                    if(st.top().second.first == input){
                        st.top().first = (i-st.top().second.second+1)*input;
                    }else{
                        st.push({input*(i-idx+1),{input,idx}});//1을 더한 이유는 idx가 예전 탑 인덱스이기 때문. 
                    }
                }else{
                    st.push({input,{input,0}});
                    //i를 넣나 0을 넣나 뭔 차이인지...
                    // 0을 넣는게 맞을 듯? 왜냐면 0을 넣어야 해당 높이의 넓이를 제대로 구할 수 있음.
                }
            }
        }else{
            st.push({input,{input,i}});
        }
    }
    while(!st.empty()){
        st.top().first = (n-st.top().second.second)*st.top().second.first;
        res = (st.top().first>res)?st.top().first:res;
        st.pop();
    }
    cout << res;
}   
/*
풀다가 사실 기억 잘 안나서 히스토그램 풀이 참고하면서 풀었다.
top값보다 더 큰 값이 들어오면 단순 삽입
top값보다 더 작은 값이 들어오면 작은 값을 찾을때까지 제거
*/