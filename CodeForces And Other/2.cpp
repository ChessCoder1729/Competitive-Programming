#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);

int main(){
    fastio;
    int n,p;
    cin >> n >> p;
    int curr,ans;
    int vertex[p][2];
    for(int i = 0;i<p;i++) cin >> vertex[i][0] >> vertex[i][1];
    int x1, y1, x2, y2;
    int peri[p];
    peri[0] = abs(vertex[0][0] - vertex[1][0] + vertex[0][1] - vertex[1][1]);
    for(int i = 1;i<p-1;i++){
        peri[i] = peri[i-1] + abs(vertex[i+1][0] - vertex[i][0] + vertex[i+1][1] - vertex[i][1]);
    }
    peri[p-1] = peri[p-2] +  abs(vertex[0][0] - vertex[p-1][0] + vertex[0][1] - vertex[p-1][1]);
    while(n--){
        cin >> x1 >> y1 >> x2 >> y2;
        int side1 = -1;
        int side2 = -1;
        for(int i = 0;i<p-1;i++){
            if(side1==-1){
                if(min(vertex[i][0],vertex[i+1][0])<=x1 and x1<=max(vertex[i][0],vertex[i+1][0])){
                    if(min(vertex[i][1],vertex[i+1][1])<=y1 and y1<=max(vertex[i][1],vertex[i+1][1])){
                        side1 = i;
                    }
                }
            }
            if(side2==-1){
                if(min(vertex[i][0],vertex[i+1][0])<=x2 and x2<=max(vertex[i][0],vertex[i+1][0])){
                    if(min(vertex[i][1],vertex[i+1][1])<=y2 and y2<=max(vertex[i][1],vertex[i+1][1])){
                        side2 = i;
                    }
                }
            }
            else if(side1!=-1 and side2!=-1) break;
        }
        if(side1==-1) side1 = p-1;
        if(side2==-1) side2 = p-1;
        if(side1<=side2){
            ans = abs(peri[(side2+p-1)%p] - peri[side1]) + abs(vertex[(side1+1)%p][0]-x1 + vertex[(side1+1)%p][1]-y1);
            ans += abs(vertex[side2][0] - x2 + vertex[side2][1] - y2);
        }
        else{
            ans = abs(peri[(side1+p-1)%p]-peri[side2] + abs(vertex[(side2+1)%p][0]-x2 + vertex[(side2+1)%p][1]- y2));
            ans += abs(vertex[side1][0] - x1 + vertex[side1][1] - y1);
        }
        cout << min(ans,peri[p-1]-ans) << endl;
    }
}
