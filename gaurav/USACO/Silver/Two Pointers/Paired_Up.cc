#include <bits/stdc++.h>

#define debug(...)                                                             \
  do                                                                           \
  {                                                                            \
    std::ostringstream debug_stream;                                           \
    debug_stream << "\033[1;32m" << #__VA_ARGS__ << " : \033[0m";              \
    debug_helper(debug_stream, __VA_ARGS__);                                   \
    std::cout << "\033[1;32m" << debug_stream.str() << "\033[0m" << std::endl; \
  } while (0);

template <typename T>
void debug_helper(std::ostringstream &os, const T &arg)
{
  os << arg;
}

template <typename T, typename... Args>
void debug_helper(std::ostringstream &os, const T &first, const Args &...args)
{
  os << first << ", ";
  debug_helper(os, args...);
}

#define rep(i, s, e) for (int i = s; i < e; i++)
#define repD(i, s, e) for (int i = s - 1; i >= e; i--)

#define repS(i, s, e, step) for (int i = s; i < e; i += step)
#define repDS(i, s, e, step) for (int i = s - 1; i >= e; i -= step)

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

void print(const std::vector<int> &vec)
{
  for (const auto &element : vec)
  {
    std::cout << element << " ";
  }
  std::cout << std::endl;
}

void print(const int arr[], int size)
{
  for (int i = 0; i < size; i++)
  {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

template <typename T>
void print(const T &variable)
{
  std::cout << variable << std::endl;
}

template <typename T, typename... Args>
void print(const T &first, const Args &...args)
{
  print(first);
  print(args...);
}

template <typename T>
void read(T &variable)
{
  std::cin >> variable;
}

template <typename T>
void read(std::vector<T> &vec)
{
  for (auto &element : vec)
  {
    std::cin >> element;
  }
}

template <typename T, typename... Args>
void read(T &first, Args &...args)
{
  read(first);
  read(args...);
}

#define bint long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define mod 1000000007
#define inf 1000000000
#define pi 3.141592653589793
#define br cout << endl;

using namespace std;

void setIO(string s)
{
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

void solve()
{
  bint n;
  read(n);
  vector<bint> cows;
  while (n--)
  {
    bint a, b;
    read(a, b);
    while (a--)
      cows.push_back(b);
  }

  std::sort(all(cows));

  bint st = 0, end = cows.size() - 1;
  bint ans = 0;
  while (st < end)
  {
    ans = max(ans, cows[st] + cows[end]);
    st++;
    end--;
  }

  print(ans);
}

int main()
{
  ios_base::sync_with_stdio(0);
  setIO("pairup");

  solve();
  return 0;
}
