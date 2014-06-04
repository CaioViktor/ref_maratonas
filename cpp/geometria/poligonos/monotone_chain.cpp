set<point> pts;
vector<point> up, dn;

void convexHull(){
	up.assign(pts.size(),point());
	dn.assign(pts.size(),point());
	int i = 0, j = 0;
	
	for(set<point>::iterator it = pts.begin(); it != pts.end(); ++it){
		while(i > 1 && ccw(up[i-2], up[i-1], *it)) i--;
		while(j > 1 && !ccw(dn[j-2], dn[j-1], *it)) j--;
		
		up[i++] = *it;
		dn[j++] = *it;
	}
	up.resize(i);
	dn.resize(j);
}
