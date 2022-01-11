#include "solution.hpp"

static int getSumOfDigits(int n) {
  int sum = 0;
  while (n != 0) {
    sum = sum + n % 10;
    n = n / 10;
  }
  return sum;
}

int solution(const hash_map_t* hash_map, const std::vector<int>& lookups) {
  int result = 0;

  for (size_t i = 0; i < lookups.size() - 1; i++) {
    hash_map->prefetch(lookups[i + 1]);
    if (hash_map->find(lookups[i])) {
      result += getSumOfDigits(lookups[i]);
    }
  }
  if (hash_map->find(lookups.back())) {
    result += getSumOfDigits(lookups.back());
  }

  return result;
}
