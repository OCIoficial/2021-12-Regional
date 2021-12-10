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
  int n; cin >> n;
  vector <int> b(n);
  for(int i=0; i<n; i++){
    int c, p, k, v; cin >> c >> p >> k >> v;
    b[i] = k*v-c*p;
  }
  int ans = 0;
  pair <int, int> ans_idx = {0, 0};
  int cur_pre = 0, min_pre = 0, min_pre_idx = 0;
  for(int i=0; i<n; i++){
    cur_pre += b[i];
    if(cur_pre-min_pre > ans || (cur_pre-min_pre == ans && i-min_pre_idx > ans_idx.second-ans_idx.first)){
      ans = cur_pre-min_pre;
      ans_idx = {min_pre_idx+1, i+1};
    }
    if(cur_pre < min_pre){
      min_pre = cur_pre;
      min_pre_idx = i+1;
    }
  }
  dbg(b);
  if(ans > 0)
    cout << ans_idx.first << ' ' << ans_idx.second << ' ' << ans << '\n';
  else
    cout << "IMPOSIBLE\n";
  return 0;
}
