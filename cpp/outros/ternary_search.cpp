inline D ts(D lo, D hi){
  D m1, m2;
  while((hi - lo) > EPS){
      
    m1 = lo + (hi-lo)/3.;
    m2 = hi - (hi-lo)/3.;
    if(F(m1) < F(m2))
      lo = m1;
    else
      hi = m2;
  }
  return (lo+hi)/2;
}
