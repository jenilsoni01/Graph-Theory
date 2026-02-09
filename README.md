# Graph Theory Practicals
1. Graph Representation: Use adjacency matrix, adjacency list and incidence matrix for representing the graph. Evaluate their memory usage for basic operations like adding and removing edges. Students will compare each of the presentation technique from memory utilization perspective
2. Graph Operations:
   - Implement set operations on two graphs such as union, intersection, complement, difference and ring sum.
   - Also generate the Maze and find the path from the start point to the end point. Students will find real life application of each operations on graph
3. Write a program to determine whether two graphs are isomorphic by verifying the following conditions:
   - The graphs have identical line graphs.
   - The graphs have the same number of cycles of the same lengths.
   - The adjacency matrices of the graphs satisfy the transformation A(G1) = P * A(G2) * PT
4. You are given a list of airline tickets where tickets[i] = [fromi, toi] represent the departure and the arrival airports of one flight. Reconstruct the itinerary in order and return it. All of the tickets belong to a man who departs from "JFK", thus, the itinerary must begin with "JFK". If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"]. You may assume all tickets form at least one valid itinerary. You must use all the tickets once and only once.(Hint: Euler Graph)
5. Use Havel-Hakimi theorem and check whether the given degree sequence is graphical or not.
6. You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target. We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1. (Hint: Dijkstra Algorithm)
7. Implement a program to enumerate all spanning trees and minimum spanning tree of a given complete directed graph. Students will apply various algorithms and compare the performance of each algorithm
8. Write a program to identify the minimum cut-edges in a graph using Kerger’s randomized
algorithm. Students will learn edge contraction.
9. Develop a program to find all articulation points in a graph by leveraging a Depth-First
Search (DFS) tree.
10. Write a program to check whether the graph is planar or not. Apply elementary reduction
and check for the resultant three condition of planarity.

Extra Definitions:
1.  Write a program to find the maximum clique from a given graph.
2.  Write a program to find the chromatic number of a given graph.
3.  Write a program to apply four-color conjecture to the LAN topology represented graphically.
4.  Write a program to check whether complete matching for bipartite graph exists or not.