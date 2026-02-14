Algorithms for finding MST

1. Kruskal Algorithm:
Keep adding minimum weight edge and don't add if cycle is being formed

2. Prim's Algorithm
Start at an arbitary node.
Use the minimum weight edge to join a node in the connected component to a node not in the component

3. Boruvka's Algorithm
During each iteration we find connected components in the graph formed by already added edges, and for each component we find the shortest edge that leads out of this component.
Number of iterations <= log n

Note for Boruvka's Algorithm:
In case of same weights:
Instead of just comparing weights, the algorithm compares tuples: (weight, edge_id)
