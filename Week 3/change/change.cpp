#include <iostream>

int get_change(int m) {
  //write your code here
	int ten,five,one;

	ten = m/10;
	five = (m%10)/5;
	one = (m%5);
	int n = ten+five+one;

  return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
