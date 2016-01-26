#ifndef HEX_2_B64
#define HEX_2_B64

// encodes the string input into base64
char* encode_hex(const char* input);

// decodes a 6bit int into the appropriate
// base64 index
char int_2_b64char(int group);

#endif
