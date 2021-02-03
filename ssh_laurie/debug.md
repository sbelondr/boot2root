
0xffffcdd8 -> ebp

push   %ebp
mov    %esp,%ebp
sub    $0x20,%esp -> 32

push   %esi
push   %ebx

mov    0x8(%ebp),%edx

add    $0xfffffff8,%esp
lea    -0x18(%ebp),%eax

push   %eax
push   %edx

call   0x8048fd8 <read_six_numbers>

add    $0x10,%esp

cmpl   $0x1,-0x18(%ebp)
je     0x8048b6e <phase_2+38>
call   0x80494fc <explode_bomb>

mov    $0x1,%ebx
lea    -0x18(%ebp),%esi
lea    0x1(%ebx),%eax
imul   -0x4(%esi,%ebx,4),%eax

cmp    %eax,(%esi,%ebx,4)
je     0x8048b88 <phase_2+64>
call   0x80494fc <explode_bomb>

inc    %ebx
cmp    $0x5,%ebx

jle    0x8048b76 <phase_2+46>
lea    -0x28(%ebp),%esp


pop    %ebx
pop    %esi
mov    %ebp,%esp
pop    %ebp
ret
