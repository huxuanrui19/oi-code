#!/bin/bash
set -eu

cd "$(dirname "$0")"
shopt -s nullglob
cases=(../*评测数据/序列修缮/*.in)
if (( ${#cases[@]} == 0 )); then
    echo "No T2 judge inputs found." >&2
    exit 1
fi

compiler=${CXX:-}
if [[ -z $compiler ]]; then
    for version in {20..10}; do
        if command -v "g++-$version" >/dev/null; then
            compiler="g++-$version"
            break
        fi
    done
    compiler=${compiler:-g++}
fi

work=$(mktemp -d)
trap 'rm -rf "$work"' EXIT
"$compiler" -std=c++14 -O2 repair.cpp -o "$work/repair"

passed=0
for input in "${cases[@]}"; do
    id=$(basename "$input" .in)
    answer="${input%.in}.ans"
    if [[ ! -f $answer ]]; then
        echo "$id  MISSING ANSWER"
    elif ! "$work/repair" < "$input" > "$work/output"; then
        echo "$id  RUNTIME ERROR"
    else
        expected=$(awk '{for(i=1;i<=NF;i++) print $i}' "$answer" | tr -d '\r')
        actual=$(awk '{for(i=1;i<=NF;i++) print $i}' "$work/output" | tr -d '\r')
        if [[ $actual == "$expected" ]]; then
            echo "$id  PASS"
            passed=$((passed + 1))
        else
            echo "$id  FAIL  expected $expected, got ${actual:-<empty>}"
        fi
    fi
done

echo "$passed/${#cases[@]} passed"
(( passed == ${#cases[@]} ))
