vector<point> chPts;

// Pegar p[i] do convex hull, na seguinte ordem: minX, minY, maxX, maxY
int p[4];

inline int nxt(int id){ return (id+1)%chPts.size(); }
inline int prev(int id){ return (id == 0 ? (int)chPts.size() : id) - 1;}

inline bool angle_cmp(int lhs, int rhs){
	bool reverse = false;
	if(lhs > rhs){
		reverse = true;
		swap(lhs,rhs);
	}
	bool cmp_res;
	point	pa = toVec(chPts[p[lhs]],chPts[nxt(p[lhs])]),
			pb = toVec(chPts[p[rhs]],chPts[nxt(p[rhs])]);
	
	if(lhs == 0 && rhs == 1) cmp_res = dot	(pa,pb) < -EPS;
	if(lhs == 0 && rhs == 2) cmp_res = cross(pa,pb) < -EPS;
	if(lhs == 0 && rhs == 3) cmp_res = dot	(pa,pb) > EPS;
	if(lhs == 1 && rhs == 2) cmp_res = dot	(pa,pb) < -EPS;
	if(lhs == 1 && rhs == 3) cmp_res = cross(pa,pb) < -EPS;
	if(lhs == 2 && rhs == 3) cmp_res = dot	(pa,pb) < -EPS;
	return cmp_res ^ reverse;
}

void rotatingCalipers(){
	int p0[4];
	
	for(int i = 0; i < 4; i++)
		p0[i] = p[(i+2)%4];
	
	double	ansAr = (chPts[p[2]].x - chPts[p[0]].x)*(chPts[p[3]].y - chPts[p[1]].y),
			ansPer = 2*((chPts[p[2]].x - chPts[p[0]].x)+(chPts[p[3]].y - chPts[p[1]].y));
	double l1, l2;
	while(1){
		int incr = -1, ia, ib, ic, id, ie;
		for(int i = 0; i < 4; i++){
			if(incr == -1 || angle_cmp(i,incr)){
				incr = i;
			}
		}
		if(incr == -1 || p[incr] == p0[incr]) break;
		// ia e ib: segmento
		ia = p[incr];
		ib = p[incr] = nxt(p[incr]);
		// ic e id: segundo lado
		ic = p[(incr+1)%4];
		id = p[(incr+3)%4];
		// ie: ponto oposto ao segmento
		ie = p[(incr+2)%4];
		
		l1 = distToLine(chPts[ie],chPts[ia],chPts[ib]);
		
		point pc, pd;
		// Implementacao do CP3: ultimo param recebe o ponto mais prox
		// em cima da reta
		distToLine(chPts[ic], chPts[ia],chPts[ib], pc);
		distToLine(chPts[id], chPts[ia],chPts[ib], pd);
		l2 = sqrt(dist2(pc,pd));
	
		ansAr = min(ansAr, l1*l2);
		ansPer = min(ansPer,2*(l1+l2));
	}
}
