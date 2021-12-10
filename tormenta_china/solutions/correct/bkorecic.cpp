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
  set <int> s;
  for(int i=0; i<n; i++){
    int x; cin >> x;
    s.insert(x);
  }
  cout << *next(s.begin()) << '\n';
  return 0;
}
