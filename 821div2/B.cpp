#include<bits/stdc++.h>
//#include "headerlist.cpp"

using namespace std;
void solve(){

  int n, x, y;
  cin >> n >> x >> y;
  if(x>y){
    swap(x,y);
  }
  if(x!=0){
    cout<<-1<<endl;
    return;
  }
  if(y==0 || (n-1)%y!=0){
    cout<<-1<<endl;
    return;
  }
  for(int i =0;i<n-1;i++){
    cout<<i-i%y+2<<" \n"[i==n-2];
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t--){
    solve();
  }

  return 0;
}
