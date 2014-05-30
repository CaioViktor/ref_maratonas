dx = abs(a.x - b.x);
dy = abs(a.y - b.y);

// Qtde sem contar os pontos A e B
amt = gcd(min(dx,dy), max(dx,dy)) - 1;

// Para achar os pontos em lattices das bordas de um poligono simples:
int B = 0;
int dx, dy;
for (int i = 0; i < n; i++)
{
	dx = abs(pts[i].x - pts[(i+1)%n].x);
	dy = abs(pts[i].y - pts[(i+1)%n].y);
	B += gcd(min(dx,dy), max(dx,dy)) - 1;
}
B += n;
