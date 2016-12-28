#include <iostream>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

void multiply(long long A[2][2],long long B[2][2], long long m)
{
    long long x = ((((A[0][0]%m)*(B[0][0]%m))%m) + (((A[0][1]%m)*(B[1][0]%m))%m))%m;
    long long y = ((((A[0][0]%m)*(B[0][1]%m))%m) + (((A[0][1]%m)*(B[1][1]%m))%m))%m;
    long long z = ((((A[1][0]%m)*(B[0][0]%m))%m) + (((A[1][1]%m)*(B[1][0]%m))%m))%m;
    long long w = ((((A[1][0]%m)*(B[0][1]%m))%m) + (((A[1][1]%m)*(B[1][1]%m))%m))%m;

    A[0][0] = x;
    A[0][1] = y;
    A[1][0] = z;
    A[1][1] = w;

}


void power(long long A[2][2],long long n,long long m)
{
    if(n==0 || n==1)
        return;

    long long M[2][2]={{1,1},{1,0}};

    power(A,n/2,m);
    multiply(A,A,m);

    if(n%2!=0)
        multiply(A,M,m);

}

long long fib (long long n,long long m)
{
    if(n==0)
        return 0;

    long long A[2][2]={{1,1},{1,0}};

    power(A,n-1,m);

    return A[0][0]%m;
}

int main() {
    long long n = 0;
    std::cin >> n;
    long long m = 10;
    long long result = (fib(n+2,m)-1)%m;
    if(result<0)
        result += m;
    std::cout << result;
}
