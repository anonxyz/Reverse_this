#ifndef HDR_LEVELXOR
    #define HDR_LEVELXOR
    #define SIZE 9
    union BYTE
    {
        unsigned char data;

        struct{
        unsigned char b0: 1;
        unsigned char b1: 1;
        unsigned char b2: 1;
        unsigned char b3: 1;
        unsigned char b4: 1;
        unsigned char b5: 1;
        unsigned char b6: 1;
        unsigned char b7: 1;
        } bits;

    };

    void decrypt(char const password[]);
    char xor_gate(char const a, char const b);
    char nand(char const a, char const b);
    char nor(char const a, char const b);
    char and_gate(char const a, char const b);
    char or_gate(char const a, char const b);
    char unmix_bits_val(char const byte);
    void unmix_string_nibbles(char * const input, char *output,
                           size_t const input_len, size_t const output_len );

#endif