tape:
    .zero   120000
    .text
    .globl  main
    .type   main    @function
main:
    movl $0, %eax
    movl $0, %ebx

    movl tape(%eax), %ebx
    add $1, %ebx
    movl %ebx, tape(%eax)
    movl tape(%eax), %ebx
    add $1, %ebx
    movl %ebx, tape(%eax)
    movl tape(%eax), %ebx
    add $1, %ebx
    movl %ebx, tape(%eax)
    movl tape(%eax), %ebx
    add $1, %ebx
    movl %ebx, tape(%eax)
    movl tape(%eax), %ebx
    add $1, %ebx
    movl %ebx, tape(%eax)
    movl tape(%eax), %ebx
    add $1, %ebx
    movl %ebx, tape(%eax)
    movl tape(%eax), %ebx
    add $1, %ebx
    movl %ebx, tape(%eax)
    movl tape(%eax), %ebx
    add $1, %ebx
    movl %ebx, tape(%eax)
    movl tape(%eax), %ebx
    add $1, %ebx
    movl %ebx, tape(%eax)
    movl tape(%eax), %ebx
    add $1, %ebx
    movl %ebx, tape(%eax)
loop11:
    cmpl $0, eax
    je  cont11
    cmpl $30000, eax
    jl  equal12
    add $1, %eax
    jmp  cont12
equal12:  movl   $0,  %eax
cont12:
    movl tape(%eax), %ebx
    add $1, %ebx
    movl %ebx, tape(%eax)
    movl tape(%eax), %ebx
    add $1, %ebx
    movl %ebx, tape(%eax)
    movl tape(%eax), %ebx
    add $1, %ebx
    movl %ebx, tape(%eax)
    movl tape(%eax), %ebx
    add $1, %ebx
    movl %ebx, tape(%eax)
    movl tape(%eax), %ebx
    add $1, %ebx
    movl %ebx, tape(%eax)
    movl tape(%eax), %ebx
    add $1, %ebx
    movl %ebx, tape(%eax)
    movl tape(%eax), %ebx
    add $1, %ebx
    movl %ebx, tape(%eax)
    cmpl $30000, eax
    jl  equal20
    add $1, %eax
    jmp  cont20
equal20:  movl   $0,  %eax
cont20:
    movl tape(%eax), %ebx
    add $1, %ebx
    movl %ebx, tape(%eax)
    movl tape(%eax), %ebx
    add $1, %ebx
    movl %ebx, tape(%eax)
    movl tape(%eax), %ebx
    add $1, %ebx
    movl %ebx, tape(%eax)
    movl tape(%eax), %ebx
    add $1, %ebx
    movl %ebx, tape(%eax)
    movl tape(%eax), %ebx
    add $1, %ebx
    movl %ebx, tape(%eax)
    movl tape(%eax), %ebx
    add $1, %ebx
    movl %ebx, tape(%eax)
    movl tape(%eax), %ebx
    add $1, %ebx
    movl %ebx, tape(%eax)
    movl tape(%eax), %ebx
    add $1, %ebx
    movl %ebx, tape(%eax)
    movl tape(%eax), %ebx
    add $1, %ebx
    movl %ebx, tape(%eax)
    movl tape(%eax), %ebx
    add $1, %ebx
    movl %ebx, tape(%eax)
    cmpl $30000, eax
    jl  equal31
    add $1, %eax
    jmp  cont31
equal31:  movl   $0,  %eax
cont31:
    movl tape(%eax), %ebx
    add $1, %ebx
    movl %ebx, tape(%eax)
    movl tape(%eax), %ebx
    add $1, %ebx
    movl %ebx, tape(%eax)
    movl tape(%eax), %ebx
    add $1, %ebx
    movl %ebx, tape(%eax)
    cmpl $30000, eax
    jl  equal35
    add $1, %eax
    jmp  cont35
