Height of Centroid Tree = log2(n)

LCA of any 2 vertices in centroid tree, lies on path b/w the 2 vertices in actual tre
So we can decompose the given tree into NlogN different paths (from each centroid to every node in its subtree)
such that a path b/w any 2 nodes in actual tree can be represented as concatenation of 2 paths in centroid tree
