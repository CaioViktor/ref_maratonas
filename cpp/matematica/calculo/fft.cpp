typedef long double ld;

// usar o complex<ld> OU a struct -> a struct eh mais rapida
typedef complex<ld> base;

struct base{
  ld re, im;
  
  base(): re(0), im(0){}
  base(ld re): re(re), im(0){}
  base(ld re, ld im): re(re), im(im){}
  
  base operator+ (const base &rhs){
    return base(re + rhs.re, im + rhs.im);
  }
  
  base operator- (const base &rhs){
    return base(re - rhs.re, im - rhs.im);
  }
  
  base& operator *=(const base &rhs){
    ld r = re*rhs.re - im * rhs.im,
       i = im*rhs.re + re*rhs.im;
    re = r;
    im = i;
    return *this;
  }
  
  base operator* (const base &rhs){
    return base(re*rhs.re - im * rhs.im, im*rhs.re + re*rhs.im);
  }
  
  base& operator /=(const ld rhs){
    re /= rhs;
    im /= rhs;
    return *this;
  }
  
  ld real() const{ return re; }
};

const double PI = acos(-1.0);

void fft (vector<base> & a, bool invert)
{
	ll n = (int) a.size();

	for (int i=1, j=0; i<n; ++i) {
		int bit = n >> 1;
		for (; j>=bit; bit>>=1)
			j -= bit;
		j += bit;
		if (i < j)
			swap (a[i], a[j]);
	}

	for (int len=2; len<=n; len<<=1) {
		ld ang = 2*PI/len * (invert ? -1 : 1);
		base wlen (cos(ang), sin(ang));
		for (int i=0; i<n; i+=len) {
			base w (1);
			for (int j=0; j<len/2; ++j) {
				base u = a[i+j],  v = a[i+j+len/2] * w;
				a[i+j] = u + v;
				a[i+j+len/2] = u - v;
				w *= wlen;
			}
		}
	}
	if (invert)
		for (int i=0; i<n; ++i)
			a[i] /= n;
}


// Exemplo de utilizacao: multiplicacao de dois polinomios A e B em O(n log n)
void multiply (const vector<ll> & a, const vector<ll> & b, vector<ll> & res)
{
	vector<base> fa (a.begin(), a.end()),  fb (b.begin(), b.end());
	size_t n = 1;
	// n deve ser a menor potencia de 2 >= grau dos polinomios
	while (n < max (a.size(), b.size()))  n <<= 1;
	n <<= 1; // multiplica por 2 (G(P*Q) = G(P)+G(Q))
	fa.resize (n),  fb.resize (n);

	fft (fa, false),  fft (fb, false); // FFT dos polinomios
	for (size_t i=0; i<n; ++i)
		fa[i] *= fb[i];
	fft (fa, true); // FFT inverso da multiplicacao
	res.resize (n);
	for (size_t i=0; i<n; ++i)
		res[i] = ll (fa[i].real() + 0.5);
}
