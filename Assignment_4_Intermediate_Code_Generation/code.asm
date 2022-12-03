.MODEL SMALL
.STACK 100H
.DATA
NUMBER_STRING DB '00000$'
  k1_1 DW 0
	t0 DW 0
	t1 DW 0
	t2 DW 0
	t3 DW 0
	t4 DW 0
	t5 DW 0
	t6 DW 0
	t7 DW 0
	t8 DW 0
  x1_2 DW 0
  i1_2 DW 0
	t9 DW 0
	t10 DW 0
	t11 DW 0
	t12 DW 0
	t13 DW 0
	t14 DW 0
	t15 DW 0
	t16 DW 0
	t17 DW 0
	t18 DW 0
	t19 DW 0
	t20 DW 0
	t21 DW 0
	t22 DW 0
	t23 DW 0
	t24 DW 0
  a1_3 DW 0
  b1_3 DW 0
  i1_3 DW 0
	t25 DW 0
	t26 DW 0
	t27 DW 0
	t28 DW 0
	t29 DW 0
	t30 DW 0
	t31 DW 0
	t32 DW 0
	t33 DW 0
	t34 DW 0
	t35 DW 0
	t36 DW 0
	t37 DW 0
	t38 DW 0
	t39 DW 0
.CODE

f_PROCEDURE PROC
PUSH BP
MOV BP, SP

;5
MOV AX, 5
MOV t0, AX

;k=5
MOV AX, t0
MOV k1_1, AX
L0:

;k
MOV AX, k1_1
MOV t1, AX

;0
MOV AX, 0
MOV t2, AX

;k>0

MOV AX, t1
MOV BX, t2
CMP AX, BX
jg L1
MOV t1, 0
jmp L2
L1:
	MOV t1, 1
L2:
CMP t1, 0
JE L3

;a++

MOV AX, [BP+ 4]
MOV t3,AX
INC [BP+ 4]

;k--

MOV AX, k1_1
MOV t4, AX
DEC k1_1
JMP L0
L3:

;3
MOV AX, 3
MOV t5, AX

;a
MOV AX, [BP+4]
MOV t6, AX

;3*a
MOV AX, t5
MOV BX, t6
MUL BX
MOV t5, AX

;7
MOV AX, 7
MOV t7, AX

;3-7

MOV AX, t5
SUB AX, t7
MOV t5, AX

;return 3

MOV CX, t5
JMP L4

;9
MOV AX, 9
MOV t8, AX

;a=9
MOV AX, t8
MOV [BP+4], AX
L4: 

POP BP
RET 2

g_PROCEDURE PROC
PUSH BP
MOV BP, SP

;a
MOV AX, [BP+6]
MOV t9, AX
PUSH t9

;f(a)
CALL f_PROCEDURE
MOV t10, CX

;a
MOV AX, [BP+6]
MOV t11, AX

;f+a

MOV AX, t10
ADD AX, t11
MOV t10, AX

;b
MOV AX, [BP+4]
MOV t12, AX

;f+b

MOV AX, t10
ADD AX, t12
MOV t10, AX

;x=f
MOV AX, t10
MOV x1_2, AX

;0
MOV AX, 0
MOV t13, AX

;i=0
MOV AX, t13
MOV i1_2, AX
L5:

;i
MOV AX, i1_2
MOV t14, AX

;7
MOV AX, 7
MOV t15, AX

;i<7

MOV AX, t14
MOV BX, t15
CMP AX, BX
jl L6
MOV t14, 0
jmp L7
L6:
	MOV t14, 1
L7:
CMP t14, 0
JE L8
	JMP L9
L10:

;i++

MOV AX, i1_2
MOV t16, AX
INC i1_2
JMP L5
L9:

;i
MOV AX, i1_2
MOV t17, AX

;3
MOV AX, 3
MOV t18, AX

;i%3
MOV AX, t17
MOV BX, t18
XOR DX, DX
DIV BX
MOV t17, DX

;0
MOV AX, 0
MOV t19, AX

;i==0

MOV AX, t17
MOV BX, t19
CMP AX, BX
je L11
MOV t17, 0
jmp L12
L11:
	MOV t17, 1
