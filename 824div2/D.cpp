#include<bits/stdc++.h>

using namespace std;

using ll =long long;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,k;
  cin >> n >> k;
  map<vector<int>,ll> A;
  vector<vector<int>> S(n, vector<int>(k));
  for(int i =0;i<n;i++){
    for(int j=0;j<k;j++){
      cin >>S[i][j];
    }
  }
  sort(S.begin(), S.end());
  for(int a=0;a<n;a++){
    for(int b=a+1;b<n;b++){
      vector<int>MA(k);
      for(int j=0;j<k;j++){
        MA[j] =(6-S[a][j]-S[b][j])%3;
      }
      A[MA]++;
    }
  }
  ll ans=0;
  for(auto it: A){
    if(it.second >=2){
      if(binary_search(S.begin(),S.end(), it.first)){
        ans+= it.second*(it.second-1)/2;
      }
    }
  }
  cout<<ans<<endl;

  return 0;
}
