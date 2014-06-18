
#define INF 0x7fffffffffffffffLL
#define MAXN 2222
#define MAXM 22222

int h[MAXN],p[MAXN];
int u[MAXM],v[MAXM],next[MAXM];
int flow[MAXM],c;
int d[MAXN],cst[MAXM];

int e,n;

void reset(){
    memset(h,-1,sizeof h);
    e = 0;
}

void add(int u_, int v_, ll cst_, ll w_){
    u[e]=u_;      v[e]=v_;
    flow[e]=w_;     cst[e]=cst_;
    next[e]=h[u_];    h[u_]=e;
    e++;
}


void Bellman_Ford(int s){ // Dijkstra, na verdade
    int inq[MAXN];
    queue<int> q;
    memset(inq, 0,sizeof(inq));

    for(int i=0; i<=n; i++) {
        d[i]=INF;
        d[s]=0;
    }
    q.push(s);  
    inq[s]=1;

    while(!q.empty()){
        int u_ = q.front(); q.pop();
        inq[u_]=0;
        for(int x=h[u_]; x!=-1; x=next[x])
          if(flow[x] && d[u_]+cst[x]<d[v[x]]){
            d[v[x]] = d[u_] + cst[x];     
            p[v[x]]=x;
            if(!inq[v[x]]){
                q.push(v[x]);
                inq[v[x]]=1;
            }
          }
    }
}

// Retorna o flow maximo, se quiser o cost, basta pegar var global c
int mcmf(int s, int t){      
    int f=0;     c=0;
    p[s]=-1;           
    while(true){
        Bellman_Ford(s);

        if(d[t] == INF) break;
        ll a=INF;
        for(int x=p[t]; x!=-1; x=p[u[x]])
            a=min(a,flow[x]);
        for(int x=p[t]; x!=-1; x=p[u[x]]){
            flow[x]-=a;
            flow[x^1]+=a;                      
        }
        c+=d[t]*a;
        f+=a;
    }
    return f;
}

// Exemplo de utilizacao:
// Para cada edge no grafo, adiciona-se a edge inversa logo apos, com o
// peso negativo e capacidade nula
add(u,v, w, cap);
add(v,u, -w, 0);
