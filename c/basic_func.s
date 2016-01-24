
.text
.align 4
.code 32

@
@ int test_func(int x)
@
.global test_func
test_func:
    add     r0, r0, #6      @ Return x + 6
    mov     pc, lr


@
@ int nested_call(int val)
@
.global nested_call
nested_call:
    push    {lr}
    add     r0, r0, #1      @ Call test_func( var + 1 )
    pop     {pc}

