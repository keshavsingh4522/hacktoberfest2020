#include <cassert>   /// for assert
#include <iostream>  /// for io operations
#include <limits>    /// for variable INF
#include <queue>     /// for the priority_queue of distances
#include <utility>   /// for make_pair function
#include <vector>    /// for store the graph, the distances, and the path

constexpr int64_t INF = std::numeric_limits<int64_t>::max();

namespace graph {

namespace bidirectional_dijkstra {

void addEdge(std::vector<std::vector<std::pair<uint64_t, uint64_t>>> *adj1,
             std::vector<std::vector<std::pair<uint64_t, uint64_t>>> *adj2,
             uint64_t u, uint64_t v, uint64_t w) {
    (*adj1)[u - 1].push_back(std::make_pair(v - 1, w));
    (*adj2)[v - 1].push_back(std::make_pair(u - 1, w));
    // (*adj)[v - 1].push_back(std::make_pair(u - 1, w));
}

uint64_t Shortest_Path_Distance(
    const std::vector<uint64_t> &workset_,
    const std::vector<std::vector<uint64_t>> &distance_) {
    int64_t distance = INF;
    for (uint64_t i : workset_) {
        if (distance_[0][i] + distance_[1][i] < distance) {
            distance = distance_[0][i] + distance_[1][i];
        }
    }
    return distance;
}

int Bidijkstra(std::vector<std::vector<std::pair<uint64_t, uint64_t>>> *adj1,
               std::vector<std::vector<std::pair<uint64_t, uint64_t>>> *adj2,
               uint64_t s, uint64_t t) {
    /// n denotes the number of vertices in graph
    uint64_t n = adj1->size();

    /// setting all the distances initially to INF
    std::vector<std::vector<uint64_t>> dist(2, std::vector<uint64_t>(n, INF));

    std::vector<
        std::priority_queue<std::pair<uint64_t, uint64_t>,
                            std::vector<std::pair<uint64_t, uint64_t>>,
                            std::greater<std::pair<uint64_t, uint64_t>>>>
        pq(2);
    /// vector for store the nodes or vertices in the shortest path
    std::vector<uint64_t> workset(n);
    /// vector for store the nodes or vertices visited
    std::vector<bool> visited(n);

    /// pushing the source vertex 's' with 0 distance in pq[0] min heap
    pq[0].push(std::make_pair(0, s));

    /// marking the distance of source as 0
    dist[0][s] = 0;

    /// pushing the target vertex 't' with 0 distance in pq[1] min heap
    pq[1].push(std::make_pair(0, t));

    /// marking the distance of target as 0
    dist[1][t] = 0;

    while (true) {
        /// direct search

        // If pq[0].size() is equal to zero then the node/ vertex is not
        // reachable from s
        if (pq[0].size() == 0) {
            break;
        }
        /// second element of pair denotes the node / vertex
        uint64_t currentNode = pq[0].top().second;

        /// first element of pair denotes the distance
        uint64_t currentDist = pq[0].top().first;

        pq[0].pop();

        for (std::pair<int, int> edge : (*adj1)[currentNode]) {
            /// minimizing distances
            if (currentDist + edge.second < dist[0][edge.first]) {
                dist[0][edge.first] = currentDist + edge.second;
                pq[0].push(std::make_pair(dist[0][edge.first], edge.first));
            }
        }
        // store the processed node/ vertex
        workset.push_back(currentNode);

        /// check if currentNode has already been visited
        if (visited[currentNode] == 1) {
            return Shortest_Path_Distance(workset, dist);
        }
        visited[currentNode] = true;
        /// reversed search
        if (pq[1].size() == 0) {
            break;
        }
        /// second element of pair denotes the node / vertex
        currentNode = pq[1].top().second;

        /// first element of pair denotes the distance
        currentDist = pq[1].top().first;

        pq[1].pop();

        /// for all the reachable vertex from the currently exploring vertex
        /// we will try to minimize the distance
        for (std::pair<int, int> edge : (*adj2)[currentNode]) {
            /// minimizing distances
            if (currentDist + edge.second < dist[1][edge.first]) {
                dist[1][edge.first] = currentDist + edge.second;
                pq[1].push(std::make_pair(dist[1][edge.first], edge.first));
            }
        }
        // store the processed node/ vertex
        workset.push_back(currentNode);

        /// check if currentNode has already been visited
        if (visited[currentNode] == 1) {
            return Shortest_Path_Distance(workset, dist);
        }
        visited[currentNode] = true;
    }
    return -1;
}
}  // namespace bidirectional_dijkstra
}  // namespace graph

