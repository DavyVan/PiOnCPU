

//Binary exponentiation, (a ^ b) % mod
__int64 biexp(__int64 a, __int64 b, __int64 mod);

//Decimal --> Hex in char, 1 decimal digit convert to 2 hexadecimal characters
void DecToHexSingle(unsigned char dec, char * hex);

//Decimal --> Hex in char, convert all digits in a array
void DecToHexArray(unsigned char dec [], char hex [], int count);