# CS_ARCH_AARCH64, 0, None

0xe5,0x40,0xd4,0x1a == crc32b   w5, w7, w20
0xfc,0x47,0xde,0x1a == crc32h   w28, wzr, w30
0x20,0x48,0xc2,0x1a == crc32w   w0, w1, w2
0x27,0x4d,0xd4,0x9a == crc32x   w7, w9, x20
0xa9,0x50,0xc4,0x1a == crc32cb  w9, w5, w4
0x2d,0x56,0xd9,0x1a == crc32ch  w13, w17, w25
0x7f,0x58,0xc5,0x1a == crc32cw  wzr, w3, w5
0x12,0x5e,0xdf,0x9a == crc32cx  w18, w16, xzr
