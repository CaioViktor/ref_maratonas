class LCA{
private:
  int L[2*MAXN], E[2*MAXN], H[MAXN], idx, st[8*MAXN], n;

  void dfs(int cur, int depth, vvi & children) {
    H[cur] = idx;
    E[idx] = cur;
    L[idx++] = depth;
    for (int i = 0; i < (int)children[cur].size(); i++) {
      dfs(children[cur][i], depth+1, children);
      E[idx] = cur;
      L[idx++] = depth;
    }
  }
  void build_tree(int x, int l, int r, vvi & children){
    if(l == r)
      st[x] = l;
    else{
      build_tree(cl(x), l, (l+r)/2, children);
      build_tree(cr(x), (l+r)/2+1,r, children);
      if(L[st[cl(x)]] < L[st[cr(x)]]) st[x] = st[cl(x)];
      else st[x] = st[cr(x)];
    }
  }
  
  int query_tree(int x, int l, int r, int i, int j){
    if(i > r || j < l) return -1;
    if(l >= i && r <= j) return st[x];
    
    int vl = query_tree(cl(x), l, (l+r)/2, i, j),
      vr = query_tree(cr(x), (l+r)/2+1, r, i, j);
    
    if(vl == -1) return vr;
    if(vr == -1) return vl;
    if(L[vl] < L[vr]) return vl;
    return vr;
  }
public:
  void build(vvi & children){
    idx = 0;
    n = idx - 1;
    memset(H, -1, sizeof H);
    dfs(0, 0, children);
    build_tree(1,0, n, children);
  }
  int query(int u, int v){
    if(H[v] < H[u])swap(u,v);
    return E[query_tree(1,0,n,H[u],H[v])];
  }
};