static void tests() {
    std::cout << "Initiatinig Predefined Tests..." << std::endl;
    std::cout << "Initiating Test 1..." << std::endl;
    std::vector<std::vector<std::pair<uint64_t, uint64_t>>> adj1_1(
        4, std::vector<std::pair<uint64_t, uint64_t>>());
    std::vector<std::vector<std::pair<uint64_t, uint64_t>>> adj1_2(
        4, std::vector<std::pair<uint64_t, uint64_t>>());
    graph::bidirectional_dijkstra::addEdge(&adj1_1, &adj1_2, 1, 2, 1);
    graph::bidirectional_dijkstra::addEdge(&adj1_1, &adj1_2, 4, 1, 2);
    graph::bidirectional_dijkstra::addEdge(&adj1_1, &adj1_2, 2, 3, 2);
    graph::bidirectional_dijkstra::addEdge(&adj1_1, &adj1_2, 1, 3, 5);

    uint64_t s = 1, t = 3;
    assert(graph::bidirectional_dijkstra::Bidijkstra(&adj1_1, &adj1_2, s - 1,
                                                     t - 1) == 3);
    std::cout << "Test 1 Passed..." << std::endl;

    s = 4, t = 3;
    std::cout << "Initiating Test 2..." << std::endl;
    assert(graph::bidirectional_dijkstra::Bidijkstra(&adj1_1, &adj1_2, s - 1,
                                                     t - 1) == 5);
    std::cout << "Test 2 Passed..." << std::endl;

    std::vector<std::vector<std::pair<uint64_t, uint64_t>>> adj2_1(
        5, std::vector<std::pair<uint64_t, uint64_t>>());
    std::vector<std::vector<std::pair<uint64_t, uint64_t>>> adj2_2(
        5, std::vector<std::pair<uint64_t, uint64_t>>());
    graph::bidirectional_dijkstra::addEdge(&adj2_1, &adj2_2, 1, 2, 4);
    graph::bidirectional_dijkstra::addEdge(&adj2_1, &adj2_2, 1, 3, 2);
    graph::bidirectional_dijkstra::addEdge(&adj2_1, &adj2_2, 2, 3, 2);
    graph::bidirectional_dijkstra::addEdge(&adj2_1, &adj2_2, 3, 2, 1);
    graph::bidirectional_dijkstra::addEdge(&adj2_1, &adj2_2, 2, 4, 2);
    graph::bidirectional_dijkstra::addEdge(&adj2_1, &adj2_2, 3, 5, 4);
    graph::bidirectional_dijkstra::addEdge(&adj2_1, &adj2_2, 5, 4, 1);
    graph::bidirectional_dijkstra::addEdge(&adj2_1, &adj2_2, 2, 5, 3);
    graph::bidirectional_dijkstra::addEdge(&adj2_1, &adj2_2, 3, 4, 4);

    s = 1, t = 5;
    std::cout << "Initiating Test 3..." << std::endl;
    assert(graph::bidirectional_dijkstra::Bidijkstra(&adj2_1, &adj2_2, s - 1,
                                                     t - 1) == 6);
    std::cout << "Test 3 Passed..." << std::endl;
    std::cout << "All Test Passed..." << std::endl << std::endl;
}

int main() {
    tests();  // running predefined tests
    uint64_t vertices = uint64_t();
    uint64_t edges = uint64_t();
    std::cout << "Enter the number of vertices : ";
    std::cin >> vertices;
    std::cout << "Enter the number of edges : ";
    std::cin >> edges;

    std::vector<std::vector<std::pair<uint64_t, uint64_t>>> adj1(
        vertices, std::vector<std::pair<uint64_t, uint64_t>>());
    std::vector<std::vector<std::pair<uint64_t, uint64_t>>> adj2(
        vertices, std::vector<std::pair<uint64_t, uint64_t>>());

    uint64_t u = uint64_t(), v = uint64_t(), w = uint64_t();
    std::cout << "Enter the edges by three integers in this form: u v w "
              << std::endl;
    std::cout << "Example: if there is and edge between node 1 and node 4 with "
                 "weight 7 enter: 1 4 7, and then press enter"
              << std::endl;
    while (edges--) {
        std::cin >> u >> v >> w;
        graph::bidirectional_dijkstra::addEdge(&adj1, &adj2, u, v, w);
        if (edges != 0) {
            std::cout << "Enter the next edge" << std::endl;
        }
    }

    uint64_t s = uint64_t(), t = uint64_t();
    std::cout
        << "Enter the source node and the target node separated by a space"
        << std::endl;
    std::cout << "Example: If the source node is 5 and the target node is 6 "
                 "enter: 5 6 and press enter"
              << std::endl;
    std::cin >> s >> t;
    int dist =
        graph::bidirectional_dijkstra::Bidijkstra(&adj1, &adj2, s - 1, t - 1);
    if (dist == -1) {
        std::cout << "Target not reachable from source" << std::endl;
    } else {
        std::cout << "Shortest Path Distance : " << dist << std::endl;
    }

    return 0;
}
