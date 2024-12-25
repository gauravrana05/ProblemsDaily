#include <bits/stdc++.h>
using namespace std;

struct Event
{
  int time;
  int cow_id;
  bool is_start;
};
bool operator<(const Event &e1, const Event &e2)
{
  return e1.time < e2.time;
}
int main()
{
  freopen("lifeguards.in", "r", stdin);
  int n;
  cin >> n;
  vector<Event> events;

  for (int i = 0; i < n; i++)
  {
    int a, b;
    cin >> a >> b;
    events.push_back({a, i, true});
    events.push_back({b, i, false});
  }
  sort(events.begin(), events.end());
  vector<int> alone_time(n);
  set<int> active;
  int prev_time = 0;
  int total_time = 0;
  for (auto &e : events)
  {
    int cur_time = e.time;

    if (active.size() > 0)
      total_time += cur_time - prev_time;

    if (active.size() == 1)
      alone_time[*active.begin()] += cur_time - prev_time;

    if (e.is_start)
      active.insert(e.cow_id);
    else
      active.erase(e.cow_id);

    prev_time = cur_time;
  }

  int min_time = *min_element(alone_time.begin(), alone_time.end());
  freopen("lifeguards.out", "w", stdout);
  cout << total_time - min_time << endl;
}
