inline ll orientation(point p, point q, point r){
	return (q.second-p.second)*(r.first-p.first) - (q.first-p.first)*(r.second-p.second);
}

set<point> pts;
vector<point> up, dn;

void convexHull(){
	up.assign(pts.size(),point());
	dn.assign(pts.size(),point());
	int i = 0, j = 0;
	
	for(set<point>::iterator it = pts.begin(); it != pts.end(); ++it){
		while(i > 1 && orientation(up[i-2], up[i-1], *it) <= 0) i--;
		while(j > 1 && orientation(dn[j-2], dn[j-1], *it) >= 0) j--;
		
		up[i++] = *it;
		dn[j++] = *it;
	}
	up.resize(i);
	dn.resize(j);
}
