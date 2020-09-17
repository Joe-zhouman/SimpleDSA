#include <iostream>

#include "../../../include/list/List.h"
using namespace simple_dsa;
void print(int v) { std::cout << v << std::endl; }

int main() {
  List<int> test_list;
  test_list.InsertAsLast(1);
  test_list.InsertAsLast(2);
  test_list.Traverse(print);
}