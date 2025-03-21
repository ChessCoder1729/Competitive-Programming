#include<bits/stdc++.h>
using namespace std;


int rand(int a, int b){  // Both inclusive
    if(a>b) swap(a,b);
    return a + rand()%(b - a + 1);
}

void generateRandomTree(int n) {
    if (n <= 1) {
        std::cout << "Tree must have at least 2 nodes." << endl;
        return;
    }

    vector<bool> visited(n, false); 
    vector<pair<int, int>> edges; 

    srand(time(0));

    for (int i = 1; i < n; ++i) {
        int u = rand() % i;
        edges.push_back({u, i});
    }

    for (auto& edge : edges) {
        std::cout << edge.first << ' ' << edge.second << endl;
    }
}


int main(int argc, char* argv[]){
   srand(atoi(argv[1]));
   srand(time(NULL));
   int n = rand(2,10);
   generateRandomTree(n);
   for(int i = 0;i<n;i++){
      cout << rand(1,10) << ' ';
   }
}
 
