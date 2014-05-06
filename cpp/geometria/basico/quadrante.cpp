int quadrant(point o, point a){
	if(cross(toVec(o,a),point( 1, 0)) == 0)
		return (ccw(o, o + ay, a) ? 2 : 0);
	if(cross(toVec(o,a),point( 0, 1)) == 0)
		return (ccw(o, o + ax, a) ? 1 : 3);
	bool rAx = ccw(o, o + ax, a),
		 rAy = ccw(o, o + ay, a);
	
	if(!rAx && !rAy)	  return 3;
	else if(!rAx &&  rAy) return 2;
	else if( rAx && !rAy) return 0;
	else				  return 1;
}
