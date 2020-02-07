mov al, a ;AL := a
cbw
mov BX, AX;BX := a
mov al, b;HL := b
cbw;AX := b
add AX, BX; AX := a + b
idiv c
mov ax, 4c00h
int 21h
end
