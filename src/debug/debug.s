.globl main
main:
// 左辺と右辺をプッシュ
push 1
push 2

// 左辺と右辺をRAXとRDIにポップして足す
pop rdi
pop rax
add rax, rdi

// 足した結果をスタックにプッシュ
push rax
