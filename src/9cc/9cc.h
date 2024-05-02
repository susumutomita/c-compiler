#include <ctype.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Token and node kinds
typedef enum
{
  TK_RESERVED, // 記号
  TK_IDENT,    // 識別子
  TK_NUM,      // 整数トークン
  TK_EOF,      // 入力の終わりを表すトークン
} TokenKind;

typedef enum
{
  ND_ADD,   // +
  ND_SUB,   // -
  ND_MUL,   // *
  ND_DIV,   // /
  ND_EQ,    // ==
  ND_NE,    // !=
  ND_LT,    // <
  ND_LE,    // <=
  ND_NUM,   // Integer
  ND_LVAR,  // ローカル変数
  ND_ASSIGN // =
} NodeKind;

// AST node structure
typedef struct Node Node;
typedef struct Node
{
  NodeKind kind; // ノードの型
  Node *lhs;     // 左辺
  Node *rhs;     // 右辺
  int val;       // kindがND_NUMの場合のみ使う
  int offset;    // kindがND_LVARの場合のみ使う
} Node;

// Token structure
typedef struct Token Token; // 事前に Token 型を宣言
typedef struct Token
{
  TokenKind kind; // Token kind
  Token *next;    // Next token
  int val;        // If kind is TK_NUM, its value
  char *str;      // Token string
  int len;        // Token length
} Token;

// Function declarations
Token *tokenize();
void error(char *fmt, ...);
Node *expr(); // この関数が実際に必要な場合
void gen(Node *node);
bool consume(char *op);
Token *consume_ident();
Node *new_binary(NodeKind kind, Node *lhs, Node *rhs);
Node *new_num(int val);
void expect(char *op);
bool at_eof();
int expect_number();
void program();

// External variables
char *user_input;
Token *token;
extern Node *code[100];
