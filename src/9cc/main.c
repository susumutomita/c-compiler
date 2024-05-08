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
  program();

  printf(".intel_syntax noprefix\n");
  printf(".global main\n");
  printf("main:\n");

  // 変数26個分の領域を確保する
  printf("  push rbp\n");
  printf("  mov rbp, rsp\n");
  printf("  sub rsp, 208\n");

  for (int i = 0; code[i]; i++)
  {
    fprintf(stderr, "code[%d]:\n", i);
    fprintf(stderr, "  kind: %d\n", code[i]->kind);
    if (code[i]->lhs)
    {
      fprintf(stderr, "  lhs: %p\n", (void *)code[i]->lhs);
    }
    if (code[i]->rhs)
    {
      fprintf(stderr, "  rhs: %p\n", (void *)code[i]->rhs);
    }
    if (code[i]->kind == ND_NUM)
    {
      fprintf(stderr, "  val: %d\n", code[i]->val);
    }
    gen(code[i]);
    printf("  pop rax\n");
  }
  printf("  mov rsp, rbp\n");
  printf("  pop rbp\n");
  printf("  ret\n");
  return 0;
}
