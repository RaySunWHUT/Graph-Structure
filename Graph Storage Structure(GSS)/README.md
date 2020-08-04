# Graph Structure:

1. #### 邻接表(Adjacency Lists)
  运行结果如下:

  ![result](https://github.com/RaySunWHUT/Graph-Structure/blob/master/assets/list.png)

  在无向图的邻接表中，顶点 $v_i$ 的 **度** 恰为第 i 个链表中的结点数；

  在有向图的邻接表中，第 i 个链表中的 **结点数** 只是顶点 $v_i$ 的 **出度**，但求 ***入度***  很不方便。可建立有向图的 **逆邻接表**，对每个顶点 $v_i$ 建立一个链接以  $v_i$ 为头的弧的链表。

    

2. #### 邻接矩阵(Adjacency Matrix)

