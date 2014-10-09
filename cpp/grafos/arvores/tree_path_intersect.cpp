inline bool between(int x, int s, int t){
  if(L[H[x]] < L[H[s]]) return false;
  if(L[H[x]] > L[H[t]]) return false;
  
  if(H[x] < H[s]) return false;
  if(H[x] > H[t]) return false;
  
  return E[query(H[x],H[t])] == x && E[query(H[s], H[x])] == s;
}

inline bool intersects(int u1, int v1, int l1, int u2, int v2, int l2){
  return between(l1,l2,u2) ||
          between(l1,l2,v2) ||
          between(l2,l1,u1) ||
          between(l2,l1,v1);
}
