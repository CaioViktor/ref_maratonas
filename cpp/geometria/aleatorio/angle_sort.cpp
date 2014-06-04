// Cmp para sort em sentido anti horario
bool cmp(point lhs, point lhs){
	int qR = quadrant(seeker, rhs),
		qL = quadrant(seeker, lhs);

	// Comparacao pelo quadrante primeiro garante a condicao de
	// transitividade do sort (se a > b e b > c , a > c)
	if(qR < qL) return true;
	if(qR > qL) return false;
	
	if(ccw(seeker, lhs.p, p)) return false;
	if(ccw(seeker, p, lhs.p)) return true;
	
	// Espaco normalmente populado por condicoes do sweep
	
	return true;
}
