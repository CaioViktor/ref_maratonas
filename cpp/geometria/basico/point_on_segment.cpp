bool onSegment(Point p, Point q, Point r)
{
    if (cross(toVec(p,r),toVec(p,q)) == 0 && 
		q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
       return true;
 
    return false;
}
