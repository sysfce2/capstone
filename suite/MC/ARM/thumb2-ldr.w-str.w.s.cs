# CS_ARCH_ARM, CS_MODE_THUMB, None
0x51,0xf8,0x04,0x3b = ldr r3, [r1], #4
0x51,0xf8,0x04,0x3b = ldr r3, [r1], #4
0x40,0xf8,0x04,0x3b = str r3, [r0], #4
0x40,0xf8,0x04,0x3b = str r3, [r0], #4
0x51,0xf8,0x04,0x3d = ldr r3, [r1, #-4]!
0x51,0xf8,0x04,0x3d = ldr r3, [r1, #-4]!
0x40,0xf8,0x04,0x3d = str r3, [r0, #-4]!
0x40,0xf8,0x04,0x3d = str r3, [r0, #-4]!
0x51,0xf8,0x04,0x0d = ldr r0, [r1, #-4]!
0x51,0xf8,0x04,0xdd = ldr sp, [r1, #-4]!
0x51,0xf8,0x04,0xfd = ldr pc, [r1, #-4]!
0x50,0xf8,0x04,0x1d = ldr r1, [r0, #-4]!
0x5d,0xf8,0x04,0x1d = ldr r1, [sp, #-4]!
0x50,0xf8,0xff,0x1f = ldr r1, [r0, #0xff]!
0x50,0xf8,0xff,0x1d = ldr r1, [r0, #-0xff]!
0x50,0xf8,0x00,0x1f = ldr r1, [r0, #0]!
0x08,0xbf = it eq
0x50,0xf8,0xff,0x1f = ldreq r1, [r0, #0xff]!
0xd8,0xbf = it le
0x50,0xf8,0xff,0x1f = ldrle r1, [r0, #0xff]!
0x51,0xf8,0x04,0x0b = ldr r0, [r1], #4
0x51,0xf8,0x04,0xdb = ldr sp, [r1], #4
0x51,0xf8,0x04,0xfb = ldr pc, [r1], #4
0x51,0xf8,0x04,0x0b = ldr r0, [r1], #4
0x5d,0xf8,0x04,0x0b = ldr r0, [sp], #4
0x5f,0xf8,0x04,0x0b = ldr.w	r0, [pc, #-0xb04]
0x51,0xf8,0xff,0x0b = ldr r0, [r1], #0xff
0x51,0xf8,0x00,0x0b = ldr r0, [r1], #0
0x51,0xf8,0xff,0x09 = ldr r0, [r1], #-0xff
0x08,0xbf = it eq
0x51,0xf8,0xff,0x0b = ldreq r0, [r1], #0xff
0xd8,0xbf = it le
0x51,0xf8,0xff,0x0b = ldrle r0, [r1], #0xff
0x40,0xf8,0x04,0x1d = str r1, [r0, #-4]!
0x40,0xf8,0x04,0xdd = str sp, [r0, #-4]!
0x42,0xf8,0x04,0x1d = str r1, [r2, #-4]!
0x4d,0xf8,0x04,0x1d = str r1, [sp, #-4]!
0x42,0xf8,0xff,0x1f = str r1, [r2, #0xff]!
0x42,0xf8,0x00,0x1f = str r1, [r2, #0]!
0x42,0xf8,0xff,0x1d = str r1, [r2, #-0xff]!
0x08,0xbf = it eq
0x42,0xf8,0xff,0x1f = streq r1, [r2, #0xff]!
0xd8,0xbf = it le
0x42,0xf8,0xff,0x1f = strle r1, [r2, #0xff]!
0x40,0xf8,0x04,0x1b = str r1, [r0], #4
0x40,0xf8,0x04,0xdb = str sp, [r0], #4
0x41,0xf8,0x04,0x0b = str r0, [r1], #4
0x4d,0xf8,0x04,0x0b = str r0, [sp], #4
0x40,0xf8,0xff,0x1b = str r1, [r0], #0xff
0x40,0xf8,0x00,0x1b = str r1, [r0], #0
0x40,0xf8,0xff,0x19 = str r1, [r0], #-0xff
0x08,0xbf = it eq
0x40,0xf8,0xff,0x1b = streq r1, [r0], #0xff
0xd8,0xbf = it le
0x40,0xf8,0xff,0x1b = strle r1, [r0], #0xff
