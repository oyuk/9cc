#include <ctype.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
  TK_RESERVED,
  TK_IDENT,
  TK_NUM,
  TK_RETURN,
  TK_EOF,  
} TokenKind;


typedef struct Token Token;
struct Token {
  TokenKind kind;
  Token *next;   
  int val;       
  char *str;
  int len;
};

typedef struct LVar LVar;

struct LVar {
  LVar *next;
  char *name;
  int len;
  int offset;
};

extern LVar *locals;

LVar *find_lvar(Token *tok);

void error(char *fmt, ...);
void error_at(char *loc, char *fmt, ...);
bool consume(char *op);
Token *consume_ident();
void expect(char *op);
int expect_number();
Token *expect_return();
bool at_eof();
Token *new_token(TokenKind kind, Token *cur, char *str, int len);
Token *tokenize();

extern char *user_input;
extern Token *token;

typedef enum {
  ND_ADD,
  ND_SUB,
  ND_MUL,
  ND_DIV,
  ND_NUM,
  ND_EQ,
  ND_NE,
  ND_LT,
  ND_LE,
  ND_ASSIGN,
  ND_LVAR,
  ND_RETURN,
} NodeKind;

typedef struct Node Node;
struct Node {
  NodeKind kind; 
  Node *lhs;     
  Node *rhs;     
  int val;
  int offset;
};

extern Node *code[100];

void program();

void gen(Node *node);
