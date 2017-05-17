#pragma once

#include <string>
#include <vector>
#include <set>

int dist[1200];
int path[1200];

struct cmp_
{
    bool operator()(const int& a, const int& b)const
    {
        return dist[a] < dist[b] || (dist[a] == dist[b] && a < b);
    }
};

std::set<int, cmp_> h;

class Dijkstra
{
public:
    Dijkstra(const std::string& strInstance)
        : m_nodes(0)
        , m_edges(0)
        , m_distance_graph(NULL)
    {
        // 
    }

    int Run(int start)
    {
        for (int i=0; i<m_nodes; ++i)
        {
            if (m_distance_graph[start][i]>0 && m_distance_graph[start][i]<INT_MAX)
            {
                paths[i] = m_distance_graph[start][i];
            }
        }

        return 0;
    }

    bool DijkstraPath(int start_, int* end_, int n)
    {
        int ret = -1;

        std::vector<bool> vec_visited(n, false);
        path[start_] = -1;

        for (int i = 0; i < n; ++i)
        {
            if (m_distance_graph[start_][i] > 0)
            {
                //dist[i] = ins->cost[start_][i];
                dist[i] = INT_MAX;
                path[i] = start_;
            }
            else
            {
                dist[i] = INT_MAX;
                path[i] = -1;
            }
        }
        dist[start_] = 0;

        h.clear();
        h.insert(start_);

        while (!h.empty())
        {
            start_ = *h.begin();
            h.erase(h.begin());

            if (vec_visited[start_])
            {
                continue;
            }

            vec_visited[start_] = true;

            for (int i = 0; i < n; ++i)
            {
                if (!vec_visited[i] && dist[i] > dist[start_] + m_distance_graph[start_][i])
                {
                    dist[i] = dist[start_] + m_distance_graph[start_][i];
                    path[i] = start_;
                    h.insert(i);
                }
            }
        }

        return false;
    }

    

private:
    int m_nodes;
    int m_edges;
    int** m_distance_graph;

    int* distances;
    int* paths;
};
