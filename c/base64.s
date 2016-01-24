@
@ Create a function that converts a string passed in to the base64 encoded version of the string.
@

base64Table: .ascii "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz01234567890+/"

.text
.align 4
.code 32

.global base64_asm
@
@ void base64_asm(char *in, char* out) {};
@
@ r0 = *in
@ r1 = *out
@ r2 = i
@ r3 = temp
@
base64_asm:
    push    {r4-r7, lr}         @ Save registers for use as local variables (we only use through r7)
    mov     r2, #2              @ i = 2
    mov     r3, #0              @ temp = 0
loop:
    ldrb    r4, [r0]            @ r4 = the current byte
    tst     r4, #0xff           @ if ( r4 == 0 )
    beq     cleanup
    mov     r5, r2, LSL #3      @ r5 = i * 8
    mov     r5, r4, LSL r5      @ r5 = byte << (i * 8)
    orr     r3, r3, r5          @ r3 = temp | byte << (i * 8)
    sub     r2, r2, #1          @ i--
    cmp     r2, #0              @ not efficient to use -1 as constant, so use < 0
    bge     if_done             @ if ( i < 0 )
    mov     r2, #2              @   i = 2

    mov     r4, #0x3f
    ldr     r6, =base64Table    @ r6 = &base64Table

    lsr     r5, r3, #18
    and     r5, r5, r4          @ r5 = (temp >> 18) & 0x3f
    add     r5, r5, r6
    ldrb    r7, [r5]            @ r7 = base64Table[(temp >> 18) & 0x3f]
    strb    r7, [r1]
    add     r1, #1              @ out++

    lsr     r5, r3, #12
    and     r5, r5, r4          @ r5 = (temp >> 12) & 0x3f
    add     r5, r5, r6
    ldrb    r7, [r5]            @ r7 = base64Table[(temp >> 12) & 0x3f]
    strb    r7, [r1]
    add     r1, #1              @ out++

    lsr     r5, r3, #6
    and     r5, r5, r4          @ r5 = (temp >> 6) & 0x3f
    add     r5, r5, r6
    ldrb    r7, [r5]            @ r7 = base64Table[(temp >> 6) & 0x3f]
    strb    r7, [r1]
    add     r1, #1              @ out++

    and     r5, r3, r4          @ r5 = temp & 0x3f
    add     r5, r5, r6
    ldrb    r7, [r5]            @ r7 = base64Table[(temp) & 0x3f]
    strb    r7, [r1]
    add     r1, #1              @ out++

    mov     r3, #0
if_done:
    add     r0, r0, #1          @ in++
    b       loop
cleanup:

    mov     r4, #0x3f
    cmp     r2, #0
    bne     try_one

    lsr     r5, r3, #18
    and     r5, r5, r4          @ r5 = (temp >> 18) & 0x3f
    add     r5, r5, r6
    ldrb    r7, [r5]            @ r7 = base64Table[(temp >> 18) & 0x3f]
    strb    r7, [r1]
    add     r1, #1              @ out++

    lsr     r5, r3, #12
    and     r5, r5, r4          @ r5 = (temp >> 12) & 0x3f
    add     r5, r5, r6
    ldrb    r7, [r5]            @ r7 = base64Table[(temp >> 12) & 0x3f]
    strb    r7, [r1]
    add     r1, #1              @ out++

    lsr     r5, r3, #6
    and     r5, r5, r4          @ r5 = (temp >> 6) & 0x3f
    add     r5, r5, r6
    ldrb    r7, [r5]            @ r7 = base64Table[(temp >> 6) & 0x3f]
    strb    r7, [r1]
    add     r1, #1              @ out++

    mov     r7, #'='
    strb    r7, [r1]
    add     r1, #1              @ out++

try_one:
    cmp     r2, #1
    bne     done

    lsr     r5, r3, #18
    and     r5, r5, r4          @ r5 = (temp >> 18) & 0x3f
    add     r5, r5, r6
    ldrb    r7, [r5]            @ r7 = base64Table[(temp >> 18) & 0x3f]
    strb    r7, [r1]
    add     r1, #1              @ out++

    lsr     r5, r3, #12
    and     r5, r5, r4          @ r5 = (temp >> 12) & 0x3f
    add     r5, r5, r6
    ldrb    r7, [r5]            @ r7 = base64Table[(temp >> 12) & 0x3f]
    strb    r7, [r1]
    add     r1, #1              @ out++

    mov     r7, #'='
    strb    r7, [r1]
    add     r1, #1              @ out++
    strb    r7, [r1]
    add     r1, #1              @ out++

done:
    mov     r0, #0
    strb    r0, [r1]            @ null terminate the string
    pop     {r4-r7, pc}
