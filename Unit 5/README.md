### DSA Practical No. 57

Title: Represent routers and communication links with non-negative weights, and apply Dijkstra's algorithm to determine the minimum-cost paths from a source router to all reachable routers.

### 1\. Aim

To implement Dijkstra's Algorithm to find the minimum-cost paths from a source router to all reachable routers in a computer network.

### 2\. Objectives

* To understand the concept of Graph Data Structure.

* To represent routers as vertices and communication links as edges.

* To assign non-negative weights to communication links.

* To implement Dijkstra's Shortest Path Algorithm using C++.

* To find the minimum-cost path from a source router to all other reachable routers.

### 3\. Problem Statement

Represent routers and communication links with non-negative weights, and apply Dijkstra's algorithm to determine the minimum-cost paths from a source router to all reachable routers.

### 4\. Theory

Dijkstra's Algorithm is a shortest-path algorithm used in graph theory. It finds the minimum-cost path from a selected source vertex to all other reachable vertices in a weighted graph.

In a computer network, routers are represented as vertices and communication links are represented as edges. Each edge has a weight representing the communication cost.

The algorithm works with non-negative edge weights and repeatedly selects the router having the minimum known distance.

### 5\. Algorithm

* Start the program.

* Enter the number of routers and communication links.

* Create a weighted graph using an adjacency list.

* Enter the router connections and their costs.

* Select the source router.

* Initialize the source distance to zero and all other distances to infinity.

* Insert the source router into a priority queue.

* Select the router with the minimum distance.

* Update the distances of its neighbouring routers if a shorter path is found.

* Repeat until the priority queue becomes empty.

* Display the minimum cost and path for each reachable router.

* Stop the program.

### 6\. Data Structures Used

* Graph: Represents the computer network.

* Vector: Stores routers and their connections.

* Priority Queue: Selects the router with minimum distance.

* Parent Array: Stores the previous router to reconstruct the path.

* Distance Array: Stores the minimum cost to reach each router.

### 7\. Applications

* Computer network routing.

* GPS navigation systems.

* Shortest path finding.

* Network communication optimization.

* Transportation and road networks.

### 8\. Time Complexity

O((V+E)\\log V)

Where:

* V = Number of vertices (routers).

* E = Number of edges (communication links).

Space Complexity:

O(V+E)

### 9\. Advantages

* Finds minimum-cost paths efficiently.

* Easy to implement using graphs.

* Useful in computer network routing.

* Handles multiple routers and connections.

* Identifies unreachable routers.

### 10\. Limitations

* Does not work correctly with negative edge weights.

* Requires knowledge of the network connections and their costs.

* Performance depends on graph size and representation.

### 11\. Expected Output

```text
Minimum-cost paths from Router R1:

Router  Minimum Cost  Path
R1      0             R1
R2      3             R1 -> R3 -> R2
R3      1             R1 -> R3
R4      4             R1 -> R3 -> R2 -> R4
R5      7             R1 -> R3 -> R2 -> R4 -> R5
```

### 12\. Conclusion

Thus, we successfully implemented Dijkstra's Algorithm using C++. The program calculates the minimum-cost paths from a selected source router to all reachable routers in a weighted computer network. It helps in finding efficient communication routes and optimizing network connections.