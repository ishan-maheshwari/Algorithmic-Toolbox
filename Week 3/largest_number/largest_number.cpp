#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

bool isSmall(string first, string second){
  int first_second = stoi(first + second);
  int second_first = stoi(second + first);

  if(first_second<second_first)
    return true;
  else return false;
}

string largest_number(vector<string> a) {
  //write your code here

  int n = a.size();

  for(int i=0;i<n-1;i++)
    for(int j=i+1;j<n;j++)
      if(isSmall(a[i],a[j])){
        string temp = a[i];
        a[i] = a[j];
        a[j] = temp;
      }

  std::stringstream ret;
  for (size_t i = 0; i < a.size(); i++) {
    ret << a[i];
  }
  string result;
  ret >> result;
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
