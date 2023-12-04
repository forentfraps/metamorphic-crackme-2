
void func(unsigned long long value, unsigned long long* ptr){
    unsigned short p1,p2,p3,p4;
    p1 = (unsigned short)((value >> 48) & 0xFFFF);
    *ptr = *ptr ^ 0x0101010101010101;
    p2 = (unsigned short)((value >> 32) & 0xFFFF);
    p3 = (unsigned short)((value >> 16) & 0xFFFF);
    p4 = (unsigned short)(value & 0xFFFF);
    if (((p1 ^ p2) * p2 * p1)% 0xffff == 0xdead && ((p3 ^ p4) * p3 * p4) % 0xffff == 0xbeef){
        *ptr = *ptr ^ 0x005b49450f0a1415;
    }
    return;
}