#include "9cc.h"

int main(int argc, char **argv)
{
  if (argc != 2)
  {
    error("引数の個数が正しくありません");
    return 1;
  }

  // Tokenize and parse.
  user_input = argv[1];
  token = tokenize();
  Node *node = expr();
  program();

  // Print out the first half of assembly.
  printf(".intel_syntax noprefix\n");
  printf(".global main\n");
  printf("main:\n");

  // プロローグ
  // 変数26個分の領域を確保する
  printf("  push rbp\n");
  printf("  mov rbp, rsp\n");
  printf("  sub rsp, 208\n");

  // 先頭の式から順にコード生成
  for (int i = 0; code[i]; i++)
  {
    gen(code[i]);

    // 式の評価結果としてスタックに一つの値が残っている
    // はずなので、スタックが溢れないようにポップしておく
    printf("  pop rax\n");
  }

  // Traverse the AST to emit assembly.
  // gen(node);

  // A result must be at the top of the stack, so pop it
  // to RAX to make it a program exit code.
  printf("  mov rsp, rbp\n");
  printf("  pop rbp\n");
  printf("  ret\n");
  return 0;
}
