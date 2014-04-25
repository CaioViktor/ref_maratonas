/* - Utilizacao:

   - vni st; st_create(st, A); 
  		vni eh um vector de NodeInfo 
  		(A tambem eh um vni)
  		cria a segment tree com base nos dados em A

   - st_update_point(st, A, I, val);
  		atualiza a st com o val (NodeInfo) no indice I

   - NodeInfo res = st_query(st, A, beg, end);
  		retorna o NodeInfo com o resultado de uma 
  		query do indice 'beg' ao indice 'end'
 

   No exemplo abaixo, eh uma ST para fazer queries do tipo
   'quantos zeros e quantos negativos existem no intervalo'
 */

class NodeInfo {
  public:
    int zeroes;
    int negs;

  NodeInfo() {
    negs = 0;
    zeroes = 0;
  }

  static bool isOutOfRange(NodeInfo node) {
    return node.zeroes == -1;
  }

  static NodeInfo outOfRange() {
    NodeInfo res;
    res.zeroes = -1;
    return res;
  }

  static NodeInfo join(NodeInfo lhs, NodeInfo rhs) {
    NodeInfo res;
    res.zeroes = lhs.zeroes + rhs.zeroes;
    res.negs = lhs.negs + rhs.negs;
    return res;
  }

  //Retorna um noh com valor neutro, que nao interfira
  //na query
  static NodeInfo initialValue() {
    NodeInfo res;
    res.zeroes = 0;
    res.negs = 0;
    return res;
  }
};


typedef vector<NodeInfo> vni;

void st_build(vni &st, const vni &A, int vertex, int L, int R) {
  if (L == R)                              
    st[vertex] = A[L];                                     
  else {   
    int nL = 2 * vertex, nR = 2 * vertex + 1;
    st_build(st, A, nL, L              , (L + R) / 2);
    st_build(st, A, nR, (L + R) / 2 + 1, R          );
    NodeInfo lContent = st[nL] , rContent = st[nR];
    st[vertex] = NodeInfo::join(lContent,rContent);
} }

void st_create(vni &st, const vni &A) {       
  int len = (int)(2*pow(2.0, 
  	floor((log((double)A.size())/log(2.0)) + 1)));
  st.assign(len, NodeInfo::initialValue());
  st_build(st, A, 1, 0, (int)A.size() - 1);
}

NodeInfo st_query(vni &st, const vni &A, int vertex, 
int L, int R, int i, int j) {
  if (i >  R || j <  L) return NodeInfo::initialValue();   
  if (L >= i && R <= j) return st[vertex];            

  NodeInfo p1 = st_query(st, A, 2 * vertex, L, 
  				(L+R) / 2, i, j);
  NodeInfo p2 = st_query(st, A, 2 * vertex + 1, 
  				(L+R) / 2 + 1, R, i, j);

  if (NodeInfo::isOutOfRange(p1)) return p2;     
  if (NodeInfo::isOutOfRange(p2)) return p1;                                
  return NodeInfo::join(p1,p2); 
}

NodeInfo st_query(vni &st, const vni& A, int i, int j) {
  return st_query(st, A, 1, 0, (int)A.size() - 1, i, j); }


NodeInfo st_update_point(vni &st, vni &A, int node, int b, 
int e, int idx, NodeInfo new_value) {

  int i = idx, j = idx;

  if (i > e || j < b)
    return st[node];

  if (b == i && e == j) {
    A[i] = new_value;
    return st[node] = new_value; 
  }

  NodeInfo p1, p2;
  p1 = st_update_point(st, A, 2 * node, b, 
  			(b + e) / 2, idx, new_value);
  p2 = st_update_point(st, A, 2 * node + 1, (b+e)/2 + 1,
  			 e, idx, new_value);

  return st[node] = NodeInfo::join(p1,p2);
}

NodeInfo st_update_point(vni &st, vni &A, 
int idx, NodeInfo new_value) {
  return st_update_point(st, A, 1, 0, (int)A.size() - 1,
  			 idx, new_value); 
}