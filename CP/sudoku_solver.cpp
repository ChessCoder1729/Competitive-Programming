#include <bits/stdc++.h>
using namespace std;

struct point{
     int x,y,v;
};
int bx(int x, int y){
     return x/3 + 3*(y/3);
}

int sudoko[9][9]; 
vector<int> values[9][9]; // The values the box (i,j) can take
vector<int> row[9][9]; // The boxes the the value j can take in i^th row
vector<int> col[9][9];
vector<int> box[9][9];

queue<point>q;

void build(){
     vector<int>tmp = {0,1,2,3,4,5,6,7,8};
     for(int i = 0;i<9;i++){
          for(int j = 0;j<9;j++){
               sudoko[i][j] = -1;
               values[i][j] = tmp;
               row[i][j] = tmp;
               col[i][j] = tmp;
               box[i][j] = tmp;
          }
     }
}

void set(point p){
     sudoko[p.x][p.y] = p.v;
     update(p);
}
void remove(vector<int>&v, int val){
     auto it = lower_bound(v.begin(),v.end(),val);
     if(it!=v.end() and *it==val){
          v.erase(it);
     }
}

void update(point p){
     for(int i = 0;i<9;i++){
          remove(values[p.x][i],p.v);
          remove(values[i][p.y],p.v);
          
          remove(row[i][p.v],p.y);
          remove(col[i][p.v],p.x);
     }
     row[p.x][p.v] = {p.y};
     col[p.y][p.v] = {p.x};
     for(int i = 0;i<9;i++){
          for(int j = 0;j<9;j++){
               if(bx(i,j)==bx(p.x,p.y)){
                    remove(values[i][j],p.v);
                    
               }
          }
     }
     values[p.x][p.y] = {p.v};

}

int main(){
     for(int i = 0;i<9;i++){
          for(int j = 0;j<9;j++){
               char c; cin >> c;
               if(c!='?'){
                    point p; p.x = i, p.y = j, p.v = (c-'1');
                    q.push(p);
               }
          }
     }


}