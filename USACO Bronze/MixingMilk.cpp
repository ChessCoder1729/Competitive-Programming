#include <bits/stdc++.h>
using namespace std;


int main() {
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int c1, c2, c3, m1, m2, m3;
    cin >> c1 >> m1 >> c2 >> m2 >> c3 >> m3;
    for(int i = 0;i<100;i++){
        if(i%3==0){
            if((m1+m2)>c2){
                m1 = m1 + m2 - c2;
                m2 = c2;
            }
            else{
                m2 = m1 + m2;
                m1 = 0;
            }
        }
        else if(i%3==1){
            if((m2+m3)>c3){
                m2 = m2 + m3 - c3;
                m3= c3;
            }
            else{
                m3 += m2;
                m2 = 0;
            }
        }
        else{
            if((m3+m1)>c1){
                m3 = m3 + m1 - c1;
                m1 = c1;
            }
            else{
                m1 += m3;
                m3 = 0;
            }
        }
    }
    cout << m1 << endl << m2 << endl << m3;
}

