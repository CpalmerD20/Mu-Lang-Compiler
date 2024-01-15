#ifndef mu_scanner_h
#define mu_scanner_h

typedef enum {
  END_OF_FILE, TOKEN_ERROR,

  //SINGLE CHARACTER
  S_GRAVE, S_TILDE, S_BANG, S_AT, S_OCTO,    // ` ~ ! @ #
  S_MODULO, S_RAISE, S_AMPERSAND, S_STAR,    // % ^ & *
  S_LEFT_PARENTHESIS, S_RIGHT_PARENTHESIS,   // ( )
  S_MINUS, S_UNDERSCORE, S_PLUS, S_EQUAL,    // - _ + =
  S_LEFT_CURLYBRACE, S_RIGHT_CURLYBRACE,     // { }
  S_LEFT_SQUAREBRACE, S_RIGHT_SQUARE_BRACE,  // [ ]
  S_PIPE, S_BACKSLASH, S_COLON, S_SEMICOLON, // | \ : ; 
  S_QUOTE, S_APOSTROPHE, S_COMMA, S_DOT,     // " ' , .
  S_SLASH, S_LESS, S_GREATER, S_QUESTION,    // / < > ? 
  S_NEW_LINE,                                // \n

  //DOUBLE CHARACTER
  D_BANG_TILDE,  D_COMMA, D_STAR,             // !~ ,, **
  D_COLON, D_DOT, D_EQUAL, D_QUESTION,        // :: .. == ?? 
  D_DIAMOND, D_GREATER_EQUAL, D_LESS_EQUAL,   // <> >= <=
  D_RIGHT_ARROW, D_LEFT_ARROW,            // -> <-
  
  //LITERALS
  L_IDENTIFIER,
  L_STRING, L_ARRAY, L_TUPLE, L_RECORD,
  L_FLOAT,
  
  //KEYWORDS
  K_AND, K_AS, 
  // K_ALWAYS,
  K_BUILD,
  K_CALL,
  K_DEFINE, K_DELETE,
  K_ELSE, K_EACH, K_EXISTS, // K_END,
  K_FALSE, K_FROM,
  K_GENERATES, // K_GIVE,
  K_HOLD,
  K_IF, K_ITERATES, //K_IS,
  K_JOIN, 
  // k ...
  K_LIKE, // pattern matching when... like...
  // ... m
  K_NOT, // unsure if ! or not is better
  K_OR, 
  K_PRINT, K_PANIC,
  K_QUIT,
  K_RETURN, K_REDO, 
  K_SELF, K_SHARE, // K_SHIFT, K_SPECIFY, (could also be define)
  K_TRUE, K_TYPE,
  // K_TRY,
  K_UNLESS, K_UNTIL, // K_USE,
  K_VOID, // K_VIEW, // alternative to readonly
  K_WHEN, K_WHILE,
  K_XOR,
  K_YIELD,
} TokenType;

typedef struct {
  TokenType type;
  const char* start_;
  int length;
  int line;
} Token;

typedef struct {
  const char* start_;
  const char* current_;
  int line;
} Scanner;

void initScanner(const char* iSource);
Token scanToken();

#endif