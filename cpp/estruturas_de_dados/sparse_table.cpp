#define MAX_N 1000    
#define LOG_TWO_N 10  // 2^10 > 1000

// L eh o array com os dados para ser montada a sparse table
// n eh o tamanho desse array

int SpT[MAX_N][LOG_TWO_N];
void buildSparseTable() {
  for (int i = 0; i < n; i++)
    SpT[i][0] = i; 
    
  for (int j = 1; (1<<j) <= n; j++) 
    for (int i = 0; i + (1<<j) - 1 < n; i++)    
      if (L[SpT[i][j-1]] < L[SpT[i+(1<<(j-1))][j-1]])            
        SpT[i][j] = SpT[i][j-1];    
      else                 
        SpT[i][j] = SpT[i+(1<<(j-1))][j-1];
}

int query(int i, int j) {
    int k = (int)floor(log((double)j-i+1) / log(2.0));
    if (L[SpT[i][k]] <= L[SpT[j-(1<<k)+1][k]])
      return SpT[i][k];
    else
      return SpT[j-(1<<k)+1][k];
}