# 洛谷模板题代码索引

核对日期：2026-10-24。按洛谷当前标题是否以 `【模板】` 开头筛选，确认 **44 道题、57 份 C++ 源码**，另迁入原有的 `P8306/Trie.md`。不同实现全部保留，源码内容与编码未改动。

核对依据：[洛谷题库搜索](https://www.luogu.com.cn/problem/list?keyword=%E3%80%90%E6%A8%A1%E6%9D%BF%E3%80%91)。读取 6 页共 287 个结果，再严格筛出 199 个前缀匹配题目，与项目中的题号、文件名及代码输入输出交叉核对。

文件按 `luogu_templates/<题号>/<原文件名>` 存放。编译器任务使用当前文件所在目录，因此可继续单独打开、编译每份源码。

完整学习笔记在 Obsidian 的 `OI/07 General Techniques/Luogu Template Problems.md`。

## 文件索引

| 题号与当前标题 | 分类 / 本地实现 | 代码 |
| --- | --- | --- |
| [B3647 【模板】Floyd](https://www.luogu.com.cn/problem/B3647) | 图论：Floyd 全源最短路 | [【模板】Floyd.cpp](<B3647/%E3%80%90%E6%A8%A1%E6%9D%BF%E3%80%91Floyd.cpp>) |
| [P3366 【模板】最小生成树](https://www.luogu.com.cn/problem/P3366) | 图论：Kruskal + 并查集 | [【模板】最小生成树.cpp](<P3366/%E3%80%90%E6%A8%A1%E6%9D%BF%E3%80%91%E6%9C%80%E5%B0%8F%E7%94%9F%E6%88%90%E6%A0%91.cpp>) |
| [P3371 【模板】单源最短路径（弱化版）](https://www.luogu.com.cn/problem/P3371) | 图论：SPFA 单源最短路 | [【模板】单源最短路径（弱化版）.cpp](<P3371/%E3%80%90%E6%A8%A1%E6%9D%BF%E3%80%91%E5%8D%95%E6%BA%90%E6%9C%80%E7%9F%AD%E8%B7%AF%E5%BE%84%EF%BC%88%E5%BC%B1%E5%8C%96%E7%89%88%EF%BC%89.cpp>) |
| [P3379 【模板】最近公共祖先（LCA）](https://www.luogu.com.cn/problem/P3379) | 图论：树链剖分求 LCA | [【模板】最近公共祖先（LCA）(树链剖分).cpp](<P3379/%E3%80%90%E6%A8%A1%E6%9D%BF%E3%80%91%E6%9C%80%E8%BF%91%E5%85%AC%E5%85%B1%E7%A5%96%E5%85%88%EF%BC%88LCA%EF%BC%89%28%E6%A0%91%E9%93%BE%E5%89%96%E5%88%86%29.cpp>) |
| [P3384 【模板】重链剖分 / 树链剖分](https://www.luogu.com.cn/problem/P3384) | 图论：重链剖分 + 懒标记线段树 | [【模板】重链剖分&树链剖分.cpp](<P3384/%E3%80%90%E6%A8%A1%E6%9D%BF%E3%80%91%E9%87%8D%E9%93%BE%E5%89%96%E5%88%86%26%E6%A0%91%E9%93%BE%E5%89%96%E5%88%86.cpp>) |
| [P3385 【模板】负环](https://www.luogu.com.cn/problem/P3385) | 图论：SPFA 判负环 | [【模板】负环.cpp](<P3385/%E3%80%90%E6%A8%A1%E6%9D%BF%E3%80%91%E8%B4%9F%E7%8E%AF.cpp>) |
| [P3386 【模板】二分图最大匹配](https://www.luogu.com.cn/problem/P3386) | 图论：增广路二分图匹配 | [【模板】二分图最大匹配.cpp](<P3386/%E3%80%90%E6%A8%A1%E6%9D%BF%E3%80%91%E4%BA%8C%E5%88%86%E5%9B%BE%E6%9C%80%E5%A4%A7%E5%8C%B9%E9%85%8D.cpp>) |
| [P3387 【模板】缩点 / 强连通分量](https://www.luogu.com.cn/problem/P3387) | 图论：Tarjan SCC + DAG 最长路 | [P3387.cpp](<P3387/P3387.cpp>) · [【模板】缩点.cpp](<P3387/%E3%80%90%E6%A8%A1%E6%9D%BF%E3%80%91%E7%BC%A9%E7%82%B9.cpp>) |
| [P3388 【模板】割点](https://www.luogu.com.cn/problem/P3388) | 图论：Tarjan 割点 | [P3388.cpp](<P3388/P3388.cpp>) · [【模板】割点（割顶）.cpp](<P3388/%E3%80%90%E6%A8%A1%E6%9D%BF%E3%80%91%E5%89%B2%E7%82%B9%EF%BC%88%E5%89%B2%E9%A1%B6%EF%BC%89.cpp>) |
| [P4779 【模板】单源最短路径（标准版）](https://www.luogu.com.cn/problem/P4779) | 图论：堆优化 Dijkstra | [【模板】单源最短路径（标准版）.cpp](<P4779/%E3%80%90%E6%A8%A1%E6%9D%BF%E3%80%91%E5%8D%95%E6%BA%90%E6%9C%80%E7%9F%AD%E8%B7%AF%E5%BE%84%EF%BC%88%E6%A0%87%E5%87%86%E7%89%88%EF%BC%89.cpp>) |
| [P7771 【模板】欧拉路径](https://www.luogu.com.cn/problem/P7771) | 图论：Hierholzer 有向图欧拉路径 | [【模板】欧拉路径.cpp](<P7771/%E3%80%90%E6%A8%A1%E6%9D%BF%E3%80%91%E6%AC%A7%E6%8B%89%E8%B7%AF%E5%BE%84.cpp>) |
| [P8435 【模板】点双连通分量](https://www.luogu.com.cn/problem/P8435) | 图论：Tarjan 点双连通分量 | [【模板】点双连通分量.cpp](<P8435/%E3%80%90%E6%A8%A1%E6%9D%BF%E3%80%91%E7%82%B9%E5%8F%8C%E8%BF%9E%E9%80%9A%E5%88%86%E9%87%8F.cpp>) |
| [P8436 【模板】边双连通分量](https://www.luogu.com.cn/problem/P8436) | 图论：Tarjan 边双连通分量 | [【模板】边双连通分量-1.cpp](<P8436/%E3%80%90%E6%A8%A1%E6%9D%BF%E3%80%91%E8%BE%B9%E5%8F%8C%E8%BF%9E%E9%80%9A%E5%88%86%E9%87%8F-1.cpp>) · [【模板】边双连通分量.cpp](<P8436/%E3%80%90%E6%A8%A1%E6%9D%BF%E3%80%91%E8%BE%B9%E5%8F%8C%E8%BF%9E%E9%80%9A%E5%88%86%E9%87%8F.cpp>) |
| [P3367 【模板】并查集](https://www.luogu.com.cn/problem/P3367) | 数据结构：并查集 | [【模板】并查集.cpp](<P3367/%E3%80%90%E6%A8%A1%E6%9D%BF%E3%80%91%E5%B9%B6%E6%9F%A5%E9%9B%86.cpp>) |
| [P3368 【模板】树状数组 2](https://www.luogu.com.cn/problem/P3368) | 数据结构：差分 + 树状数组 | [【模板】树状数组 2.cpp](<P3368/%E3%80%90%E6%A8%A1%E6%9D%BF%E3%80%91%E6%A0%91%E7%8A%B6%E6%95%B0%E7%BB%84%202.cpp>) |
| [P3369 【模板】普通平衡树](https://www.luogu.com.cn/problem/P3369) | 数据结构：普通平衡树：Treap / 替罪羊树 / vector | [【模板】普通平衡树(rotate treap实现).cpp](<P3369/%E3%80%90%E6%A8%A1%E6%9D%BF%E3%80%91%E6%99%AE%E9%80%9A%E5%B9%B3%E8%A1%A1%E6%A0%91%28rotate%20treap%E5%AE%9E%E7%8E%B0%29.cpp>) · [【模板】普通平衡树(替罪羊树实现).cpp](<P3369/%E3%80%90%E6%A8%A1%E6%9D%BF%E3%80%91%E6%99%AE%E9%80%9A%E5%B9%B3%E8%A1%A1%E6%A0%91%28%E6%9B%BF%E7%BD%AA%E7%BE%8A%E6%A0%91%E5%AE%9E%E7%8E%B0%29.cpp>) · [【模板】普通平衡树(STL实现).cpp](<P3369/%E3%80%90%E6%A8%A1%E6%9D%BF%E3%80%91%E6%99%AE%E9%80%9A%E5%B9%B3%E8%A1%A1%E6%A0%91%28STL%E5%AE%9E%E7%8E%B0%29.cpp>) |
| [P3372 【模板】线段树 1](https://www.luogu.com.cn/problem/P3372) | 数据结构：区间加、区间和：双树状数组 / 线段树 | [【模板】线段树 1.cpp](<P3372/%E3%80%90%E6%A8%A1%E6%9D%BF%E3%80%91%E7%BA%BF%E6%AE%B5%E6%A0%91%201.cpp>) · [【模板】线段树 1(纯正线段树版本).cpp](<P3372/%E3%80%90%E6%A8%A1%E6%9D%BF%E3%80%91%E7%BA%BF%E6%AE%B5%E6%A0%91%201%28%E7%BA%AF%E6%AD%A3%E7%BA%BF%E6%AE%B5%E6%A0%91%E7%89%88%E6%9C%AC%29.cpp>) · [segment_tree.cpp](<P3372/segment_tree.cpp>) |
| [P3373 【模板】线段树 2](https://www.luogu.com.cn/problem/P3373) | 数据结构：带乘法与加法标记的线段树 | [【模板】线段树 2.cpp](<P3373/%E3%80%90%E6%A8%A1%E6%9D%BF%E3%80%91%E7%BA%BF%E6%AE%B5%E6%A0%91%202.cpp>) |
| [P3374 【模板】树状数组 1](https://www.luogu.com.cn/problem/P3374) | 数据结构：树状数组单点加、区间和 | [【模板】树状数组 1.cpp](<P3374/%E3%80%90%E6%A8%A1%E6%9D%BF%E3%80%91%E6%A0%91%E7%8A%B6%E6%95%B0%E7%BB%84%201.cpp>) |
| [P3378 【模板】堆](https://www.luogu.com.cn/problem/P3378) | 数据结构：priority_queue 小根堆 | [堆.cpp](<P3378/%E5%A0%86.cpp>) |
| [P3865 【模板】ST 表 & RMQ 问题](https://www.luogu.com.cn/problem/P3865) | 数据结构：Sparse Table 静态区间最大值 | [ST 表 && RMQ 问题.cpp](<P3865/ST%20%E8%A1%A8%20%26%26%20RMQ%20%E9%97%AE%E9%A2%98.cpp>) |
| [P5490 【模板】扫描线 & 矩形面积并](https://www.luogu.com.cn/problem/P5490) | 数据结构：扫描线 + 覆盖长度线段树 | [【模板】扫描线 & 矩形面积并.cpp](<P5490/%E3%80%90%E6%A8%A1%E6%9D%BF%E3%80%91%E6%89%AB%E6%8F%8F%E7%BA%BF%20%26%20%E7%9F%A9%E5%BD%A2%E9%9D%A2%E7%A7%AF%E5%B9%B6.cpp>) |
| [P3370 【模板】字符串哈希](https://www.luogu.com.cn/problem/P3370) | 字符串：字符串哈希去重 | [【模板】字符串哈希.cpp](<P3370/%E3%80%90%E6%A8%A1%E6%9D%BF%E3%80%91%E5%AD%97%E7%AC%A6%E4%B8%B2%E5%93%88%E5%B8%8C.cpp>) |
| [P3375 【模板】KMP](https://www.luogu.com.cn/problem/P3375) | 字符串：KMP | [P3375.cpp](<P3375/P3375.cpp>) · [【模板】KMP.cpp](<P3375/%E3%80%90%E6%A8%A1%E6%9D%BF%E3%80%91KMP.cpp>) |
| [P8306 【模板】字典树 / Trie](https://www.luogu.com.cn/problem/P8306) | 字符串：Trie 前缀计数 | [P8306.cpp](<P8306/P8306.cpp>) · [【模板】字典树.cpp](<P8306/%E3%80%90%E6%A8%A1%E6%9D%BF%E3%80%91%E5%AD%97%E5%85%B8%E6%A0%91.cpp>) |
| [P13270 【模板】最小表示法](https://www.luogu.com.cn/problem/P13270) | 字符串：最小表示法 | [P13270.cpp](<P13270/P13270.cpp>) |
| [P1495 【模板】中国剩余定理（CRT）/ 曹冲养猪](https://www.luogu.com.cn/problem/P1495) | 数学：中国剩余定理 CRT | [【模板】中国剩余定理（CRT） 曹冲养猪(new).cpp](<P1495/%E3%80%90%E6%A8%A1%E6%9D%BF%E3%80%91%E4%B8%AD%E5%9B%BD%E5%89%A9%E4%BD%99%E5%AE%9A%E7%90%86%EF%BC%88CRT%EF%BC%89%20%E6%9B%B9%E5%86%B2%E5%85%BB%E7%8C%AA%28new%29.cpp>) · [【模板】中国剩余定理（CRT） 曹冲养猪.cpp](<P1495/%E3%80%90%E6%A8%A1%E6%9D%BF%E3%80%91%E4%B8%AD%E5%9B%BD%E5%89%A9%E4%BD%99%E5%AE%9A%E7%90%86%EF%BC%88CRT%EF%BC%89%20%E6%9B%B9%E5%86%B2%E5%85%BB%E7%8C%AA.cpp>) |
| [P2197 【模板】Nim 游戏](https://www.luogu.com.cn/problem/P2197) | 数学：Nim 博弈 | [Nim 游戏.cpp](<P2197/Nim%20%E6%B8%B8%E6%88%8F.cpp>) |
| [P2252 【模板】威佐夫博弈 / [SHOI2002] 取石子游戏](https://www.luogu.com.cn/problem/P2252) | 数学：威佐夫博弈 | [取石子游戏【模板】威佐夫博弈.cpp](<P2252/%E5%8F%96%E7%9F%B3%E5%AD%90%E6%B8%B8%E6%88%8F%E3%80%90%E6%A8%A1%E6%9D%BF%E3%80%91%E5%A8%81%E4%BD%90%E5%A4%AB%E5%8D%9A%E5%BC%88.cpp>) |
| [P2613 【模板】有理数取余](https://www.luogu.com.cn/problem/P2613) | 数学：模意义下的除法 | [有理数取余.cpp](<P2613/%E6%9C%89%E7%90%86%E6%95%B0%E5%8F%96%E4%BD%99.cpp>) |
| [P3383 【模板】线性筛素数](https://www.luogu.com.cn/problem/P3383) | 数学：线性筛素数 | [【模板】线性筛素数.cpp](<P3383/%E3%80%90%E6%A8%A1%E6%9D%BF%E3%80%91%E7%BA%BF%E6%80%A7%E7%AD%9B%E7%B4%A0%E6%95%B0.cpp>) |
| [P3390 【模板】矩阵快速幂](https://www.luogu.com.cn/problem/P3390) | 数学：矩阵快速幂 | [【模板】矩阵快速幂.cpp](<P3390/%E3%80%90%E6%A8%A1%E6%9D%BF%E3%80%91%E7%9F%A9%E9%98%B5%E5%BF%AB%E9%80%9F%E5%B9%82.cpp>) |
| [P3807 【模板】卢卡斯定理 / Lucas 定理](https://www.luogu.com.cn/problem/P3807) | 数学：Lucas 定理 | [卢卡斯定理.cpp](<P3807/%E5%8D%A2%E5%8D%A1%E6%96%AF%E5%AE%9A%E7%90%86.cpp>) · [卢卡斯定理 Lucas 定理.cpp](<P3807/%E5%8D%A2%E5%8D%A1%E6%96%AF%E5%AE%9A%E7%90%86%20Lucas%20%E5%AE%9A%E7%90%86.cpp>) |
| [P3846 【模板】BSGS / [TJOI2007] 可爱的质数](https://www.luogu.com.cn/problem/P3846) | 数学：BSGS | [【模板】BSGS  [TJOI2007] 可爱的质数.cpp](<P3846/%E3%80%90%E6%A8%A1%E6%9D%BF%E3%80%91BSGS%20%20%5BTJOI2007%5D%20%E5%8F%AF%E7%88%B1%E7%9A%84%E8%B4%A8%E6%95%B0.cpp>) |
| [P4213 【模板】杜教筛](https://www.luogu.com.cn/problem/P4213) | 数学：杜教筛 | [杜教筛.cpp](<P4213/%E6%9D%9C%E6%95%99%E7%AD%9B.cpp>) |
| [P4549 【模板】裴蜀定理](https://www.luogu.com.cn/problem/P4549) | 数学：裴蜀定理 | [P4549.cpp](<P4549/P4549.cpp>) |
| [P4720 【模板】扩展卢卡斯定理 / exLucas](https://www.luogu.com.cn/problem/P4720) | 数学：exLucas | [【模板】扩展卢卡斯定理  exLucas.cpp](<P4720/%E3%80%90%E6%A8%A1%E6%9D%BF%E3%80%91%E6%89%A9%E5%B1%95%E5%8D%A2%E5%8D%A1%E6%96%AF%E5%AE%9A%E7%90%86%20%20exLucas.cpp>) |
| [P4777 【模板】扩展中国剩余定理（EXCRT）](https://www.luogu.com.cn/problem/P4777) | 数学：扩展 CRT | [【模板】扩展中国剩余定理（EXCRT）TJ版.cpp](<P4777/%E3%80%90%E6%A8%A1%E6%9D%BF%E3%80%91%E6%89%A9%E5%B1%95%E4%B8%AD%E5%9B%BD%E5%89%A9%E4%BD%99%E5%AE%9A%E7%90%86%EF%BC%88EXCRT%EF%BC%89TJ%E7%89%88.cpp>) · [【模板】扩展中国剩余定理（EXCRT）.cpp](<P4777/%E3%80%90%E6%A8%A1%E6%9D%BF%E3%80%91%E6%89%A9%E5%B1%95%E4%B8%AD%E5%9B%BD%E5%89%A9%E4%BD%99%E5%AE%9A%E7%90%86%EF%BC%88EXCRT%EF%BC%89.cpp>) |
| [P5091 【模板】扩展欧拉定理](https://www.luogu.com.cn/problem/P5091) | 数学：扩展欧拉定理 | [【模板】扩展欧拉定理.cpp](<P5091/%E3%80%90%E6%A8%A1%E6%9D%BF%E3%80%91%E6%89%A9%E5%B1%95%E6%AC%A7%E6%8B%89%E5%AE%9A%E7%90%86.cpp>) |
| [P5431 【模板】模意义下的乘法逆元 2](https://www.luogu.com.cn/problem/P5431) | 数学：批量求逆 | [【模板】模意义下的乘法逆元 2.cpp](<P5431/%E3%80%90%E6%A8%A1%E6%9D%BF%E3%80%91%E6%A8%A1%E6%84%8F%E4%B9%89%E4%B8%8B%E7%9A%84%E4%B9%98%E6%B3%95%E9%80%86%E5%85%83%202.cpp>) |
| [P5495 【模板】Dirichlet 前缀和](https://www.luogu.com.cn/problem/P5495) | 数学：Dirichlet 前缀和 | [【模板】Dirichlet 前缀和.cpp](<P5495/%E3%80%90%E6%A8%A1%E6%9D%BF%E3%80%91Dirichlet%20%E5%89%8D%E7%BC%80%E5%92%8C.cpp>) |
| [P5656 【模板】二元一次不定方程 (exgcd)](https://www.luogu.com.cn/problem/P5656) | 数学：exgcd 解二元一次不定方程 | [【模板】二元一次不定方程 (exgcd).cpp](<P5656/%E3%80%90%E6%A8%A1%E6%9D%BF%E3%80%91%E4%BA%8C%E5%85%83%E4%B8%80%E6%AC%A1%E4%B8%8D%E5%AE%9A%E6%96%B9%E7%A8%8B%20%28exgcd%29.cpp>) |
| [P1177 【模板】排序](https://www.luogu.com.cn/problem/P1177) | 基础与离线技巧：快速排序、归并排序 | [排序.cpp](<P1177/%E6%8E%92%E5%BA%8F.cpp>) · [排序_1.cpp](<P1177/%E6%8E%92%E5%BA%8F_1.cpp>) |
| [P3810 【模板】三维偏序 / 陌上花开](https://www.luogu.com.cn/problem/P3810) | 基础与离线技巧：CDQ 分治 + 树状数组 | [P3810.cpp](<P3810/P3810.cpp>) |

## 边界与待核对项目

只收录已能确认身份的源码；没有题号、题名或可辨认输入输出的草稿不作猜测归类。此目录是整理与复习索引，不代表每个历史版本已通过当前数据。

- `P1368/P1368.cpp`：当前标题为「工艺」，不以【模板】开头；新模板题是 P13270。
- `P3808/P3808.cpp`：当前标题为「AC 自动机（简单版）」，不以【模板】开头。
- `B3609/B3609.cpp`：当前标题为「[图论与代数结构 701] 强连通分量」，不以【模板】开头。
- `c++竞赛/Pollard-Rho.cpp`：虽然文件名相同，但实际代码读入 x,c,k，迭代 (x*x+c)%10000，不是 P4718 的质因数分解输入输出。
- `c++竞赛/中位数 [权值线段树模板].cpp`：本地“模板”字样不能证明洛谷题目标题以【模板】开头；未归入官方模板题。
- `c++竞赛/割边（桥）模板.cpp`：本地“模板”字样不能证明洛谷题目标题以【模板】开头；未归入官方模板题。

下列自建题页面返回 401，需要登录才能核实当前标题，因此保持原位置，不能据本次核对断言它们一定不是模板题：T520384、T521148、T634638、T778421、T831481、T832258。

## 迁移记录与核验

- [manifest.json](manifest.json)：每个文件的旧路径、新路径、SHA-256，以及未核实项目。
- [title_snapshot.json](title_snapshot.json)：核对当日的 199 个官方模板标题与来源。
- 逐文件验证迁移前后 SHA-256；所有其他源码保持原位与原内容。此次未修改算法，也未重新提交洛谷判题。
- P3372 包含两棵树状数组的实现；P3369 的 STL 版本实际为有序 vector，修改复杂度为 O(n)。不要仅凭文件名判断实现方式。
