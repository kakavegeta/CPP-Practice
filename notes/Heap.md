
1. build a heap can implement `siftUp` and `siftDown`  

2. when build a heap, we need to put operation on every node, which means that `siftDown` is better than `siftUp`  

3. a theorem: for a perfect binary tree of height h containing 2^(h+1)-1 nodes, the sum of the heights of the nodes is 2^(h+1)-1-(h+1).
This means that we can build a heap in O(n) in which n is the number of nodes.  

4. Leftist Heap:   
theorem: a leftist tree with r nodes on the right path must have at least 2^r-1 nodes.
Why leftist property?  
- the right path is short
- a leftist tree of N nodes has a right path of at most log2(N+1) nodes.
So we perform all work on the right path