equal35:  movl   $0,  %eax
cont35:
    movl tape(%eax), %ebx
    add $1, %ebx
    movl %ebx, tape(%eax)
    cmpl $0, eax
    jb  equal37
    sub $1, %eax
    jmp  cont37
equal37:  movl   $30000, %eax
cont37:
    cmpl $0, eax
    jb  equal38
    sub $1, %eax
    jmp  cont38
equal38:  movl   $30000, %eax
cont38:
    cmpl $0, eax
    jb  equal39
    sub $1, %eax
    jmp  cont39
equal39:  movl   $30000, %eax
cont39:
    cmpl $0, eax
    jb  equal40
    sub $1, %eax
    jmp  cont40
equal40:  movl   $30000, %eax
cont40:
    movl tape(%eax), %ebx
    sub $1, %ebx
    movl %ebx, tape(%eax)
    jmp  loop11
cont11:
    cmpl $30000, eax
    jl  equal42
    add $1, %eax
    jmp  cont42
equal42:  movl   $0,  %eax
cont42:
    movl tape(%eax), %ebx
    add $1, %ebx
    movl %ebx, tape(%eax)
    movl tape(%eax), %ebx
    add $1, %ebx
    movl %ebx, tape(%eax)
    movl tape(%eax), %ebx
    leal %ebx
    cmpl $30000, eax
    jl  equal46
    add $1, %eax
    jmp  cont46
equal46:  movl   $0,  %eax
cont46:
    movl tape(%eax), %ebx
    add $1, %ebx
    movl %ebx, tape(%eax)
    movl tape(%eax), %ebx
    leal %ebx
    movl tape(%eax), %ebx
    add $1, %ebx
    movl %ebx, tape(%eax)
    movl tape(%eax), %ebx
    add $1, %ebx
    movl %ebx, tape(%eax)
    movl tape(%eax), %ebx
    add $1, %ebx
    movl %ebx, tape(%eax)
    movl tape(%eax), %ebx
    add $1, %ebx
    movl %ebx, tape(%eax)
    movl tape(%eax), %ebx
    add $1, %ebx
    movl %ebx, tape(%eax)
    movl tape(%eax), %ebx
    add $1, %ebx
    movl %ebx, tape(%eax)
    movl tape(%eax), %ebx
    add $1, %ebx
    movl %ebx, tape(%eax)
    movl tape(%eax), %ebx
    leal %ebx
    movl tape(%eax), %ebx
    leal %ebx
    movl tape(%eax), %ebx
    add $1, %ebx
    movl %ebx, tape(%eax)
    movl tape(%eax), %ebx
    add $1, %ebx
    movl %ebx, tape(%eax)
    movl tape(%eax), %ebx
    add $1, %ebx
    movl %ebx, tape(%eax)
    movl tape(%eax), %ebx
    leal %ebx
    cmpl $30000, eax
    jl  equal62
    add $1, %eax
    jmp  cont62
equal62:  movl   $0,  %eax
cont62:
    movl tape(%eax), %ebx
    add $1, %ebx
    movl %ebx, tape(%eax)
    movl tape(%eax), %ebx
    add $1, %ebx
    movl %ebx, tape(%eax)
    movl tape(%eax), %ebx
    leal %ebx
    cmpl $0, eax
    jb  equal66
    sub $1, %eax
    jmp  cont66
equal66:  movl   $30000, %eax
cont66:
    cmpl $0, eax
    jb  equal67
    sub $1, %eax
    jmp  cont67
