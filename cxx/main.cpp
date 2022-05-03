#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <vector>

void bubble_sort(std::vector<int> &a, std::size_t n) {
  bool swapped = true;
  while (swapped) {
    swapped = false;
    for (std::size_t i = 0; i < n - 1; i++) {
      if (a[i] > a[i + 1]) {
        std::swap(a[i], a[i + 1]);
        swapped = true;
      }
    }
  }
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    return 1;
  }

  std::size_t n = argc - 1;
  std::vector<int> a;
  for (std::size_t i = 1; i < argc; i++) {
    a.push_back(atoi(argv[i]));
  }

  bubble_sort(a, n);

  std::for_each(a.cbegin(), a.cend(),
                [](const auto &item) { std::cout << item << ", "; });
  std::cout << std::endl;
  return 0;
}
