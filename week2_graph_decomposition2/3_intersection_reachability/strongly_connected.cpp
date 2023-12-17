#include <algorithm>
#include <iostream>
#include <vector>

using std::pair;
using std::vector;

void dfs2(vector<vector<int>> &adj, int vertex, vector<bool> &visited)
{
  visited[vertex] = true;

  for (int neigh : adj[vertex])
  {
    if (!visited[neigh])
    {
      dfs2(adj, neigh, visited);
    }
  }
}

void dfs1(vector<vector<int>> &adj, int vertex, vector<bool> &visited, vector<int> &topSort)
{
  visited[vertex] = true;

  for (int neigh : adj[vertex])
  {
    if (!visited[neigh])
    {
      dfs1(adj, neigh, visited, topSort);
    }
  }

  topSort.push_back(vertex);
}

int number_of_strongly_connected_components(vector<vector<int>> adj)
{
  vector<vector<int>> rev_adj(adj.size());
  for (size_t i = 0; i < adj.size(); ++i)
  {
    for (int neigh : adj[i])
    {
      rev_adj[neigh].push_back(i);
    }
  }
  vector<int> topSort;
  vector<bool> visited(adj.size(), false);
  for (size_t vertex = 0; vertex < adj.size(); ++vertex)
  {
    if (!visited[vertex])
    {
      dfs1(rev_adj, vertex, visited, topSort);
    }
  }

  reverse(topSort.begin(), topSort.end());
  fill(visited.begin(), visited.end(), false);
  int numComponents = 0;
  for (size_t itr = 0; itr < topSort.size(); ++itr)
  {
    int vertex = topSort[itr];
    if (!visited[vertex])
    {
      dfs2(adj, vertex, visited);
      numComponents += 1;
    }
  }

  return numComponents;
}

int main()
{
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int>> adj(n, vector<int>());
  for (size_t i = 0; i < m; i++)
  {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << number_of_strongly_connected_components(adj);
}
