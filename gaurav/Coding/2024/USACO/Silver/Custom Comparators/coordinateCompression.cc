#include <bits/stdc++.h>
using namespace std;

vector<int> compressCoordinates(vector<int> &original)
{
  vector<int> compressed = original;
  sort(compressed.begin(), compressed.end());
  compressed.erase(unique(compressed.begin(), compressed.end()), compressed.end());
  map<int, int> compressionMap;
  for (int i = 0; i < compressed.size(); i++)
  {
    compressionMap[compressed[i]] = i + 1;
  }
  for (int &value : original)
  {
    value = compressionMap[value];
  }
  return compressed;
}

int main()
{
  std::vector<int> original = {5, 2, 8, 5, 1, 2, 8, 3};

  std::cout << "Original array: ";
  for (const auto &val : original)
  {
    std::cout << val << " ";
  }
  std::cout << std::endl;

  // Perform coordinate compression
  std::vector<int> compressedValues = compressCoordinates(original);

  std::cout << "Compressed array: ";
  for (const auto &val : original)
  {
    std::cout << val << " ";
  }
  std::cout << std::endl;

  std::cout << "Unique compressed values: ";
  for (const auto &val : compressedValues)
  {
    std::cout << val << " ";
  }
  std::cout << std::endl;

  return 0;
}