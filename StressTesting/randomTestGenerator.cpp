#include<bits/stdc++.h>
using namespace std;


int rand(int a, int b){  // Both inclusive
    if(a>b) swap(a,b);
    return a + rand()%(b - a + 1);
}


int main(int argc, char* argv[]){
    srand(atoi(argv[1]));
    int n = rand(1,100);
    cout<<n<<endl;
}