# Git 日常开发流程指南

> 适用场景：个人写代码 / 小团队协作，从写代码到推送到远程仓库的完整流程。

---

## 一、开始前：仓库初始化（每个项目只做一次）

### 方式 A：从零开始一个新项目

```bash
# 1. 进入项目文件夹
cd /Users/jerry/code_cpp_hxr/P14636

# 2. 初始化为 Git 仓库
git init

# 3. 配置身份（全局只需配一次，之后所有项目通用）
git config --global user.name "你的名字"
git config --global user.email "你的邮箱@example.com"
```

### 方式 B：克隆已有项目

```bash
git clone <仓库地址>
# 例如
git clone https://github.com/用户名/仓库名.git
```

### 4. 建议：创建 .gitignore 文件

在项目根目录新建 `.gitignore`，告诉 Git 哪些文件不要跟踪（比如编译产物）：

```gitignore
# C++ 常见
*.o
*.out
*.exe
*.dSYM/

# 系统/编辑器
.DS_Store
.vscode/
.idea/

# 其他
build/
```

---

## 二、日常开发流程（每天循环使用）

这是核心流程，每次写代码都按这个循环走：

```bash
# ① 查看当前状态（随时看，养成习惯）
git status

# ② 把改动的文件加入暂存区
git add 文件名          # 添加指定文件
git add .               # 添加当前目录所有改动

# ③ 提交（生成一个"存档点"）
git commit -m "简短的说明，说明你改了什么"

# ④ 推送到远程仓库（GitHub 等）
git push
```

**一个完整的例子：**

```bash
# 你修改了 main.cpp 之后
git status                      # 看看改了哪些文件（红色 = 未暂存）
git add main.cpp                # 加入暂存区（变绿色）
git commit -m "修复了输入读取的bug"
git push                        # 上传到 GitHub
```

---

## 三、开始写新功能 / 修 bug 前：使用分支（好习惯）

在主分支 main 上直接改容易出问题，推荐在分支上开发：

```bash
# 1. 创建并切换到新分支
git switch -c feature-新功能名

# 2. 在这个分支上正常写代码、add、commit（流程同第二节）

# 3. 功能完成后，合并回主分支
git switch main               # 切回主分支
git merge feature-新功能名    # 合并
git push                      # 推送

# 4. 删除已完成的分支
git branch -d feature-新功能名
```

---

## 四、写代码前的同步（多人协作 / 多设备时必做）

```bash
git pull        # 拉取远程最新代码，再开始写
```

---

## 五、常见场景速查

### 提交前想看看自己改了什么

```bash
git diff                    # 查看未暂存的改动
git diff --staged           # 查看已暂存、待提交的改动
```

### 提交信息写错了 / 想追加修改到最后一次提交

```bash
git commit --amend
```

### 想撤销还没 add 的修改（小心，改不回来）

```bash
git restore 文件名
```

### 想撤销已经 add 但还没 commit 的

```bash
git restore --staged 文件名
```

### 想回到之前的某个版本（先找到版本号）

```bash
git log --oneline           # 查看历史，每行一个版本
git checkout 版本号          # 查看旧版本
git switch main             # 回到最新
```

### 暂存手头的工作，去处理别的事

```bash
git stash                   # 把未提交的改动收起来
# ……处理完别的事回来……
git stash pop               # 恢复刚才收起来的改动
```

### push 被拒绝（远程有你没有的新提交）

```bash
git pull --rebase           # 先拉取并整理你的提交
git push                    # 再推送
```

---

## 六、典型报错对照

| 报错信息 | 含义 | 解决 |
|---|---|---|
| `zsh: no such file or directory` | 把路径当命令敲了 | 用 `cd /完整路径` |
| `failed to push some refs` | 远程比你新 | 先 `git pull --rebase` 再 push |
| `Please tell me who you are` | 没配置用户名邮箱 | 执行 `git config --global user.name/email` |
| `src refspec main does not match` | 本地分支和远程没关联 | `git push -u origin main`（只需一次）|
| `fatal: not a git repository` | 不在 Git 仓库目录里 | `cd` 到项目根目录再操作 |

---

## 七、一张图记住全流程

```
写代码 → git status（看看改了啥）
       → git add .（加入暂存）
       → git commit -m "说明"（存一个档）
       → git push（上传 GitHub）

新功能：先 git switch -c 新分支 → 开发 → 合并回 main
开始前：先 git pull 保持最新
```

---

## 八、推荐的日常节奏

1. **开始写码前**：`git pull` 同步最新代码
2. **每完成一个小功能/修复**：`add` → `commit`（提交信息写清楚）
3. **当天收工前**：`git push` 推送到远程（代码上云，不怕丢）
4. **提交信息规范**：用动词开头，如 `修复 XX bug`、`添加 XX 功能`、`更新 XX 文档`

> 记住一句话：**先 pull，勤 commit，勤 push**。
