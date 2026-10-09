#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
整理洛谷题目文件：按题号归类到对应文件夹
只处理根目录下的零散文件，不碰子目录中的内容
"""
import os
import re
import shutil
from pathlib import Path
from collections import defaultdict

WORK_DIR = Path(".")
# 题号正则：匹配 P 后跟数字（如 P1036, P11232, P16526）
PID_PATTERN = re.compile(r"(P\d+)", re.IGNORECASE)

def main():
    # 只收集根目录下的文件
    root_files = [p for p in WORK_DIR.iterdir() if p.is_file()]
    
    # 题号 -> 文件列表
    pid_files = defaultdict(list)
    unknown_files = []
    
    for fpath in root_files:
        fname = fpath.name
        # 跳过压缩包等
        if fname.lower().endswith(('.zip', '.rar', '.7z', '.tar', '.gz')):
            unknown_files.append(fpath)
            continue
        # 从文件名提取题号
        match = PID_PATTERN.search(fname)
        if match:
            pid = match.group(1).upper()
            pid_files[pid].append(fpath)
        else:
            unknown_files.append(fpath)
    
    print(f"根目录下共 {len(root_files)} 个文件")
    print(f"其中可识别洛谷题号的有 {sum(len(v) for v in pid_files.values())} 个文件，涉及 {len(pid_files)} 个题号")
    print(f"无法识别题号的有 {len(unknown_files)} 个文件（保持原位）")
    
    # 创建题号文件夹并移动文件
    moved_count = 0
    for pid, files in sorted(pid_files.items()):
        folder = WORK_DIR / pid
        folder.mkdir(exist_ok=True)
        for fpath in files:
            dest = folder / fpath.name
            # 处理同名冲突
            if dest.exists():
                stem = dest.stem
                suffix = dest.suffix
                for i in range(1, 1000):
                    dest = folder / f"{stem}_{i}{suffix}"
                    if not dest.exists():
                        break
            try:
                shutil.move(str(fpath), str(dest))
                moved_count += 1
            except Exception as e:
                print(f"  移动失败 {fpath} -> {dest}: {e}")
    
    print(f"\n已移动 {moved_count} 个文件到对应题号文件夹")
    
    # 输出统计
    print("\n=== 题号文件夹统计 ===")
    for pid in sorted(pid_files.keys()):
        folder = WORK_DIR / pid
        files_in_folder = list(folder.iterdir()) if folder.exists() else []
        print(f"  {pid}: {len(files_in_folder)} 个文件")
    
    if unknown_files:
        print(f"\n=== 未分类文件（保持原位） ===")
        for fpath in unknown_files:
            print(f"  {fpath.name}")

if __name__ == "__main__":
    main()
