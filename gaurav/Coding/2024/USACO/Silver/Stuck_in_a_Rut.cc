
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
vector<array<int, 3>> north;
vector<array<int, 3>> east;
const int maxV = 1e4;
vector<int> adj[maxV];
vector<int> parent(maxV, -1);
vector<int> ansV(maxV);
using namespace std;

void setIO(string s)
{
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int dfs(int node, int parent)
{
  int ans = 1;
  for (int next : adj[node])
  {
    if (next != parent)
    {
      ans += dfs(next, node);
    }
  }
  ansV[node] = ans;
  return ans;
}

void solve()
{
  int n;
  read(n);
  vector<pair<int, int>> pos(n);
  rep(i, 0, n)
  {
    char d;
    read(d);
    pair<int, int> p;
    read(p.first, p.second);
    array<int, 3> varr = {p.ff, p.ss, i};
    if (d == 'E')
    {
      east.push_back(varr);
    }
    else
    {
      north.push_back(varr);
    }
    pos[i] = p;
  }

  vector<vector<int>> meetTime;
  for (auto nC : north)
  {
    for (auto eC : east)
    {
      int yT = eC[1] - nC[1];
      int xT = nC[0] - eC[0];

      if (xT == yT)
      {
        continue;
      }
      if (yT > xT && xT > 0)
      {
        meetTime.push_back({yT, nC[2], eC[2], 0});
      }
      else if (yT < xT && yT > 0)
      {
        meetTime.push_back({xT, eC[2], nC[2], 1});
      }
    }
  }
  sort(meetTime.begin(), meetTime.end());

  vector<int> ans(n, inf);
  for (auto mt : meetTime)
  {
    if (ans[mt[2]] == inf && ans[mt[1] == inf])
    {
      ans[mt[1]] = mt[0];
      adj[mt[2]].push_back(mt[1]);
      parent[mt[1]] = mt[2];
      continue;
    }
    if (ans[mt[1]] == inf)
    {
      if (mt[3])
      {
        int start = pos[mt[2]].ss;
        int end = start + ans[mt[2]];
        if (pos[mt[1]].ss >= start && pos[mt[1]].ss <= end)
        {
          ans[mt[1]] = mt[0];
          adj[mt[2]].push_back(mt[1]);
          parent[mt[1]] = mt[2];
        }
      }
      else
      {
        int start = pos[mt[2]].ff;
        int end = start + ans[mt[2]];

        if (pos[mt[1]].ff >= start && pos[mt[1]].ff <= end)
        {
          ans[mt[1]] = mt[0];
          adj[mt[2]].push_back(mt[1]);
          parent[mt[1]] = mt[2];
        }
      }
    }
  }
  rep(i, 0, n)
  {
    if (parent[i] == -1)
    {
      dfs(i, -1);
    }
  }
  for (auto i : ansV)
  {
    cout << i - 1 << endl;
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  setIO("filename");

  solve();
  return 0;
}
