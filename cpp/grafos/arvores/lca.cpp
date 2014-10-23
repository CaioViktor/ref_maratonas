class RMQ {
private:
  int _A[2*MAXN], SpT[2*MAXN][2*LOGTWON];
public:
  void build(int n, int A[]) {
    for (int i = 0; i < n; i++) { _A[i] = A[i]; SpT[i][0] = i; }
    
    for (int j = 1; (1<<j) <= n; j++)
      for (int i = 0; i + (1<<j) - 1 < n; i++)
        if (_A[SpT[i][j-1]] < _A[SpT[i+(1<<(j-1))][j-1]])
          SpT[i][j] = SpT[i][j-1];
        else
          SpT[i][j] = SpT[i+(1<<(j-1))][j-1];
  }

  int query(int i, int j) {
    int k = (int)floor(log((double)j-i+1) / log(2.0));
    if (_A[SpT[i][k]] <= _A[SpT[j-(1<<k)+1][k]]) return SpT[i][k];
    else return SpT[j-(1<<k)+1][k];
} };

class LCA{
private:
  RMQ rmq;
  int L[2*MAXN], E[2*MAXN], H[MAXN], idx;

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
public:
  void build(vvi & children){
    idx = 0;
    memset(H, -1, sizeof H);
    dfs(0, 0, children);
    rmq.build(idx,L);
  }
  int query(int u, int v){
    if(H[v] < H[u])swap(u,v);
    return E[rmq.query(H[u],H[v])];
  }
};
