#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "dbg.h"
#else
#define dbg(...) 1313
#endif

typedef long long ll;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m; cin >> n >> m;
  vector <vector <int>> grilla(n, vector <int>(m));
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cin >> grilla[i][j];
    }
  }
  vector <vector <int>> min_SE(n, vector <int>(m));
  int ans = -1;
  for(int i=n-1; i>=0; i--){
    for(int j=m-1; j>=0; j--){
      int mn = 1e9;
      if(i<n-1) mn = min(mn, min_SE[i+1][j]);
      if(j<m-1) mn = min(mn, min_SE[i][j+1]);
      if(mn < grilla[i][j])
        ans = max(ans, grilla[i][j]-mn);
      min_SE[i][j] = min(mn, grilla[i][j]);
    }
  }
  cout << ans << '\n';
  return 0;
}
