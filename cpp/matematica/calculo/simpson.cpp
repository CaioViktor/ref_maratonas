template<typename T>
double simps(double a, double b, T f) {
  return (f(a) + 4*f((a+b)/2) + f(b))*(b-a)/6;
}

template<typename T>
double integrate(double a, double b, T f){
  double m = (a+b)/2;
  double l = simps(a,m, f), r = simps(m,b, f), tot=simps(a,b, f);
  if (fabs(l+r-tot) < eps) return tot;
  return integrate(a,m,f)+integrate(m,b,f);
}

// exemplo de implementacao de f(X)
struct funcao{
    double operator() (const double &x){
        return x*x;
    }
} f;

double ans = integrate(1.0,3.0,f);
