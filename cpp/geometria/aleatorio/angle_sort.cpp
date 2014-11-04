// Cmp para sort em sentido anti horario
inline bool cmp(const point & lhs, const point & rhs){
	// Comparacao pelo quadrante primeiro garante a condicao de
	// transitividade do sort (se a > b e b > c , a > c)
	if(lhs.y >= pivot.y  && rhs.y < pivot.y) return true;
	if(lhs.y < pivot.y && rhs.y >= pivot.y) return false;
	
	if(cross(toVec(pivot,lhs),toVec(pivot,rhs)) > 0) return true;

	return false;
}
