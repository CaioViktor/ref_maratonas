// java.math.BigInteger

// Construtores, etc
new BigInteger(string) new BigInteger(string, radix)
BigInteger.ONE	BigInteger.ZERO
BigInteger.valueOf(numero)

// Operacoes matematicas (todas retornam um bi, n mudam ele)
bi2.abs();	
bi2.add(bi3); bi2.divide(bi3); bi2.multiply(bi3); bi2.subtract(bi3);	
bi2.divideAndRemainder(bi3);	//  Returns array of two BigIntegers representing the result of division and remainder of bi2 and bi3.
bi2.gcd(bi3) bi2.max(bi3); bi2.min(bi3);	//  Returns minimum of bi2 and bi3
bi2.mod(bi3) bi2.modPow(bi exp, bi m)
bi2.modInverse(bi3); // bi2^-1 mod bi3	
bi2.remainder(bi3);	// pode ser negativo
int bi.signum();	//  -1 for neg numbers, 0 for zero, and +1 for positive.
bi2.pow(bi3);
bi1.compareTo(bi2);	//  Returns negative number if bi1<bi2, 0 if bi1==bi2, or positive number if bi1>bi2.
bi.negate() // -this

bi.nextProbablePrime()

// Operacoes binarias, etc
bi.and(bi2) bi.or(bi2) bi.not() bi.xor(bi2)
bi.andNot(bi2) // this & ~val
bi.flipBit(n) bi.setBit(n) bi.clearBit(n)
bi.shiftLeft(n) bi.shiftRight(n)
int bi.getLowestSetBit()
bool bi.testBit(n)
bi.bitCount() // com o sinal
bi.bitLength() // sem o sinal

// Conversoes
bi.doubleValue() bi.floatValue() bi.intValue() bi.longValue() bi.toString()
bi.toString(i);	//  Returns string representation of bi in radix i.