equal67:  movl   $30000, %eax
cont67:
    movl tape(%eax), %ebx
    add $1, %ebx
    movl %ebx, tape(%eax)
    movl tape(%eax), %ebx
    add $1, %ebx
    movl %ebx, tape(%eax)
    movl tape(%eax), %ebx
    add $1, %ebx
    movl %ebx, tape(%eax)
    movl tape(%eax), %ebx
    add $1, %ebx
    movl %ebx, tape(%eax)
    movl tape(%eax), %ebx
    add $1, %ebx
    movl %ebx, tape(%eax)
    movl tape(%eax), %ebx
    add $1, %ebx
    movl %ebx, tape(%eax)
    movl tape(%eax), %ebx
    add $1, %ebx
    movl %ebx, tape(%eax)
    movl tape(%eax), %ebx
    add $1, %ebx
    movl %ebx, tape(%eax)
    movl tape(%eax), %ebx
    add $1, %ebx
    movl %ebx, tape(%eax)
    movl tape(%eax), %ebx
    add $1, %ebx
    movl %ebx, tape(%eax)
    movl tape(%eax), %ebx
    add $1, %ebx
    movl %ebx, tape(%eax)
    movl tape(%eax), %ebx
    add $1, %ebx
    movl %ebx, tape(%eax)
    movl tape(%eax), %ebx
    add $1, %ebx
    movl %ebx, tape(%eax)
    movl tape(%eax), %ebx
    add $1, %ebx
    movl %ebx, tape(%eax)
    movl tape(%eax), %ebx
    add $1, %ebx
    movl %ebx, tape(%eax)
    movl tape(%eax), %ebx
    leal %ebx
    cmpl $30000, eax
    jl  equal84
    add $1, %eax
    jmp  cont84
equal84:  movl   $0,  %eax
cont84:
    movl tape(%eax), %ebx
    leal %ebx
    movl tape(%eax), %ebx
    add $1, %ebx
    movl %ebx, tape(%eax)
    movl tape(%eax), %ebx
    add $1, %ebx
    movl %ebx, tape(%eax)
    movl tape(%eax), %ebx
    add $1, %ebx
    movl %ebx, tape(%eax)
    movl tape(%eax), %ebx
    leal %ebx
    movl tape(%eax), %ebx
    sub $1, %ebx
    movl %ebx, tape(%eax)
    movl tape(%eax), %ebx
    sub $1, %ebx
    movl %ebx, tape(%eax)
    movl tape(%eax), %ebx
    sub $1, %ebx
    movl %ebx, tape(%eax)
    movl tape(%eax), %ebx
    sub $1, %ebx
    movl %ebx, tape(%eax)
    movl tape(%eax), %ebx
    sub $1, %ebx
    movl %ebx, tape(%eax)
    movl tape(%eax), %ebx
    sub $1, %ebx
    movl %ebx, tape(%eax)
    movl tape(%eax), %ebx
    leal %ebx
    movl tape(%eax), %ebx
    sub $1, %ebx
    movl %ebx, tape(%eax)
    movl tape(%eax), %ebx
    sub $1, %ebx
    movl %ebx, tape(%eax)
    movl tape(%eax), %ebx
    sub $1, %ebx
    movl %ebx, tape(%eax)
    movl tape(%eax), %ebx
    sub $1, %ebx
    movl %ebx, tape(%eax)
    movl tape(%eax), %ebx
    sub $1, %ebx
    movl %ebx, tape(%eax)
    movl tape(%eax), %ebx
    sub $1, %ebx
    movl %ebx, tape(%eax)
    movl tape(%eax), %ebx
    sub $1, %ebx
    movl %ebx, tape(%eax)
    movl tape(%eax), %ebx
    sub $1, %ebx
    movl %ebx, tape(%eax)
    movl tape(%eax), %ebx
    leal %ebx
    cmpl $30000, eax
    jl  equal106
    add $1, %eax
    jmp  cont106
equal106:  movl   $0,  %eax
cont106:
    movl tape(%eax), %ebx
    add $1, %ebx
    movl %ebx, tape(%eax)
    movl tape(%eax), %ebx
    leal %ebx
    cmpl $30000, eax
    jl  equal109
    add $1, %eax
    jmp  cont109
equal109:  movl   $0,  %eax
cont109:
    movl tape(%eax), %ebx
    leal %ebx
    ret

