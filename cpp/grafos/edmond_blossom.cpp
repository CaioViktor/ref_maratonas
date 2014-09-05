
typedef vector<int> VI;
typedef vector<VI> VVI;

VI match;
VI vis;
 
void couple(int n, int m) { match[n]=m; match[m]=n; }
 
bool dfs(int n, VVI &conn, VI &blossom, int &N) {
  vis[n]=0;
  for(int i = 0; i < N; i++) if(conn[n][i]) {
    if(vis[i]==-1) {
      vis[i]=1;
      if(match[i]==-1 || dfs(match[i], conn, blossom, N)) {
        couple(n,i);
        return true;
      }
    }
    if(vis[i]==0 || blossom.size()) {  // found flower
      blossom.push_back(i); blossom.push_back(n);
      if(n==blossom[0]) { match[n]=-1; return true; }
      return false;
    }
  }
  return false;
}

bool augment(VVI &conn, int &N) {
  for(int m = 0; m < N; m++) if(match[m]==-1) {
    VI blossom;
    vis=VI(N,-1);
    if(!dfs(m, conn, blossom, N)) continue;
    if(blossom.size()==0) return true; 
 
    int base=blossom[0], S=blossom.size();
    VVI newconn=conn;
    for(int i = 1; i < S-1; i++)
      for(int j = 0; j < N; j++)
        newconn[base][j]=newconn[j][base]|=conn[blossom[i]][j];
    for(int i = 1; i < S-1; i++)
      for(int j = 0; j < N; j++)
        newconn[blossom[i]][j]=newconn[j][blossom[i]]=0;
    newconn[base][base]=0; // is now the new graph
    if(!augment(newconn, N)) return false;
    int n=match[base];
 
// if n!=-1 the augmenting path ended on this blossom
 
    if(n!=-1) for(int i = 0; i < S; i++) if(conn[blossom[i]][n]) {
      couple(blossom[i], n);
      if(i&1) for(int j=i+1; j<S; j+=2) couple(blossom[j],blossom[j+1]);
      else for(int j=0; j<i; j+=2) couple(blossom[j],blossom[j+1]);
      break;
    }
    return true;
  }
  return false;
}
 

// input: AdjMat[N][N]
// output: matching
int edmonds(VVI &conn, int N) {
  int res=0;
  match=VI(N,-1);
  while(augment(conn, N)) res++;
  return res;
}
