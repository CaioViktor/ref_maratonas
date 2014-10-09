class HLD{
private:
  LCA lca;
  int chainNo, chainPtr, n;
  int chainHead[MAXN], chainPos[MAXN], chainInd[MAXN];
  int arrBase[MAXN], tree_sz[MAXN], st[4*MAXN], parent[MAXN];

  void build_tree(int x, int l, int r){
    if(l == r) st[x] = arrBase[l];
    else{
      build_tree(cl(x), l, (l+r)/2);
      build_tree(cr(x), (l+r)/2+1, r);
      st[x] = min(st[cl(x)], st[cr(x)]);
    }
  }

  int query_tree(int x, int l, int r, int i, int j){
    if(j < l || i > r) return INF;
    if(l >= i && r <= j) return st[x];
    
    return min(query_tree(cl(x), l, (l+r)/2, i, j),
               query_tree(cr(x), (l+r)/2+1,r, i, j));
  }

  int query_up(int u, int v){
    if(u == v) return INF;
    
    int uchain, vchain = chainInd[v], ans = INF;
    
    while(1){
      uchain = chainInd[u];
      if(uchain == vchain){
        if(u == v) break;
        ans = min(ans,query_tree(1,0,n-1, chainPos[v]+1,chainPos[u]));
        break;
      }
      ans = min(ans,query_tree(1,0,n-1, chainPos[chainHead[uchain]], chainPos[u]));
      u = parent[chainHead[uchain]];
    }
    return ans;
  }

  int dfscnt(int u, vvi & children){
    int v;
    tree_sz[u] = 1;
    
    for(int i = 0; i < (int)children[u].sz(); i++){
      v = children[u][i];
      parent[v] = u;
      tree_sz[u] += dfscnt(v,children);
    }
    
    return tree_sz[u];
  }
  
  void hld(int u, int cst, vvi & children, vvi & costs){
    arrBase[chainPtr] = cst;
    if(chainHead[chainNo] == -1) chainHead[chainNo] = u;
    chainInd[u] = chainNo; chainPos[u] = chainPtr++;
    
    int ind = n, nc, v, w;
    for(int i = 0; i < (int) children[u].sz(); i++){
      v = children[u][i];
      w = costs[u][i];
      if(tree_sz[v] > tree_sz[ind]){
        ind = v;
        nc = w;
      }
    }
    if(ind == n) return;
    hld(ind, nc, children, costs);
    
    for(int i = 0; i < (int) children[u].sz(); i++){
      v = children[u][i];
      w = costs[u][i];
      if(v != ind){
        chainNo++;
        hld(v, w, children, costs);
      }
    }
  }

public:
  HLD(){
    lca = LCA();
  }
  void build(vvi & children, vvi & costs){
    memset(tree_sz, -1, sizeof tree_sz);
    n = children.size();
    dfscnt(0,children);
    
    chainNo = 0;
    memset(chainHead, -1, sizeof chainHead);
    chainPtr = 0;
    hld(0, INF, children, costs);
    
    lca.build(children);
    build_tree(1,0,n-1);
  }
  
  int query(int u, int v){
    int l = lca.query(u,v);
    return min(query_up(u,l), query_up(v,l));
  }
};
