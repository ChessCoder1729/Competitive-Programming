SegTree* seg
Calculate subtree size, depth, parent
Find heavy children

Decompose into chains
1. Store the head of each chain
2. Give the nodes a new index so that we can build a segtree on the nodes

For each query
while (head[u] != head[v]) {
       if (depth[head[u]] < depth[head[v]]) swap(u, v);
       seg->query(newPos[head[u]], newPos[u]);
       u = parent[head[u]];
}
if (depth[u] > depth[v]) swap(u, v);
seg->query(newPos[u], newPos[v]);
