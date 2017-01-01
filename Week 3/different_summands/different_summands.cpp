#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  //write your code here
  int i,j;
  for(i=1;;i++)
  {
    int sum = i*(i+1)/2;
    if(sum>n)
      break;
  }
  i--;
  for(j=1;j<i;j++)
    summands.push_back(j);

  int extra = n - i*(i+1)/2;
  summands.push_back(i+extra);


  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
