# Tree Algorithm
## 搜索tree 的三种方法各自的特点




## All kinds of trees

## tree
1. 删除: 总是需要找到一个至少一个子节点为空, 如果采用一下方法删除,会导致整棵树向左边倾斜
```
 private Node delete(Node x, Key key) {
        if (x == null) return null;

        int cmp = key.compareTo(x.key);
        if      (cmp < 0) x.left  = delete(x.left,  key);
        else if (cmp > 0) x.right = delete(x.right, key);
        else { 
            if (x.right == null) return x.left;
            if (x.left  == null) return x.right;
            Node t = x;
            x = min(t.right);
            x.right = deleteMin(t.right);
            x.left = t.left;
        } 
        x.size = size(x.left) + size(x.right) + 1;
        return x;
    } 
```


### Balanced Tree


### AVL Tree

An AVL tree is a binary search tree which has the following properties:
1. The sub-trees of every node differ in height by at most one.
2. Every sub-tree is an AVL tree.

single rotation and double rotation

所有的插入只会导致一次的rotation:并不会,可以出现从下到上,一直旋转的情景
删除只会导致一次rotation : **有待证明**


### red black tree
1. Every node has a color either red or black.
2. Root of tree is always black.
3. There are no two adjacent red nodes (A red node cannot have a red parent or red child).
4. Every path from root to a NULL node has same number of black nodes.

The AVL trees are more balanced compared to Red Black Trees, but they may cause more rotations 
during insertion and deletion



### splay tree
1. in many application, when a node is accessed, it is likely to be access again in the near future
2. splay tree don't require the maintenance of height or balance information
3. down-top rotation need over head and too much special case **其实并不知道是哪一些special case**.
in top-down case,keep split the tree and assemble them at last

 

### B-tree
1. the root is either a leaf or has between 2 and M children
2. all non-leaf nodes(except the root) have between 向下取整(M / 2) and M children
3. all leaves are at the same depth
### top down splay tree

### AA-tree

### treap


### k-d tree

### B-tree



## head

### pairing heap


