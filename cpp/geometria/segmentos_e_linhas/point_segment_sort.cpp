inline bool cmpActive(line a, line b){
  if(a == b) return false; // if lines are the same, ignore

  // checks if b.p1 is in the sector defined by a.p1 and a.p2
  if(ccw(origin, a.p1, b.p1) && !ccw(origin, a.p2, b.p1)){
    // if it is, checks if b.p1 is on the same side of line a as origin
    return ccw(a.p1, a.p2, b.p1) !=  ccw(a.p1, a.p2, origin);
  }
  else if(ccw(origin, a.p1, b.p2) && !ccw(origin, a.p2, b.p2)){
    // if b.p1 isn't in the sector, but b.p2 is
    return ccw(a.p1, a.p2, b.p2) !=  ccw(a.p1, a.p2, origin);
  }
  else{
    // this was missing: when interval A is completely inside B, so we can
    // choose any point of A we want
    return ccw(b.p1, b.p2, a.p1) ==  ccw(b.p1, b.p2, origin);
  }
}
