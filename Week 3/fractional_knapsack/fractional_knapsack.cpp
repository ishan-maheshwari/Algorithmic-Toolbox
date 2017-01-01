#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;

  int n = weights.size();

  for(int i=0;i<n-1;i++)
    for(int j=i;j<n;j++)
      if((double)values[i]/weights[i]<(double)values[j]/weights[j]){
        int temp_val = values[i];
        values[i]=values[j];
        values[j]=temp_val;

        int temp_weight = weights[i];
        weights[i] = weights[j];
        weights[j] = temp_weight;
      }
      int k=0,sum=0;
      while(sum<=capacity && k<n)
      {
          sum+=weights[k];

          if(sum<=capacity)
            value+=(double)values[k];
          else {
            value += ((double)values[k]/weights[k])*(capacity - sum + weights[k]);
          }

          k++;
      }
  // write your code here

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
