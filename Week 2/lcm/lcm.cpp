#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

long long gcd(int a, int b)
{
	if(b==0)
		return a;
	else return gcd(b,a%b);
}


int main() {
  long long a, b;
  std::cin >> a >> b;
  std::cout <<(a*b)/gcd(a,b)<< std::endl;
  return 0;
}
