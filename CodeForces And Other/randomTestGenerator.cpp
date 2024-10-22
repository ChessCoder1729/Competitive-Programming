#include<bits/stdc++.h>
using namespace std;

void shuffle(int arr[], int n) {
    for (int i = n - 1; i >= 1; i--) {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

vector<int>permutation(int n){
    int arr[n];
    for(int i = 0;i<n;i++){
        arr[i] = i+1;
    }
    shuffle(arr,n);
    vector<int>v;
    for(auto x : arr){
        v.push_back(x);
    }
    return v;
}

int rand(int a, int b){  // Both inclusive
    if(a>b) swap(a,b);
    return a + rand()%(b - a + 1);
}


int main(int argc, char* argv[]){
   srand(atoi(argv[1]));
   srand(time(NULL));
   cout << 1 << endl;
   int n = rand(1,10);
    for(int i = 0;i<n;i++){
        cout << rand(0,1) << ' ';
    }
}
 
