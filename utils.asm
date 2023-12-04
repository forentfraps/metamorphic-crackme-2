global GetRip
global AddrOffset
section .text
    GetRip:
        pop rax
        jmp rax

    AddrOffset:
        pop rcx
        add rcx, 1
        jmp rcx