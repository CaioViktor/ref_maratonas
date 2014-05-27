inline bool acute(point o, point a, point b){
	return dot(toVec(o,a),toVec(o,b)) > 0;
}
