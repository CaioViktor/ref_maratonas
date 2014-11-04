namespace FFT{
  struct Complex{
      double x,y;
      
      Complex(){}
      Complex(double _x, double _y):
          x(_x), y(_y){}
      
      void operator += (Complex &c){
          x += c.x; y += c.y;
      }
      
      Complex& operator -= (Complex &c){
          x -= c.x; y -= c.y;
          return *this;
      }
      
      Complex operator * (Complex &c){
          return Complex(x * c.x - y * c.y,x * c.y + y * c.x);
      }
  };

  Complex wn[2][MAXLGN];

  void init(){
    for(int i = 1,M = 2;i < MAXLGN; ++i,M <<= 1){
        wn[0][i] = Complex(cos(-2 * M_PI / M), sin(-2 * M_PI / M));
        wn[1][i] = Complex(cos(2 * M_PI / M), sin(2 * M_PI / M));
    }
  }

  Complex a[MAXN];
  void fft(int n, Complex A[], int s){
      int p = __builtin_ctz(n);
      
      for(int i = 0;i < n;++i) a[i] = A[i];
      
      for(int i = 0;i < n;++i){
          int rev = 0;
          
          for(int j = 0;j < p;++j){
              rev <<= 1;
              rev |= ((i >> j) & 1);
          }
          
          A[i] = a[rev];
      }
      
      Complex w,aux;
      int M = 2,K = 1;
      
      for(int i = 1;i <= p;++i,M <<= 1,K <<= 1){
          aux = wn[s == -1? 0 : 1][i];
          
          for(int j = 0;j < n;j += M){
              w = Complex(1,0);
              
              for(int l = j;l < K+j;++l){
                  Complex t = w * A[l + K],u = A[l];
                  
                  A[l] += t;
                  u -= t;
                  A[l + K] = u;
                  w = w * aux;
              }
          }
      }
      
      if(s == -1)
          for(int i = 0;i < n;++i)
              A[i].x /= n, A[i].y /= n;;
  }

  int nR;
  Complex P[MAXN], Q[MAXN];
  Complex R[MAXN];
  void mult(ll nP, const ll (&P_) [MAXN], ll nQ, const ll (&Q_) [MAXN], ll (&R_) [MAXN]){
      for(int i = 0; i < nP; i++) P[i] = Complex(P_[i], 0);
      for(int i = 0; i < nQ; i++) Q[i] = Complex(Q_[i], 0);
      nR = nP + nQ;
      while(__builtin_popcount(nR) > 1) nR += nR & -nR;

      for(int i = nP;i < nR;++i) P[i] = Complex(0,0);
      for(int i = nQ;i < nR;++i) Q[i] = Complex(0,0);
      
      fft(nR,P,1);
      fft(nR,Q,1);
      
      for(int i = 0;i < nR;i++) R[i] = P[i] * Q[i];
      
      fft(nR,R,-1);
      
      for(int i = 0; i < nR; i++) R_[i] = ll (R[i].x + .5);
  }
}
