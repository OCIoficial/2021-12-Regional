/*
 * Regional OCI 2021
 * Problema: Calendario
 * Autor solución: Blaz
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(int d, int x){
  vector <bool> vis(31, 0); // los dias ya visitados
  vector <int> dia(31, 0);
  dia[1] = d;
  for(int i=2; i<=30; i++){
    // forma fácil de ver el día actual:
    // precalcularlos y olvidarse del d
    dia[i] = (dia[i-1]+1)%7;
  }
  while(!vis[x]){
    vis[x] = 1;
    if(dia[x]==0){ // lunes
      int start=x;
      while(vis[x]){
        x++;
        if(x>30) x-=30;
        if(x == start) break;
      }
    }
    else if(dia[x]==1){ // martes
      x = 31-x;
    }
    else if(dia[x]==2){ // miércoles
      if(x%2 == 0) x--;
      else x++;
    }
    else if(dia[x]==3){ // jueves
      x += 10;
      if(x > 30) x-=30;
    }
    else if(dia[x]==4){ // viernes
      if(x%2 == 0) x/=2;
      else{
        x = 3*x+1;
        while(x>30) x-=30;
      }
    }
    else if(dia[x]==5){ // sábado
      x *= 2;
      if(x>30) x-=30;
    }
    else if(dia[x]==6){ // domingo
      int start=x;
      while(vis[x]){
        x+=2;
        if(x>30) x-=30;
        if(x == start) break;
      }
    }
  }
  cout << x << '\n';
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int d, x;
  cin >> d >> x;
  solve(d, x); // 0 para lunes, 6 para domingo
  return 0;
}
