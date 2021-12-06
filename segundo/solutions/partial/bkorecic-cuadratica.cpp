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
  vector <int> a(n);
  for(int i=0; i<n; i++) cin >> a[i];
  // solución cuadrática: para cada uno, contamos cuantos valores distintos mayores a él hay
  // xd
  for(int i=0; i<n; i++){
    set <int> bigger;
    for(int j=0; j<n; j++){
      if(a[j] > a[i]) bigger.insert(a[j]);
    }
    if(bigger.size() == 1){ // encontramos el segundo!!1111
      cout << a[i] << '\n';
      exit(0);
    }
  }
  return 0;
}
