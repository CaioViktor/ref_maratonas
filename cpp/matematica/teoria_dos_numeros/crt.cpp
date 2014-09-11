
typedef pair<int,int> bezout;
bezout find_bezout(int x, int y){
  if(y == 0) return bezout(1,0);
  bezout u = find_bezout(y, x%y);
  return bezout(u.second, u.first - (x/y)*u.second);
}

int mod(int x, int m){ return x%m + ((x < 0) ? m : 0); }
int solve_mod(int a, int b, int m){
  if(m < 0) return solve_mod(a,b,-m);
  if(a < 0 || a >= m || b < 0 || b >= m)
    return solve_mod(mod(a,m), mod(b,m), m);
  bezout t = find_bezout(a,m);
  int d = t.first * a + t.second * m;
  if(b % d) return -1;
  else return mod(t.first * (b/d), m);
}

int chinese_remainder(vector<int> &b, vector<int> &m){
  int b0 = b[0], m0 = m[0], d;
  for(int i = 1; i < (int)b.size(); i++){
    d = gcd(m0, m[i]);
    if(d != 1 && (b0-b[i]) % d != 0) return -1;
    b0 = b0 + ( solve_mod(m0/d, (b[i]-b0)/d, m[i]/d) )*m0;
    m0 = lcm(m0,m[i]);
    b0 = mod(b0,m0);
  }
  return b0;
}
