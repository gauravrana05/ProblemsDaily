#include <bits/stdc++.h>
#define bint long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define mod 1000000007
#define inf 1000000000
#define pi 3.141592653589793
#define br cout << endl;

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

#define rep(i, s, e) for (bint i = s; i < e; i++)
#define repD(i, s, e) for (bint i = s - 1; i >= e; i--)

#define repS(i, s, e, step) for (bint i = s; i < e; i += step)
#define repDS(i, s, e, step) for (bint i = s - 1; i >= e; i -= step)

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

using namespace std;

void setIO(string s)
{
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

const bint MAXM = 1e5 + 5;

vector<bint> factors[MAXM + 5];

void init()
{
  rep(i, 1, MAXM)
  {
    repS(j, i, MAXM, i)
    {
      factors[j].pb(i);
    }
  }
}
void solve()
{
  bint n, m;
  cin >> n >> m;
  vector<pair<int, int>> smartness(n);
  bint ctr = 0;
  for (auto &i : smartness)
  {
    read(i.first);
    i.second = ctr++;
  }

  sort(all(smartness));

  vector<bint> freq(m + 5, 0);
  bint cur_count = 0;
  bint j = 0;
  bint global_ans = 1e17;

  rep(i, 0, n)
  {
    for (auto x : factors[smartness[i].first])
    {
      if (x > m)
        break;
      if (!freq[x]++)
        cur_count++;
    }
    while (cur_count == m)
    {
      bint cur_ans = smartness[i].first - smartness[j].first;

      global_ans = min(cur_ans, global_ans);
      for (auto x : factors[smartness[j].first])
      {
        if (x > m)
          break;
        if (--freq[x] == 0)
        {
          cur_count--;
        }
      }
      j++;
    }
  }

  print((global_ans == 1e17 ? -1 : global_ans));
}

int main()
{
  ios_base::sync_with_stdio(0);
  init();
  int n;
  read(n);
  while (n--)
    solve();
  return 0;
}