L12:
CMP t17, 0
JE L13

;x
MOV AX, x1_2
MOV t20, AX

;5
MOV AX, 5
MOV t21, AX

;x+5

MOV AX, t20
ADD AX, t21
MOV t20, AX

;x=x
MOV AX, t20
MOV x1_2, AX
JMP L14
L13:

;x
MOV AX, x1_2
MOV t22, AX

;1
MOV AX, 1
MOV t23, AX

;x-1

MOV AX, t22
SUB AX, t23
MOV t22, AX

;x=x
MOV AX, t22
MOV x1_2, AX
L14:
JMP L10
L8:

;x
MOV AX, x1_2
MOV t24, AX

;return x

MOV CX, t24
JMP L15
L15: 

POP BP
RET 4

MAIN PROC
MOV AX, @DATA
MOV DS, AX

;1
MOV AX, 1
MOV t25, AX

;a=1
MOV AX, t25
MOV a1_3, AX

;2
MOV AX, 2
MOV t26, AX

;b=2
MOV AX, t26
MOV b1_3, AX

;a
MOV AX, a1_3
MOV t27, AX
PUSH t27

;b
MOV AX, b1_3
MOV t28, AX
PUSH t28

;g(a,b)
CALL g_PROCEDURE
MOV t29, CX

;a=g
MOV AX, t29
MOV a1_3, AX

;println(a)
MOV AX, a1_3
CALL println

;printing new line
mov ah,2
mov dl,10
int 21h
mov dl,13
int 21h

;0
MOV AX, 0
MOV t30, AX

;i=0
MOV AX, t30
MOV i1_3, AX
L16:

;i
MOV AX, i1_3
MOV t31, AX

;4
MOV AX, 4
MOV t32, AX

;i<4

MOV AX, t31
MOV BX, t32
CMP AX, BX
jl L17
MOV t31, 0
jmp L18
L17:
	MOV t31, 1
L18:
CMP t31, 0
JE L19
	JMP L20
L21:

;i++

MOV AX, i1_3
MOV t33, AX
INC i1_3
JMP L16
L20:

;3
MOV AX, 3
MOV t34, AX

;a=3
MOV AX, t34
MOV a1_3, AX
L22:

;a
MOV AX, a1_3
MOV t35, AX

;0
MOV AX, 0
MOV t36, AX

;a>0

MOV AX, t35
MOV BX, t36
CMP AX, BX
jg L23
MOV t35, 0
jmp L24
L23:
	MOV t35, 1
L24:
CMP t35, 0
JE L25

;b++

MOV AX, b1_3
MOV t37, AX
INC b1_3

;a--

MOV AX, a1_3
MOV t38, AX
DEC a1_3
JMP L22
L25:
JMP L21
L19:

;println(a)
MOV AX, a1_3
CALL println

;printing new line
mov ah,2
mov dl,10
int 21h
mov dl,13
int 21h

;println(b)
MOV AX, b1_3
CALL println

;printing new line
mov ah,2
mov dl,10
int 21h
mov dl,13
int 21h

;println(i)
MOV AX, i1_3
CALL println

;printing new line
mov ah,2
mov dl,10
int 21h
mov dl,13
int 21h

;0
MOV AX, 0
MOV t39, AX

;return 0

MOV CX, t39
JMP L26
L26: 

MOV AH, 4CH
INT 21H
main ENDP
println proc
	LEA SI, NUMBER_STRING
	ADD SI, 5
	CMP AX, 0
	JNGE NEG_AX
	PRINT_LOOP:
	DEC SI
	MOV DX, 0
	; DX:AX = 0000:AX
	MOV BX, 10
	DIV BX
	ADD DL, '0'
	MOV [SI], DL
	CMP AX, 0
	JNE PRINT_LOOP
	MOV DX, SI
	MOV AH, 9
	INT 21H
	RET
	NEG_AX:
	MOV BX, AX
	MOV DX, '-'
	MOV AH, 2
	INT 21H
	MOV AX, BX
	NEG AX
	JMP PRINT_LOOP
	println endp
END MAIN
