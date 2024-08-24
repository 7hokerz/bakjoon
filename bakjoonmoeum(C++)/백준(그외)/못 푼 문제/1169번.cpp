#include <iostream>
#include <stack>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    stack <pair<pair<int,long double>,pair<int,bool>>> st;//pair<높이, 좌표> pair<인덱스, avail>
    stack <pair<int, long double>> tmp;
    int n;
    int input;
    cin >> n;
    for(int i = 1;i<n+1;i++){
        cin >> input;//높이
        if(st.empty()) st.push({{input,input*0.708},{i,true}});
        else{
            long double loc = (st.top().first.first>input)?input:st.top().first.first;
            loc = loc*1.416 + st.top().first.second;//input의 좌표
            long double val = st.top().first.second - st.top().first.first*0.708;
            long double val2 = st.top().first.second + st.top().first.first*0.708;
            if (val<0 && val>-1) val = 0.0; if (val2<0 && val2>-1) val2 = 0.0;

            if(st.top().first.first >= input*3) st.push({{input + 0.0,loc},{i,false}});
            else if(st.top().first.first*3 <= input){
                st.top().second.second = false;
                st.push({{input + 0.0 ,loc},{i,true}});
            }
            else if(st.top().first.first > input 
            && (loc + input*0.708 <= val2)){//1.2
                st.push({{input + 0.0,loc},{i,false}});
                
            }
            else if(st.top().first.first <= input 
            && loc - input*0.708 <= val){//1.1
                st.top().second.second = false;
                st.push({{input + 0.0 ,loc},{i,true}});
                //cout << st.top().first.second << ' ';
            }
            else st.push({{input + 0.0 ,loc},{i,true}});
        }
    }

    vector <int> vt;
    while(!st.empty()){
        //cout << st.top().first.second << ' ';
        if(st.top().second.second){
            vt.push_back(st.top().second.first);
            tmp.push(st.top().first);
            long double val;
            long double val2;
            st.pop();
            if(!st.empty()){
                val = tmp.top().second - tmp.top().first*0.708;
                val2 = st.top().first.second - st.top().first.first*0.708;
                if(val<0&&val>-1) val = 0.0;
                if(val2<0&&val2>-1) val2 = 0.0;
            }
            while(!st.empty() 
            && (val <= val2)){
                //cout << val << ' ';
                //cout << val2 << ' ';
                st.pop();
                if(!st.empty()) val2 = st.top().first.second - st.top().first.first*0.708;
                if(val2<0&&val2>-1) val2 = 0.0;
            }
            tmp.pop();
        }else{
            st.pop();
        }
    }
    for(int i = vt.size()-1;i>=0;i--){
        cout << vt[i] << ' ';
    }
}
/*
루트 2 : 0.7로 정의

스택에 들어갈 요소 pair<높이, 좌표> pair<인덱스, avail>

정리:
1. 가려지는 요소로 확인되면 avail = false;로 정의
1.1 top보다 작으면서, ba + 0.7 >= bb + 0.7인 경우
1.2 top이 더 작으면서, ba - 0.7 <= bb - 0.7인 경우

좌표를 구하는 법?
(첫 요소는 제외) 더 작거나 같은 정사각형의 변 * 1.4 + b(top의 좌표)

중요한 것
좌표 b, 한변의길이를 a라하면 가리는 범위는 ba +- 0.7a 단 더 큰 정사각형에 해당
결국 중요한 건 어떤 작은 정사각형의 좌표를 bb라 하면,
ba - 0.7 < bb -0.7 || ba +0.7 > ba + 0.7인 경우에는 bb가 가려진다고 증명 가능하다?
2.
추가 조건으로 두 정사각형 중 더 작은 어떤 정사각형b과 큰 정사각형a의 좌표 비교를 통해도 가능하다.
만약 bb-ba == 1.4bb라면 
ba와 bb 사이에 있는 정사각형들은 모두 보이지 않는다

*/