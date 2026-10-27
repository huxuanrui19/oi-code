# 洛谷模板题代码与题解索引

**48 道题、61 份 C++ 源码、48 篇 Obsidian 题解。** 更新：2026-10-27。

## 收录声明

保留 2026-10-24 确认的 44 道官方标题模板题；按用户指定，额外将 **P1368、B3609、P1168（指定中位数文件）、P1656（指定桥文件）** 视为个人模板。它们无需满足官方标题以 `【模板】` 开头。其他题目保持原位。

[在 Obsidian 打开题解总索引](obsidian://open?vault=Obsidian%20Vault&file=OI%2F07%20General%20Techniques%2FLuogu%20Template%20Problems)

[在本机打开总索引 Markdown](</Users/jerry/Documents/Obsidian Vault/OI/07 General Techniques/Luogu Template Problems.md>)

## 导航说明

下表的“目录与源码”使用简单的相对路径进入各题 README，再点击对应源码。每题 README 同时提供 Obsidian 题解入口与本机 Markdown 入口；文件名含空格、括号、方括号的源码链接使用合法 Markdown 路径。Obsidian 和本机链接需要这台电脑上的笔记库。

## 全部题目

| 题目 | 分类 / 算法 | 目录与源码 | 依据 |
| --- | --- | --- | --- |
| [B3609 \[图论与代数结构 701\] 强连通分量](https://www.luogu.com.cn/problem/B3609) | 图论：Tarjan 强连通分量 | [B3609 · 1 份源码](./B3609/README.md) | 个人指定 |
| [B3647 【模板】Floyd](https://www.luogu.com.cn/problem/B3647) | 图论：Floyd 全源最短路 | [B3647 · 1 份源码](./B3647/README.md) | 官方标题模板 |
| [P1656 炸铁路](https://www.luogu.com.cn/problem/P1656) | 图论：Tarjan 求桥 | [P1656 · 1 份源码](./P1656/README.md) | 个人指定 |
| [P3366 【模板】最小生成树](https://www.luogu.com.cn/problem/P3366) | 图论：Kruskal + 并查集 | [P3366 · 1 份源码](./P3366/README.md) | 官方标题模板 |
| [P3371 【模板】单源最短路径（弱化版）](https://www.luogu.com.cn/problem/P3371) | 图论：SPFA 单源最短路 | [P3371 · 1 份源码](./P3371/README.md) | 官方标题模板 |
| [P3379 【模板】最近公共祖先（LCA）](https://www.luogu.com.cn/problem/P3379) | 图论：树链剖分求 LCA | [P3379 · 1 份源码](./P3379/README.md) | 官方标题模板 |
| [P3384 【模板】重链剖分 / 树链剖分](https://www.luogu.com.cn/problem/P3384) | 图论：重链剖分 + 懒标记线段树 | [P3384 · 1 份源码](./P3384/README.md) | 官方标题模板 |
| [P3385 【模板】负环](https://www.luogu.com.cn/problem/P3385) | 图论：SPFA 判负环 | [P3385 · 1 份源码](./P3385/README.md) | 官方标题模板 |
| [P3386 【模板】二分图最大匹配](https://www.luogu.com.cn/problem/P3386) | 图论：增广路二分图匹配 | [P3386 · 1 份源码](./P3386/README.md) | 官方标题模板 |
| [P3387 【模板】缩点 / 强连通分量](https://www.luogu.com.cn/problem/P3387) | 图论：Tarjan SCC + DAG 最长路 | [P3387 · 2 份源码](./P3387/README.md) | 官方标题模板 |
| [P3388 【模板】割点](https://www.luogu.com.cn/problem/P3388) | 图论：Tarjan 割点 | [P3388 · 2 份源码](./P3388/README.md) | 官方标题模板 |
| [P4779 【模板】单源最短路径（标准版）](https://www.luogu.com.cn/problem/P4779) | 图论：堆优化 Dijkstra | [P4779 · 1 份源码](./P4779/README.md) | 官方标题模板 |
| [P7771 【模板】欧拉路径](https://www.luogu.com.cn/problem/P7771) | 图论：Hierholzer 有向图欧拉路径 | [P7771 · 1 份源码](./P7771/README.md) | 官方标题模板 |
| [P8435 【模板】点双连通分量](https://www.luogu.com.cn/problem/P8435) | 图论：Tarjan 点双连通分量 | [P8435 · 1 份源码](./P8435/README.md) | 官方标题模板 |
| [P8436 【模板】边双连通分量](https://www.luogu.com.cn/problem/P8436) | 图论：Tarjan 边双连通分量 | [P8436 · 2 份源码](./P8436/README.md) | 官方标题模板 |
| [P1168 中位数](https://www.luogu.com.cn/problem/P1168) | 数据结构：权值线段树求前缀中位数 | [P1168 · 1 份源码](./P1168/README.md) | 个人指定 |
| [P3367 【模板】并查集](https://www.luogu.com.cn/problem/P3367) | 数据结构：并查集 | [P3367 · 1 份源码](./P3367/README.md) | 官方标题模板 |
| [P3368 【模板】树状数组 2](https://www.luogu.com.cn/problem/P3368) | 数据结构：差分 + 树状数组 | [P3368 · 1 份源码](./P3368/README.md) | 官方标题模板 |
| [P3369 【模板】普通平衡树](https://www.luogu.com.cn/problem/P3369) | 数据结构：普通平衡树：Treap / 替罪羊树 / vector | [P3369 · 3 份源码](./P3369/README.md) | 官方标题模板 |
| [P3372 【模板】线段树 1](https://www.luogu.com.cn/problem/P3372) | 数据结构：区间加、区间和：双树状数组 / 线段树 | [P3372 · 3 份源码](./P3372/README.md) | 官方标题模板 |
| [P3373 【模板】线段树 2](https://www.luogu.com.cn/problem/P3373) | 数据结构：带乘法与加法标记的线段树 | [P3373 · 1 份源码](./P3373/README.md) | 官方标题模板 |
| [P3374 【模板】树状数组 1](https://www.luogu.com.cn/problem/P3374) | 数据结构：树状数组单点加、区间和 | [P3374 · 1 份源码](./P3374/README.md) | 官方标题模板 |
| [P3378 【模板】堆](https://www.luogu.com.cn/problem/P3378) | 数据结构：priority_queue 小根堆 | [P3378 · 1 份源码](./P3378/README.md) | 官方标题模板 |
| [P3865 【模板】ST 表 & RMQ 问题](https://www.luogu.com.cn/problem/P3865) | 数据结构：Sparse Table 静态区间最大值 | [P3865 · 1 份源码](./P3865/README.md) | 官方标题模板 |
| [P5490 【模板】扫描线 & 矩形面积并](https://www.luogu.com.cn/problem/P5490) | 数据结构：扫描线 + 覆盖长度线段树 | [P5490 · 1 份源码](./P5490/README.md) | 官方标题模板 |
| [P1368 工艺](https://www.luogu.com.cn/problem/P1368) | 字符串：整数序列最小表示法 | [P1368 · 1 份源码](./P1368/README.md) | 个人指定 |
| [P3370 【模板】字符串哈希](https://www.luogu.com.cn/problem/P3370) | 字符串：字符串哈希去重 | [P3370 · 1 份源码](./P3370/README.md) | 官方标题模板 |
| [P3375 【模板】KMP](https://www.luogu.com.cn/problem/P3375) | 字符串：KMP | [P3375 · 2 份源码](./P3375/README.md) | 官方标题模板 |
| [P8306 【模板】字典树 / Trie](https://www.luogu.com.cn/problem/P8306) | 字符串：Trie 前缀计数 | [P8306 · 2 份源码](./P8306/README.md) | 官方标题模板 |
| [P13270 【模板】最小表示法](https://www.luogu.com.cn/problem/P13270) | 字符串：最小表示法 | [P13270 · 1 份源码](./P13270/README.md) | 官方标题模板 |
| [P1495 【模板】中国剩余定理（CRT）/ 曹冲养猪](https://www.luogu.com.cn/problem/P1495) | 数学：中国剩余定理 CRT | [P1495 · 2 份源码](./P1495/README.md) | 官方标题模板 |
| [P2197 【模板】Nim 游戏](https://www.luogu.com.cn/problem/P2197) | 数学：Nim 博弈 | [P2197 · 1 份源码](./P2197/README.md) | 官方标题模板 |
| [P2252 【模板】威佐夫博弈 / \[SHOI2002\] 取石子游戏](https://www.luogu.com.cn/problem/P2252) | 数学：威佐夫博弈 | [P2252 · 1 份源码](./P2252/README.md) | 官方标题模板 |
| [P2613 【模板】有理数取余](https://www.luogu.com.cn/problem/P2613) | 数学：模意义下的除法 | [P2613 · 1 份源码](./P2613/README.md) | 官方标题模板 |
| [P3383 【模板】线性筛素数](https://www.luogu.com.cn/problem/P3383) | 数学：线性筛素数 | [P3383 · 1 份源码](./P3383/README.md) | 官方标题模板 |
| [P3390 【模板】矩阵快速幂](https://www.luogu.com.cn/problem/P3390) | 数学：矩阵快速幂 | [P3390 · 1 份源码](./P3390/README.md) | 官方标题模板 |
| [P3807 【模板】卢卡斯定理 / Lucas 定理](https://www.luogu.com.cn/problem/P3807) | 数学：Lucas 定理 | [P3807 · 2 份源码](./P3807/README.md) | 官方标题模板 |
| [P3846 【模板】BSGS / \[TJOI2007\] 可爱的质数](https://www.luogu.com.cn/problem/P3846) | 数学：BSGS | [P3846 · 1 份源码](./P3846/README.md) | 官方标题模板 |
| [P4213 【模板】杜教筛](https://www.luogu.com.cn/problem/P4213) | 数学：杜教筛 | [P4213 · 1 份源码](./P4213/README.md) | 官方标题模板 |
| [P4549 【模板】裴蜀定理](https://www.luogu.com.cn/problem/P4549) | 数学：裴蜀定理 | [P4549 · 1 份源码](./P4549/README.md) | 官方标题模板 |
| [P4720 【模板】扩展卢卡斯定理 / exLucas](https://www.luogu.com.cn/problem/P4720) | 数学：exLucas | [P4720 · 1 份源码](./P4720/README.md) | 官方标题模板 |
| [P4777 【模板】扩展中国剩余定理（EXCRT）](https://www.luogu.com.cn/problem/P4777) | 数学：扩展 CRT | [P4777 · 2 份源码](./P4777/README.md) | 官方标题模板 |
| [P5091 【模板】扩展欧拉定理](https://www.luogu.com.cn/problem/P5091) | 数学：扩展欧拉定理 | [P5091 · 1 份源码](./P5091/README.md) | 官方标题模板 |
| [P5431 【模板】模意义下的乘法逆元 2](https://www.luogu.com.cn/problem/P5431) | 数学：批量求逆 | [P5431 · 1 份源码](./P5431/README.md) | 官方标题模板 |
| [P5495 【模板】Dirichlet 前缀和](https://www.luogu.com.cn/problem/P5495) | 数学：Dirichlet 前缀和 | [P5495 · 1 份源码](./P5495/README.md) | 官方标题模板 |
| [P5656 【模板】二元一次不定方程 (exgcd)](https://www.luogu.com.cn/problem/P5656) | 数学：exgcd 解二元一次不定方程 | [P5656 · 1 份源码](./P5656/README.md) | 官方标题模板 |
| [P1177 【模板】排序](https://www.luogu.com.cn/problem/P1177) | 基础与离线技巧：快速排序、归并排序 | [P1177 · 2 份源码](./P1177/README.md) | 官方标题模板 |
| [P3810 【模板】三维偏序 / 陌上花开](https://www.luogu.com.cn/problem/P3810) | 基础与离线技巧：CDQ 分治 + 树状数组 | [P3810 · 1 份源码](./P3810/README.md) | 官方标题模板 |

## 其他题目

P3808、未确认的 T 类题目及其他未指定文件保持原处。P1656 这里只包含此次指定的 `割边（桥）模板.cpp`，其他同题代码不移动。

## 记录与源码状态

- [迁移记录](./manifest.json)：旧路径、新路径、SHA-256、个人模板声明和题解路径。
- [原始官方标题快照](./title_snapshot.json)：保留 2026-10-24 的核对记录，不把个人声明伪装成官方标题。
- 所有 C++ 源码内容保持不变；BSGS、矩阵快速幂等历史实现的具体限制见对应题解。
