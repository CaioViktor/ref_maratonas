int A2 = 0;
// Para poligono simples e pontos ordenados em sentido horario ou anti-
// horario
for (int i = 0; i < n; i++)
{
	A2 += pts[i].x*pts[(i+1)%n].y - pts[(i+1)%n].x*pts[i].y;
}
// A2 sera negativo se o sentido for horario
double A = abs(A2)/2;
