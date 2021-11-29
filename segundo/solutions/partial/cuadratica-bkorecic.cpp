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
  // solución cuadrática: para cada uno, contamos cuantos mayores a él hay
  // xd
  for(int i=0; i<n; i++){
    int cnt=0;
    for(int j=0; j<n; j++){
      if(a[j] > a[i]) cnt++;
    }
    if(cnt == 1){ // encontramos el segundo!!1111
      cout << i << '\n';
      exit(0);
    }
  }
  return 0;
}
