inline bool cmp(line a, line b){
  if(a == b){
    return false;
  }
   
  if(ccw(origin, a.first, b.first) && !ccw(origin, a.second, b.first)){
    return ccw(a.first, a.second, b.first) !=  ccw(a.first, a.second, origin);
  }
  else if(ccw(origin, a.first, b.second) && !ccw(origin,a.second, b.second)){
    return ccw(a.first,a.second, b.second) !=  ccw(a.first,a.second, origin);
  }
  else{
    return ccw(b.first, b.second, a.first) == ccw(b.first, b.second, origin);
  }
}
