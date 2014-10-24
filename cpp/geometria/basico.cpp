// Dot product
inline int dot(const vec & a, const vec &b){
  return a.x*b.x + a.y*b.y;
}

// Cross product
inline int cross(const vec & a, const vec &b){
  return a.x*b.y - a.y*b.x;
}

// Returns orientation between vector a and vector b
// 1: CW/ -1: CCW
inline int orientation(const vec & a, const vec & b){
  L c = cross(a,b);
  if(c == 0) return 0;
  return c < 0 ? 1 : -1;
}


// Returns if point q is on segment pr
inline bool onSegment(const point & p, const point & q, const point & r)
{
    if (orientation(toVec(p, q), toVec(p, r)) == 0 &&
        q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
       return true;

    return false;
}

// The main function that returns true if line segment 'p1q1'
// and 'p2q2' intersect.
inline bool doIntersect(const point & p1, const point & q1,
                        const point & p2, const point & q2)
{
    // Find the four orientations needed
    int o1 = orientation(toVec(p1,q1),toVec(p1,p2));
    int o2 = orientation(toVec(p1,q1),toVec(p1,q2));
    int o3 = orientation(toVec(p2,q2),toVec(p2,p1));
    int o4 = orientation(toVec(p2,q2),toVec(p2,q1));

    // General case (it's being checked wether the points are on the segment)
    if (o1 != o2 && o3 != o4)
        return true;

    return false;
}

// Computes signed area * 2 of polygon
// If points in CW  -> signedA2 < 0
// If points in CCW -> signedA2 > 0
inline int signedA2(vector<point> &pts){
  L S = 0;
  for(size_t i = 0; i < pts.size(); i++){
    S += cross(pts[i],pts[(i+1)%pts.size()]);
  }
  return S;
}
