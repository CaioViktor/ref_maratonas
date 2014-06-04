inline point circumcenter(point a, point b, point c){
	double d = 2.*(a.x*(b.y - c.y) + b.x*(c.y - a.y) + c.x*(a.y - b.y));
	
	return point(((a.x*a.x + a.y*a.y)*(b.y - c.y) + (b.x*b.x + b.y*b.y)*(c.y - a.y) + (c.x*c.x + c.y*c.y) * (a.y - b.y))/d,
				  ((a.x*a.x + a.y*a.y)*(c.x - b.x) + (b.x*b.x + b.y*b.y)*(a.x - c.x) + (c.x*c.x + c.y*c.y) * (b.x - a.x))/d);
}
