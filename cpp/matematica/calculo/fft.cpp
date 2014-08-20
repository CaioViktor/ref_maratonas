typedef complex<double> cd; // possivel otimizacao: usar struct no lugar
typedef vector<cd> vcd;

vcd fft(const vcd &as) {
  int n = as.size();
  int k = 0;
  while ((1 << k) < n) k++;
  vector<int> rev(n);
  rev[0] = 0;
  int high1 = -1;
  for (int i = 1; i < n; i++) {
    if ((i & (i - 1)) == 0)
      high1++;
    rev[i] = rev[i ^ (1 << high1)];
    rev[i] |= (1 << (k - high1 - 1));
  }

  vcd roots(n);
  for (int i = 0; i < n; i++) {
    double alpha = 2 * M_PI * i / n;
    roots[i] = cd(cos(alpha), sin(alpha));
  }

  vcd cur(n);
  for (int i = 0; i < n; i++)
    cur[i] = as[rev[i]];

  for (int len = 1; len < n; len <<= 1) {
    vcd ncur(n);
    int rstep = roots.size() / (len * 2);
    for (int pdest = 0; pdest < n;) {
      int p1 = pdest;
      for (int i = 0; i < len; i++) {
        cd val = roots[i * rstep] * cur[p1 + len];
        ncur[pdest] = cur[p1] + val;
        ncur[pdest + len] = cur[p1] - val;
        pdest++, p1++;
      }
      pdest += len;
    }
    cur.swap(ncur);
  }
  return cur;
}


vcd fft_rev(const vcd &as) {
  vcd res = fft(as);
  for (int i = 0; i < (int)res.size(); i++) res[i] /= as.size();
  reverse(res.begin() + 1, res.end());
  return res;
}

// utilizacao:
int n; // grau dos polinomios A e B
vcd A(2*n, 0), B(2*n, 0); // pols a serem multiplicados

// le A e B

vcd FA = fft(A), FB = fft(B), FC; // fourier
for(int i = 0; i < 2*N; i++){
  FC[i] = FA[i]*FB[i];
}
vcd C = fft_rev(C); // resultado da multiplicacao
