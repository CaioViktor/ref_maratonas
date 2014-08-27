ll getNextLarger(ll a) {
 ll c = (a & -a);
 ll r = a+c;
  return ((((r ^ a) >> 2) / c) | r);
}
ll getNextSmaller(ll a) {
    return ~getNextLarger(~a);
}
