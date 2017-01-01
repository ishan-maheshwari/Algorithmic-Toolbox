#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

long long max_dot_product(vector<int> a, vector<int> b) {
  // write your code here

  int n = a.size();

  for(int i=0;i<n-1;i++)
    for(int j=i;j<n;j++)
      if(a[i]<a[j]){
        int temp = a[i];
        a[i]=a[j];
        a[j]=temp;
      }

  n = b.size();
  for(int i=0;i<n-1;i++)
    for(int j=i;j<n;j++)
      if(b[i]<b[j]){
        int temp = b[i];
        b[i] = b[j];
        b[j] = temp;
      }

  long long result = 0;
  for (size_t i = 0; i < a.size(); i++) {
    result += ((long long) a[i]) * b[i];
  }
  return result;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << max_dot_product(a, b) << std::endl;
}
