// pontos em cima do eixo: pertencem ao quadrante de maior indice
int quadrant(point o, point a){
  int x = a.x - o.x, y = a.y - o.y;
  if(x == 0 && y == 0) return 0;
  
  if(x >  0 && y >= 0) return 0;
  if(x <= 0 && y >  0) return 1;
  if(x <  0 && y <= 0) return 2;
  
  return 3;
}
