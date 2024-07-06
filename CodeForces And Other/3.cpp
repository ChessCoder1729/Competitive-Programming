#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);

bool check(vector <int>&a, vector <int>&h){
   int n = a.size();
   int start = 0;
   int end = n-1;
   bool ans = true;
   for(int i = 0;i<n-1;i++){
      if(a[start]>a[end]){
         start++;
         if(a[start]!=h[i]){
            ans = false;
            break;
         }
      }
      else{
         end--;
         if(a[end]!=h[i]){
            ans = false;
            break;
         }
      }
   }
   return ans;
}

int main(){
   fastio;
    int t;
   cin >> t;
   while(t--){
      long int n;
      cin >> n;
      vector <int> h(n-1);
      set <int> s;
      int cnt = 0;
      vector <int>a(n);
      bool vis[n+1];
      for(int i = 1;i<=n;i++) vis[i] = false;
      for(int i = 0;i<n-1;i++){
         cin >> h[i];
         if(vis[h[i]]==false){
            vis[h[i]] = true;
            cnt++;
         }
      }
      int start,end;
      if(cnt<n-2) cout << -1 ;
      else if(cnt==n-2){
         for(int i = 1;i<=n;i++){
            if(cnt==n) break;
            if(vis[i]) continue;
            else{
               if(cnt==n-2){
                  a[0] = i;
                  cnt++;
               }
               else if(cnt==n-1){
                  a[n-1] = i;
                  cnt++;
               }
            }
         }
         start = 0;
         end = n-1;
         for(int i = 0;i<n-1;i++){
            if(a[start]<a[end]){
               end--;
               a[end] = h[i];
            }
            else{
               start++;
               a[start] = h[i];
            }
         }
         if(check(a,h)){
            for(int i = 0;i<n-1;i++) cout << a[i] << ' ';
            cout << a[n-1];
         }
         else cout << -1 ;
      }
      else if(cnt==n-1){
         a[0] = 1;
         for(int i = 1;i<n-1;i++){
            a[i] = h[n - i - 2];
         }
         for(int i = 1;i<=n;i++){
            if(vis[i]==false){
               a[n-1] = i;
               break;
            }
         }
         if(check(a,h)){
            for(int i = 0;i<n-1;i++) cout << a[i] << ' ';
            cout << a[n-1];
         }
         else cout << -1 ;
      }
      if(t>=1)cout << endl;
   }
}
