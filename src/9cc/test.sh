#!/bin/bash
assert() {
  expected="$1"
  input="$2"

  ./9cc "$input" > tmp.s
  cc -o tmp tmp.s
  ./tmp
  actual="$?"

  if [ "$actual" = "$expected" ]; then
    echo "$input => $actual"
  else
    echo "$input => $expected expected, but got $actual"
    exit 1
  fi
}

assert 0 "0;"
assert 42 "42;"
assert 47 "5+6*7;"
assert 21 "5+20-4;"
assert 23 "5+20+1-4 +1;"
assert 41 " 12 + 34 - 5 ;"
assert 15 "5*(9-6);"
assert 4 "(3+5)/2;"
assert 2 "-3+5;"
assert 0 "-3==5;"
assert 1 "1==1;"
assert 0 "1!=1;"
assert 1 "-3!=5;"
assert 1 "a = 1;"  # 単純な変数代入と参照
# assert 14 "a = 3; b = 5; a * b - 1"  # 複数の変数を使った計算
# assert 1 "a = 3; b = 3; a == b"  # 等価演算子
# assert 0 "a = 5; b = 3; a == b"  # 等価演算子（不一致）
# assert 1 "a = 5; b = 3; a != b"  # 不等演算子
# assert 1 "a = 2; b = 3; a < b"   # 小なり演算子
# assert 0 "a = 5; a < 5"          # 小なり演算子（境界値）
# assert 1 "a = 5; a <= 5"         # 小なり等価演算子（境界値）
# assert 1 "a = 5; b = 5; a >= b"  # 大なり等価演算子
# assert 0 "a = 3; b = 5; a >= b"  # 大なり等価演算子（不一致）
# assert 0 "a = 3; b = 5; a > b"   # 大なり演算子
# assert 1 "a = 6; b = 5; a > b"   # 大なり演算子（一致）
# assert 15 "a = 5; b = 3; a * b"  # 乗算テスト
# assert 2 "a = 6; b = 3; a / b"   # 除算テスト
echo OK
