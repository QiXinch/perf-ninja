
#include <array>

// Assume those constants never change
constexpr int N = 10000;
constexpr int minRandom = 0;
constexpr int maxRandom = 100;

struct S {
  float d;
  unsigned short l : 14;
  unsigned short b : 2;
  unsigned char i;
  unsigned char s;

  bool operator<(const S &s) const { return this->i < s.i; }
};

static_assert(sizeof(S) == 8);

void init(std::array<S, N> &arr);
S create_entry(int first_value, int second_value);
void solution(std::array<S, N> &arr);
