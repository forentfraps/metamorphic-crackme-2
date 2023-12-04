nasm -f win64 utils.asm -o utils.o
nasm -f win64 aes_home/fast.asm -o fast.o
gcc funcs.c -c -nostdlib -ffreestanding -static
python ./parser_x86.py
gcc main.c aes_home/aes.c fast.o utils.o -o main.exe -w -Ofast -static -ffreestanding -s