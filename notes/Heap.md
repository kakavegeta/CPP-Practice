
1. build a heap can implement `siftUp` and `siftDown`  
2. when build a heap, we need to put operation on every node, which means that `siftDown` is better than `siftUp`  
3. a theorm: for a perfect binary tree of height h containing 2^(h+1)-1 nodes, the sum of the heights of the nodes is 2^(h+1)-1-(h+1).
This means that we can build a heap in O(n) in which n is the number of nodes.  
