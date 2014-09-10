double lagrange(double p, vector<double> &x, vector<double> &y){
  double num, den, ans = 0;
  for(size_t i = 0; i < x.size(); i++){
    num = den = 1.0;
    for(size_t j = 0; j < x.size(); j++){
      num *= (p-x[j]);
      den *= (x[i]-x[j]);
    }
    ans += (num/den)*y[i];
  }
  return ans;
}
