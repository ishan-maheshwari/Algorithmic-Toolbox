#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

long long MaxPairwiseProduct(const vector<int>& numbers) {
  long long result = 0;
  int n = numbers.size();
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (((long long)numbers[i]) * numbers[j] > result) {
        result = ((long long)numbers[i])   * numbers[j];
      }
    }
  }
  return result;
}

long long FastProduct(const vector<int>& numbers){
  long long result = 0;
  int n = numbers.size();

  int largest=-1,second=-1;

  for(int i=0;i<n;i++)
    if(numbers[largest]<numbers[i] || largest == -1)
      largest = i;

  for(int i=0;i<n;i++)
    if((numbers[second]<numbers[i] || second == -1) && i!=largest)
      second = i;

  return ((long long)numbers[largest])*numbers[second];
}

int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    long long result = FastProduct(numbers);
    cout << result << "\n";
    return 0;
}
