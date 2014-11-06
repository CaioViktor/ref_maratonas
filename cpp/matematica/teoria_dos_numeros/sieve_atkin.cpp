const int max_n = 100000000;
vector<int> primes;
bool sieve[max_n];
 
void sieveOfAtkin(){
   int N = sqrt(max_n);
   memset(sieve, 0, sizeof(sieve));
   for (int x = 1; x <= N; x++){
      for (int y = 1; y <= N; y++){
         int n = (4*x*x)+(y*y);
         if (n <= max_n && (n % 12 == 1 || n % 12 == 5))
            sieve[n] ^= true;
         n = (3*x*x)+(y*y);
         if (n <= max_n && n % 12 == 7)
            sieve[n] ^= true;
         n = (3*x*x)-(y*y);
         if (x > y && n <= max_n && n % 12 == 11)
            sieve[n] ^= true;
      }
   }
   sieve[2] = sieve[3] = true;
   primes.push_back(2);
   primes.push_back(3);
   int a;
   for (a = 5; a <= N; a+=2){
      if (sieve[a]){
         for (int i = a*a; i < max_n; i += a*a)
            sieve[i] = false;
         primes.push_back(a);
      }
   }
   for (; a < max_n; a+=2) if (sieve[a])
      primes.push_back(a);
}
