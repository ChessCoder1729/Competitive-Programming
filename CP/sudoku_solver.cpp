#include <bits/stdc++.h>
using namespace std;

struct cell{
     int row, col;
};
queue<cell>numbers;

int sudoku[9][9];
int box_val[9][9];
bool pushed[9][9];
set<int> possiblities[9][9];

void remove_val_from_set(set<int>&s, int val){
     if(s.size()==1){
          return;
     }
     if(s.count(val)){
          s.erase(s.find(val));
     }
}

pair<int,int> middle_val_of_box(int box){
     if(box==0) return {1,1};
     if(box==1) return {1,4};
     if(box==2) return {1,7};
     if(box==3) return {4,1};
     if(box==4) return {4,4};
     if(box==5) return {4,7};
     if(box==6) return {7,1};
     if(box==7) return {7,4};
     if(box==8) return {7,7};
}

vector<pair<int,int>>all_cells_in_row(int row){
     vector<pair<int,int>>vec;
     for(int i = 0;i<9;i++)vec.push_back({row,i});
     return vec;
}

vector<pair<int,int>>all_cells_in_col(int col){
     vector<pair<int,int>>vec;
     for(int i = 0;i<9;i++) vec.push_back({i,col});
     return vec;
}

vector<pair<int,int>>all_cells_in_box(int box){
     vector<pair<int,int>>vec;
     int x = middle_val_of_box(box).first, y = middle_val_of_box(box).second;
     for(int xi = x-1;xi<=x+1;xi++){
          for(int yi = y-1;yi<=y+1;yi++){
               vec.push_back({xi,yi});
          }
     }
     return vec;
}

void remove_from_vec(vector<pair<int,int>>vec, int val){
     for(auto [x,y]:vec){
          remove_val_from_set(possiblities[x][y],val);
     }
}

void remove_from_row(int row, int val){
     remove_from_vec(all_cells_in_row(row),val);
}

void remove_from_col(int col, int val){
     remove_from_vec(all_cells_in_col(col),val);
}

void remove_from_box(int box, int val){
     remove_from_vec(all_cells_in_box(box),val);
}

void update_vec(vector<pair<int,int>>vec){
     for(auto [x,y]:vec){
          if(pushed[x][y]){
               continue;
          }
          if(possiblities[x][y].size()==1){
               numbers.push({x,y});
               sudoku[x][y] = *possiblities[x][y].begin();
               pushed[x][y] = true;
          }
     }

     for(int val = 1;val<=9;val++){
          bool taken = false;
          for(auto [x,y]:vec){
               if(sudoku[x][y]==val){
                    taken = true; break;
               }
          }
          if(taken) continue;

          int cnt = 0;
          for(auto [x,y]:vec){
               cnt += possiblities[x][y].count(val);
          }
          if(cnt!=1){
               continue;
          }
          for(auto [x,y]:vec){
               if(possiblities[x][y].count(val)){
                    numbers.push({x,y});
                    sudoku[x][y] = val;
                    possiblities[x][y] = {val};
                    pushed[x][y] = true;
               }
          }
     }
}

void update_row(int row){
     update_vec(all_cells_in_row(row));
}
void update_col(int col){
     update_vec(all_cells_in_col(col));
}
void update_box(int box){
     update_vec(all_cells_in_box(box));
}

void push_cell(cell x){
     int box = box_val[x.row][x.col];
     remove_from_row(x.row,sudoku[x.row][x.col]);
     remove_from_col(x.col,sudoku[x.row][x.col]);
     remove_from_box(box,sudoku[x.row][x.col]);
     update_row(x.row);
     update_col(x.col);
     update_box(box);
}


void judge(){
    srand(time(NULL));
    #ifndef ONLINE_JUDGE
    freopen("1.txt","r",stdin);
    freopen("2.txt","w",stdout);
    #endif
}

void solver(){
     set<int>s;
     for(int i = 1;i<=9;i++) s.insert(i);
     for(int i = 0;i<9;i++){
          for(int j = 0;j<9;j++){
               possiblities[i][j] = s;
          }
     }

     for(int i = 0;i<9;i++){
          for(int j = 0;j<9;j++){
               pushed[i][j] = false;
               cin >> sudoku[i][j];
               if(sudoku[i][j]!=0){
                    numbers.push({i,j});
                    possiblities[i][j] = {sudoku[i][j]};
                    pushed[i][j] = true;
               }
          }
     }

     while(!numbers.empty()){
          push_cell(numbers.front());
          numbers.pop();
     }
     cout << "The Solution for this sudoku is" << endl;
     for(int i = 0;i<9;i++){
          for(int j = 0;j<9;j++){
               cout << sudoku[i][j] << ' ';
          }
          cout << endl;
     }
     cout << endl;
}


int main(){
     cout << "Hello there! Myself ludo" << endl;
     cout << "----------------------------" << endl;
     cout << "INPUT FORMAT : " << endl;
     cout << "For every blank cell put a 0 and every cell that has a number put the number" << endl;
     cout << "Put spaces between adjacent digits" << endl;
     cout << "-------------------------------" << endl;

     for(int v = 0;v<=8;v++){
          int x = middle_val_of_box(v).first, y = middle_val_of_box(v).second;
          for(int dx = x-1;dx<=x+1;dx++){
               for(int dy = y-1;dy<=y+1;dy++){
                    box_val[dx][dy] = v;
               }
          }
     }
     int choice = 1;
     do{
          cout << "Input : " << endl;
          solver();
          cout << "Press 1 to try another sudoku, and 0 to exit" << endl;
          cin >> choice;
          while(choice!=1 and choice!=0){
               cout << "Please input either 1 or 0" << endl;
               cin >> choice;
          }

     }while(choice==1);

     cout << "Thanks for Testing" << endl;
     cout << "Press any key to exit" << endl;
     system("pause>nul");
}
