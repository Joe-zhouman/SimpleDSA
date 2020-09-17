#include <iostream>

#include "../../../include/list/List.h"
using namespace simple_dsa;
int main() {
  List<int> test_list;
  test_list.InsertAsLast(1);
  test_list.InsertAsLast(2);
  std::cout << test_list.Deduplicate();
}
