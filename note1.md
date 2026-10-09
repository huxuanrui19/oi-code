# VS Code + CMD 常用速查表

---

## 一、VS Code 快捷键

### 核心操作

| 快捷键 | 功能 | OI 场景 |
|--------|------|---------|
| `Ctrl+Shift+P` | 命令面板 | 搜索任何命令 |
| `Ctrl+Shift+B` | 运行默认编译任务 | 一键编译当前 cpp |
| `F5` | 启动调试 | 断点调试程序 |
| `Shift+F5` | 停止调试 | 退出调试模式 |
| `F10` | 单步跳过（Step Over） | 调试时不进入函数内部 |
| `F11` | 单步进入（Step Into） | 调试时进入函数内部 |
| `Shift+F11` | 单步跳出（Step Out） | 从当前函数跳出 |
| `Ctrl+`` ` | 显示/隐藏终端 | 快速查看编译/运行结果 |
| `Ctrl+K Ctrl+S` | 打开快捷键设置 | 修改冲突快捷键 |

### 编辑与导航

| 快捷键 | 功能 |
|--------|------|
| `Ctrl+N` | 新建文件 |
| `Ctrl+S` | 保存文件 |
| `Ctrl+Z` | 撤销 |
| `Ctrl+Shift+Z` | 重做 |
| `Ctrl+F` | 当前文件查找 |
| `Ctrl+H` | 当前文件替换 |
| `Ctrl+G` | 跳转到指定行号 |
| `Alt+↑ / Alt+↓` | 当前行上移/下移 |
| `Ctrl+/` | 注释/取消注释当前行 |
| `Ctrl+D` | 选中当前单词，再次按选中下一个相同单词 |
| `Ctrl+Shift+L` | 选中所有相同单词 |
| `Home / End` | 跳到行首 / 行尾 |
| `Ctrl+Home / Ctrl+End` | 跳到文件开头 / 结尾 |

### CPH（Competitive Programming Helper）

| 快捷键 | 功能 |
|--------|------|
| `Ctrl+Alt+B` | 运行当前测试用例 |
| `Ctrl+Alt+T` | 添加新测试用例 |

&gt; 如果 `Ctrl+Alt+B` 冲突，可在 `Ctrl+K Ctrl+S` 中搜索 `cph: Run Testcases` 修改。

---

## 二、OI 代码片段

在 `.cpp` 文件中输入前缀，按 `Tab` 展开：

| 前缀 | 效果 |
|------|------|
| `oi` | 展开万能头模板（已配置） |

---

## 三、CMD 常用命令

### 文件与目录

| 命令 | 功能 | 示例 |
|------|------|------|
| `cd 目录名` | 进入目录 | `cd OI` |
| `cd ..` | 返回上级目录 | — |
| `cd \` | 返回根目录 | — |
| `dir` | 列出当前目录文件 | — |
| `cls` | 清屏 | — |
| `mkdir 文件夹名` | 创建文件夹 | `mkdir p1001` |
| `rmdir 文件夹名` | 删除空文件夹 | — |
| `del 文件名` | 删除文件 | `del a.exe` |
| `copy 源文件 目标文件` | 复制文件 | `copy a.cpp b.cpp` |
| `move 源文件 目标路径` | 移动文件 | `move a.cpp D:\OI\` |
| `type 文件名` | 显示文件内容 | `type in.txt` |

### 路径相关

| 命令 | 功能 |
|------|------|
| `D:` | 切换到 D 盘 |
| `C:` | 切换到 C 盘 |
| `cd /d D:\OI` | 跨盘符切换目录 |

### 程序运行

| 命令 | 功能 | 示例 |
|------|------|------|
| `文件名.exe` | 运行程序 | `test.exe` 或 `.\test.exe` |
| `文件名.exe &lt; in.txt` | 从文件读入运行 | `a.exe &lt; in.txt` |
| `文件名.exe &gt; out.txt` | 输出重定向到文件 | `a.exe &gt; out.txt` |
| `文件名.exe &lt; in.txt &gt; out.txt` | 同时重定向输入输出 | — |

---

## 四、g++ 编译命令

### 基础编译

| 命令 | 说明 |
|------|------|
| `g++ a.cpp -o a.exe` | 编译 a.cpp，输出 a.exe |
| `g++ a.cpp -o a.exe -std=c++17` | 指定 C++17 标准 |
| `.\a.exe` | 运行生成的程序 |

### OI 常用编译参数

| 参数 | 全称 | 作用 |
|------|------|------|
| `-std=c++17` | — | 使用 C++17 标准 |
| `-O2` | Optimize level 2 | 开启二级优化（比赛标配） |
| `-O3` | Optimize level 3 | 三级优化（可能不稳定，OI 一般不用） |
| `-Wall` | All Warnings | 显示所有常见警告 |
| `-Wextra` | Extra Warnings | 显示额外警告 |
| `-Wshadow` | Shadow Warnings | 变量遮蔽警告 |
| `-g` | Debug | 保留调试信息（配合 GDB） |
| `-static` | — | 静态链接（某些 OJ 需要） |

### 组合示例

```cmd
:: OI 标准编译（推荐）
g++ main.cpp -o main.exe -std=c++17 -O2 -Wall -Wextra -Wshadow -g

:: 静态编译（某些比赛需要）
g++ main.cpp -o main.exe -std=c++17 -O2 -static