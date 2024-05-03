.intel_syntax noprefix
.globl main
main:
    push rbp            # 呼び出し元のベースポインタを保存
    mov rbp, rsp        # 現在のスタックポインタをベースポインタに設定

    # ここで関数の本体を実行
    mov rax, 1          # raxに1をセット（通常、関数の戻り値をraxにセット）

    mov rsp, rbp        # スタックポインタを元に戻す
    pop rbp             # ベースポインタを復元
    ret                 # 呼び出し元にリターン
