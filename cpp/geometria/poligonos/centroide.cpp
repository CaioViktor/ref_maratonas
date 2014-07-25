point C = point(0,0);

for(int i = 0; i < n; i++){
  C.x += (pts[i].x + pts[i+1].x)*(pts[i].x*pts[i+1].y - pts[i+1].x*pts[i].y);
  C.y += (pts[i].y + pts[i+1].y)*(pts[i].x*pts[i+1].y - pts[i+1].x*pts[i].y);
}
C.x /= area(pts);
C.y /= area(pts);
