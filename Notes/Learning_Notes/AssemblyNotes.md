# 汇编指令

### **字符串操作类**

##### MOVSB

​	**全称：**Move String Byte（移动字符串字节）

​	**功能：**将源字符串字节（DS:SI）移动到目标字符串字节（ES:DI），并根据方向标志（DF）调整SI和DI

​	**用途：**

<blockquote style="margin-left: 80px;">
用于字符串复制
</blockquote>
​	**示例：**

```assembly
MOVSB          ; 移动字符串字节
```

##### MOVSW

​	**全称：**Move String Word（移动字符串字）

​	**功能：**将源字符串字（DS:SI）移动到目标字符串字（ES:DI），并根据方向标志（DF）调整SI和DI

​	**用途：**

<blockquote style="margin-left: 80px;">
用于字符串复制
</blockquote>
​	**示例：**

```assembly
MOVSW          ; 移动字符串字
```
##### SCASB

​	**全称：**Scan String Byte（扫描字符串字节）

​	**功能：**比较AL和ES:DI处的字节，设置标志位，并根据方向标志（DF）调整DI

​	**用途：**

<blockquote style="margin-left: 80px;">
用于字符串查找
</blockquote>
​	**示例：**

```assembly
SCASB          ; 扫描字符串字节
```
##### SCASW

​	**全称：**Scan String Word（扫描字符串字）

​	**功能：**比较AX和ES:DI处的字，设置标志位，并根据方向标志（DF）调整DI

​	**用途：**

<blockquote style="margin-left: 80px;">
用于字符串查找
</blockquote>
​	**示例：**

```assembly
SCASW          ; 扫描字符串字
```
##### LODSB

​	**全称：**Load String Byte（加载字符串字节）

​	**功能：**将DS:SI处的字节加载到AL，并根据方向标志（DF）调整SI

​	**用途：**

<blockquote style="margin-left: 80px;">
用于字符串加载
</blockquote>
​	**示例：**

```assembly
LODSB          ; 加载字符串字节
```
##### LODSW

​	**全称：**Load String Word（加载字符串字）

​	**功能：**将DS:SI处的字加载到AX，并根据方向标志（DF）调整SI

​	**用途：**

<blockquote style="margin-left: 80px;">
用于字符串加载
</blockquote>
​	**示例：**

```assembly
LODSW          ; 加载字符串字
```
##### STOSB

​	**全称：**Store String Byte（存储字符串字节）

​	**功能：将AL存储到ES:DI处的字节，并根据方向标志（DF）调整DI**

​	**用途：**

<blockquote style="margin-left: 80px;">
用于字符串存储
</blockquote>
​	**示例：**

```assembly
STOSB          ; 存储字符串字节
```
##### STOSW

​	**全称：**Store String Word（存储字符串字）

​	**功能：**将AX存储到ES:DI处的字，并根据方向标志（DF）调整DI

​	**用途：**

<blockquote style="margin-left: 80px;">
用于字符串存储
</blockquote>
​	**示例：**

```assembly
STOSW          ; 存储字符串字
```
### 处理器控制类

##### CLI

​	**全称：**Clear Interrupt（清除中断）

​	**功能：**关闭CPU的中断

​	**用途：**

<blockquote style="margin-left: 80px;">
用于临界区的保护
</blockquote>
​	**示例：**

```assembly
CLI            ; 清除中断
```
##### STI

​	**全称：**Set Interrupt（设置中断）

​	**功能：**打开CPU的中断

​	**用途：**

<blockquote style="margin-left: 80px;">
用于恢复中断
</blockquote>
​	**示例：**

```assembly
STI            ; 设置中断
```
##### HLT

​	**全称：**Halt（暂停）

​	**功能：**暂停CPU的执行

​	**用途：**

<blockquote style="margin-left: 80px;">
用于等待外部事件
</blockquote>
​	**示例：**

```assembly
HLT            ; 暂停CPU
```
##### NOP

​	**全称：**No Operation（无操作指令）

​	**功能：**执行时不做任何实际操作，相当于“空操作”


​	**用途：**

<blockquote style="margin-left: 80px;">
用于调整程序的时序（例如，延迟循环）<br>
用于代码对齐（确保某些指令落在特定的地址边界）<br>
作为调试工具（插入 NOP 指令可以方便地修改或跳过代码）
</blockquote>
​	

​	**示例：**

```assembly
NOP          ; 执行空操作
```

##### WAIT

​	**全称：**Wait（等待）

​	**功能：**暂停CPU的执行，直到某个条件满足

​	**用途：**

<blockquote style="margin-left: 80px;">
用于等待外部事件
</blockquote>
​	**示例：**

```assembly
WAIT           ; 等待
```
### 堆栈操作类

##### PUSH

​	**全称：**Push（压栈）

​	**功能：**将操作数压入堆栈

​	**用途：**

<blockquote style="margin-left: 80px;">
用于保存寄存器或内存中的值
</blockquote>
​	**示例：**

```assembly
PUSH AX        ; 将AX压入堆栈
```
##### POP

​	**全称：**Pop（弹栈）

​	**功能：**从堆栈中弹出值到操作数

​	**用途：**

<blockquote style="margin-left: 80px;">
用于恢复寄存器或内存中的值
</blockquote>
​	**示例：**

```assembly
POP AX         ; 从堆栈弹出值到AX
```
##### PUSHF

​	**全称：**Push Flags（压入标志寄存器）

​	**功能：**将标志寄存器的值压入堆栈

​	**用途：**

<blockquote style="margin-left: 80px;">
用于保存标志寄存器的值
</blockquote>
​	**示例：**

```assembly
PUSHF          ; 将标志寄存器压入堆栈
```
##### POPF

​	**全称：**Pop Flags（弹出标志寄存器）

​	**功能：**从堆栈中弹出值到标志寄存器

​	**用途：**

<blockquote style="margin-left: 80px;">
用于恢复标志寄存器的值
</blockquote>
​	**示例：**

```assembly
POPF           ; 从堆栈弹出值到标志寄存器
```
##### ENTER

​	**全称：**Enter Procedure（进入过程）

​	**功能：**设置过程的堆栈帧

​	**用途：**

<blockquote style="margin-left: 80px;">
用于过程的初始化
</blockquote>
​	**示例：**

```assembly
ENTER 10, 0    ; 设置堆栈帧
```
##### LEAVE

​	**全称：**Leave Procedure（离开过程）

​	**功能：**恢复过程的堆栈帧

​	**用途：**

<blockquote style="margin-left: 80px;">
用于过程的结束
</blockquote>
​	**示例：**

```assembly
LEAVE          ; 恢复堆栈帧
```
### 数据传送类

##### MOV

​	**全称：**Move（移动）

​	**功能：**将数据从源操作数移动到目标操作数

​	**用途：**

<blockquote style="margin-left: 80px;">
用于数据传输
</blockquote>
​	**示例：**

```assembly
MOV AX, BX     ; 将BX的值移动到AX
```

##### XCHG

​	**全称：**Exchange（交换）

​	**功能：**交换两个操作数的值

​	**用途：**

<blockquote style="margin-left: 80px;">
用于交换寄存器或内存中的值
</blockquote>
​	**示例：**

```assembly
XCHG AX, BX    ; 交换AX和BX的值
```
##### LEA

​	**全称：**Load Effective Address（加载有效地址）

​	**功能：**将操作数的有效地址加载到寄存器

​	**用途：**

<blockquote style="margin-left: 80px;">
用于获取内存地址
</blockquote>
​	**示例：**

```assembly
LEA SI, [BX+2] ; 将BX+2的有效地址加载到SI
```
### 算数运算类

##### ADD

​	**全称：**Add（加法）

​	**功能：**将两个操作数相加，并将结果存储在目标操作数

​	**用途：**

<blockquote style="margin-left: 80px;">
用于加法运算
</blockquote>
​	**示例：**

```assembly
ADD AX, BX     ; 将AX和BX相加，结果存储在AX
```
##### SUB

​	**全称：**Subtract（减法）

​	**功能：**将目标操作数减去源操作数，并将结果存储在目标操作数

​	**用途：**

<blockquote style="margin-left: 80px;">
用于减法运算
</blockquote>
​	**示例：**

```assembly
SUB AX, BX     ; 将AX减去BX，结果存储在AX
```
##### MUL

​	**全称：**Multiply（乘法）

​	**功能：**将两个操作数相乘，并将结果存储在寄存器

​	**用途：**

<blockquote style="margin-left: 80px;">
用于乘法运算
</blockquote>
​	**示例：**

```assembly
MUL BX         ; 将AX和BX相乘，结果存储在DX:AX
```
##### DIV

​	**全称：**Divide（除法）

​	**功能：**将寄存器中的值除以操作数，并将商和余数存储在寄存器

​	**用途：**

<blockquote style="margin-left: 80px;">
用于除法运算
</blockquote>
​	**示例：**

```assembly
DIV BX         ; 将DX:AX除以BX，商存储在AX，余数存储在DX
```
##### INC

​	**全称：**Increment（自增）

​	**功能：**将操作数加1

​	**用途：**

<blockquote style="margin-left: 80px;">
用于自增操作
</blockquote>
​	**示例：**

```assembly
INC AX         ; AX加1
```
##### DEC

​	**全称：**Decrement（自减）

​	**功能：**将操作数减1

​	**用途：**

<blockquote style="margin-left: 80px;">
用于自减操作
</blockquote>
​	**示例：**

```assembly
DEC AX         ; AX减1
```
### 逻辑运算类

##### AND

​	**全称：**Logical AND（逻辑与）

​	**功能：**对两个操作数进行按位与运算，并将结果存储在目标操作数

​	**用途：**

<blockquote style="margin-left: 80px;">
用于按位与运算<br>
常用于屏蔽某些位或检查标志位
</blockquote>
​	**示例：**

```assembly
AND AX, BX    ; 将 AX 和 BX 进行按位与运算，结果存储在 AX
```
##### OR

​	**全称：**Logical OR（逻辑或）

​	**功能：**对两个操作数进行按位或运算，并将结果存储在目标操作数

​	**用途：**

<blockquote style="margin-left: 80px;">
用于按位或运算<br>
常用于设置某些位或合并多个标志位
</blockquote>
​	**示例：**

```assembly
OR AX, BX     ; 将 AX 和 BX 进行按位或运算，结果存储在 AX
```
##### XOR

​	**全称：**Logical XOR（逻辑异或）

​	**功能：**对两个操作数进行按位异或运算，并将结果存储在目标操作数

​	**用途：**

<blockquote style="margin-left: 80px;">
用于按位异或运算<br>
常用于加密、数据校验或交换变量值
</blockquote>
​	**示例：**

```assembly
XOR AX, BX    ; 将 AX 和 BX 进行按位异或运算，结果存储在 AX
```
##### NOT

​	**全称：**Logical NOT（逻辑非）

​	**功能：**对操作数进行按位取反运算，并将结果存储在操作数

​	**用途：**

<blockquote style="margin-left: 80px;">
用于按位取反运算<br>
常用于反转标志位或实现简单的加密
</blockquote>
​	**示例：**

```assembly
NOT AX        ; 对 AX 进行按位取反
```
##### SHL

​	**全称：**Shift Left（左移）

​	**功能：**将操作数的位向左移动指定的位数，并将结果存储在操作数

​	**用途：**

<blockquote style="margin-left: 80px;">
用于按位左移运算<br>
常用于快速乘法运算（例如，左移1位相当于乘以2）
</blockquote>
​	**示例：**

```assembly
SHL AX, 1     ; 将 AX 的位向左移动1位
```
##### SHR

​	**全称：**Shift Right（右移）

​	**功能：**将操作数的位向右移动指定的位数，并将结果存储在操作数

​	**用途：**

<blockquote style="margin-left: 80px;">
用于按位右移运算<br>
常用于快速除法运算（例如，右移1位相当于除以2）
</blockquote>
​	**示例：**

```assembly
SHR AX, 1     ; 将 AX 的位向右移动1位
```
### 程序控制类

##### JMP

​	**全称：**Jump（无条件跳转）

​	**功能：**将程序的执行流程跳转到指定的地址

​	**用途：**

<blockquote style="margin-left: 80px;">
实现程序的无条件跳转<br>
常用于循环结构或跳过某些代码块
</blockquote>
​	**示例：**

```assembly
JMP EXIT      ; 无条件跳转到 EXIT 标签
```

##### JE

​	**全称：**Jump if Equal（如果相等则跳转）

​	**功能：**根据 **零标志位（ZF）** 和 **进位标志位（CF）** 的状态决定是否跳转

<blockquote style="margin-left: 80px;">
如果 ZF = 1 且 CF = 0，则跳转到指定的地址
</blockquote>


​	**用途：**

<blockquote style="margin-left: 80px;">
用于条件分支逻辑<br>
常用于判断两个无符号数是否相等
</blockquote>
​	**示例：**

```assembly
CMP AX, BX    ; 比较 AX 和 BX 是否相等
JE EXIT       ; 如果相等，则跳转到 EXIT 标签
```

##### JNE

​	**全称：**Jump if Not Equal（如果不相等则跳转）

​	**功能：**根据 **零标志位（ZF）** 和 **进位标志位（CF） **的状态决定是否跳转

<blockquote style="margin-left: 80px;">
如果 ZF = 0 且 CF = 0，则跳转到指定的地址
</blockquote>


​	**用途：**

<blockquote style="margin-left: 80px;">
用于条件分支逻辑<br>
常用于判断两个无符号数是否不相等
</blockquote>
​	**示例：**

```assembly
CMP AX, 0    ; 比较 AX 是否为零
JZ EXIT      ; 如果 AX 为零，跳转到 EXIT 标签
```

##### JZ

​	**全称：**Jump if Zero（如果为零则跳转）

​	**功能：**根据 **零标志位（ZF）** 的状态决定是否跳转

<blockquote style="margin-left: 80px;">
如果 ZF = 1，则跳转到指定的地址
</blockquote>


​	**用途：**

<blockquote style="margin-left: 80px;">
用于条件分支逻辑<br>
常用于判断某个条件是否满足（例如，检查某个值是否为零）
</blockquote>
​	**示例：**

```assembly
CMP AX, BX    ; 比较 AX 和 BX 是否相等
JNE LOOP      ; 如果不相等，则跳转到 LOOP 标签
```

##### JNZ

​	**全称：**Jump if Not Zero（如果不为零则跳转）

​	**功能：**根据 根据 **零标志位（ZF）**的状态决定是否跳转

<blockquote style="margin-left: 80px;">
如果 ZF = 0，则跳转到指定的地址
</blockquote>


​	**用途：**

<blockquote style="margin-left: 80px;">
用于条件分支逻辑<br>
常用于循环结构（例如，当某个条件不满足时继续循环）
</blockquote>
​	**示例：**

```assembly
CMP AX, 0    ; 比较 AX 是否为零
JNZ LOOP     ; 如果 AX 不为零，跳转到 LOOP 标签
```

##### JG

​	**全称：**Jump if Greater（如果大于则跳转）

​	**功能：**根据 **零标志位（ZF）**、**进位标志位（CF）** 和 **溢出标志位（OF）**的状态决定是否跳转

<blockquote style="margin-left: 80px;">
如果 CF = 0 且 ZF = 0 且 OF = 0，则跳转到指定的地址
</blockquote>


​	**用途：**

<blockquote style="margin-left: 80px;">
用于条件分支逻辑<br>
常用于判断一个有符号数是否大于另一个有符号数
</blockquote>
​	**示例：**

```assembly
CMP AX, BX    ; 比较 AX 和 BX 的大小
JG EXIT       ; 如果 AX 大于 BX，则跳转到 EXIT 标签
```
##### JGE

​	**全称：**Jump if Greater or Equal（如果大于或等于则跳转）

​	**功能：**根据 **进位标志位（CF）** 和 **溢出标志位（OF）** 的状态决定是否跳转

<blockquote style="margin-left: 80px;">
    如果 CF = 0 且 OF = 0，则跳转到指定的地址
</blockquote>


​	**用途：**

<blockquote style="margin-left: 80px;">
用于条件分支逻辑<br>
常用于判断一个有符号数是否大于或等于另一个有符号数
</blockquote>
​	**示例：**

```assembly
CMP AX, BX    ; 比较 AX 和 BX 的大小
JGE EXIT      ; 如果 AX 大于或等于 BX，则跳转到 EXIT 标签
```

##### JL

​	**全称：**Jump if Less（如果小于则跳转）

​	**功能：**根据 **进位标志位（CF）** 和 **溢出标志位（OF）** 的状态决定是否跳转

<blockquote style="margin-left: 80px;">
如果 CF = 1 且 OF = 0，则跳转到指定的地址
</blockquote>

​	**用途：**

<blockquote style="margin-left: 80px;">
用于条件分支逻辑<br>
常用于判断一个有符号数是否小于另一个有符号数
</blockquote>
​	**示例：**

```assembly
CMP AX, BX    ; 比较 AX 和 BX 的大小
JL EXIT       ; 如果 AX 小于 BX，则跳转到 EXIT 标签
```

##### JLE

​	**全称：**Jump if Less or Equal（如果小于或等于则跳转）

​	**功能：**根据 **零标志位（ZF）**、**进位标志位（CF）** 和** 溢出标志位（OF）** 的状态决定是否跳转

<blockquote style="margin-left: 80px;">
如果 (ZF = 1) 或 (CF = 1 且 OF = 0)，则跳转到指定的地址
</blockquote>

​	**用途：**

<blockquote style="margin-left: 80px;">
用于条件分支逻辑<br>
常用于判断一个有符号数是否小于或等于另一个有符号数
</blockquote>
​	**示例：**

```assembly
CMP AX, BX    ; 比较 AX 和 BX 的大小
JLE EXIT      ; 如果 AX 小于或等于 BX，则跳转到 EXIT 标签
```

##### CALL

​	**全称：**Call Procedure（调用过程）	

​	**功能：**将当前指令地址压入堆栈，然后跳转到指定的过程地址

​	**用途：**

<blockquote style="margin-left: 80px;">
用于调用子程序或函数<br>
常用于模块化编程
</blockquote>
​	**示例：**

```assembly
CALL MY_PROC  ; 调用名为 MY_PROC 的子程序
```

##### RET

​	**全称：**Return from Procedure（从过程返回）

​	**功能：**从堆栈中弹出返回地址，并跳转到该地址继续执行

​	**用途：**

<blockquote style="margin-left: 80px;">
用于从子程序返回主程序<br>
常用于模块化编程
</blockquote>
​	**示例：**

```assembly
RET           ; 从子程序返回主程序
```

### 输入输出类

##### IN

​	**全称：**Input（输入）

​	**功能：**从指定的端口读取数据，并将结果存储在目标寄存器

​	**用途：**

<blockquote style="margin-left: 80px;">
用于从硬件设备读取数据<br>
常用于设备驱动程序
</blockquote>
​	**示例：**

```assembly
IN AL, 60H    ; 从端口 60H 读取数据到 AL
```
##### OUT

​	**全称：**Output（输出）

​	**功能：**将数据从源寄存器发送到指定的端口

​	**用途：**

<blockquote style="margin-left: 80px;">
用于向硬件设备发送数据<br>
常用于设备驱动程序
</blockquote>

​	**示例：**

```assembly
OUT 60H, AL   ; 将 AL 的数据发送到端口 60H
```
### 特殊指令类

##### INT

​	**全称：**Interrupt（中断）

​	**功能：**触发软件中断，将控制权转移到中断服务程序

​	**用途：**

<blockquote style="margin-left: 80px;">
用于调用系统服务或处理异常<br>
常用于系统调用或调试
</blockquote>
​	**示例：**

```assembly
INT 21H       ; 触发中断 21H（DOS 系统调用）
```
##### IRET

​	**全称：**Interrupt Return（中断返回）

​	**功能：**从堆栈中弹出标志寄存器、代码段寄存器和指令指针寄存器，恢复中断前的状态

​	**用途：**

<blockquote style="margin-left: 80px;">
用于从中断服务程序返回主程序<br>
常用于中断处理
</blockquote>
​	**示例：**

```assembly
IRET          ; 从中断服务程序返回主程序
```
##### ESC

​	**全称：**Escape（转义）

​	**功能：**将指令传递给协处理器执行

​	**用途：**

<blockquote style="margin-left: 80px;">
用于扩展指令集<br>
常用于浮点运算或图形处理
</blockquote>
​	**示例：**

```assembly
ESC 0F8H      ; 将指令传递给协处理器
```
### 位操作类

##### TEST

​	**全称：**Test（测试）

​	**功能：**对两个操作数进行按位与运算，并根据结果设置标志位，但不存储结果

​	**用途：**

<blockquote style="margin-left: 80px;">
用于测试标志位或检查条件<br>
常用于条件判断
</blockquote>
​	**示例：**

```assembly
TEST AX, BX   ; 对 AX 和 BX 进行按位与运算，并设置标志位
```
##### BTS

​	**全称：**Bit Test and Set（测试并设置位）

​	**功能：**测试指定位置的位，并将该位置1

​	**用途：**

<blockquote style="margin-left: 80px;">
用于设置标志位并检查其状态<br>
常用于位操作
</blockquote>

​	**示例：**

```assembly
BTS AX, 0     ; 测试并设置 AX 的第0位
```
##### BTR

​	**全称：**Bit Test and Reset（测试并清除位）

​	**功能：**测试指定位置的位，并将该位清0

​	**用途：**

<blockquote style="margin-left: 80px;">
用于清除标志位并检查其状态<br>
常用于位操作
</blockquote>
​	**示例：**

```assembly
BTR AX, 0     ; 测试并清除 AX 的第0位
```
##### BTC

​	**全称：**Bit Test and Complement（测试并翻转位）

​	**功能：**测试指定位置的位，并将该位取反

​	**用途：**

<blockquote style="margin-left: 80px;">
用于翻转标志位并检查其状态<br>
常用于位操作
</blockquote>

​	**示例：**

```assembly
BTC AX, 0     ; 测试并翻转 AX 的第0位
```


# 汇编寄存器

### 通用寄存器（General Purpose Registers）

#### x86 架构

##### 16 位模式：

- `AX`（累加器）：用于算术运算和数据传输
- `BX`（基址寄存器）：用于内存寻址
- `CX`（计数寄存器）：用于循环计数
- `DX`（数据寄存器）：用于 I/O 操作和数据传输

##### 32 位模式：

- `EAX`：扩展累加器
- `EBX`：扩展基址寄存器
- `ECX`：扩展计数寄存器
- `EDX`：扩展数据寄存器
- `ESI`（源索引寄存器）：用于字符串操作
- `EDI`（目的索引寄存器）：用于字符串操作
- `EBP`（基指针寄存器）：用于堆栈操作
- `ESP`（堆栈指针寄存器）：用于堆栈操作

##### 64 位模式：

- `RAX`：64 位扩展累加器

- `RBX`：64 位扩展基址寄存器

- `RCX`：64 位扩展计数寄存器

- `RDX`：64 位扩展数据寄存器

- `RSI`：64 位源索引寄存器

- `RDI`：64 位目的索引寄存器

- `RBP`：64 位基指针寄存器

- `RSP`：64 位堆栈指针寄存器

- `R8` 到 `R15`：额外的通用寄存器（64 位模式新增）

#### ARM 架构

- `R0` 到 `R12`：通用寄存器，用于存储数据和地址
- `R13`（`SP`）：堆栈指针
- `R14`（`LR`）：链接寄存器，用于存储返回地址
- `R15`（`PC`）：程序计数器，存储下一条指令的地址

### 段寄存器（Segment Registers）

#### x86 架构

- `CS`（代码段寄存器）：存储代码段的起始地址
- `DS`（数据段寄存器）：存储数据段的起始地址
- `SS`（堆栈段寄存器）：存储堆栈段的起始地址
- `ES`（额外段寄存器）：用于额外的数据段
- `FS` 和 `GS`：扩展段寄存器，用于特殊用途

###  控制寄存器（Control Registers）

#### x86 架构

- `CR0`：控制处理器的模式（如保护模式、分页模式）
- `CR2`：存储最近一次页错误的线性地址
- `CR3`：存储页目录表的物理地址
- `CR4`：控制高级功能（如物理地址扩展、调试扩展等）

### 调试寄存器（Debug Registers）

#### x86 架构

- `DR0` 到 `DR7`：用于设置断点地址和调试控制

### 指令指针寄存器（Instruction Pointer Register）

#### x86 架构

- `IP`（16 位）、`EIP`（32 位）、`RIP`（64 位）：存储当前正在执行的指令的地址

#### ARM 架构

- `PC`（程序计数器）：存储下一条指令的地址

### 标志寄存器（Flags Register）

#### x86 架构

- `FLAGS`（16 位）、`EFLAGS`（32 位）、`RFLAGS`（64 位）：存储处理器的状态标志，如：
  - `CF`（进位标志）：表示算术运算中是否有进位
  - `ZF`（零标志）：表示结果是否为零
  - `SF`（符号标志）：表示结果是否为负数
  - `OF`（溢出标志）：表示算术运算中是否有溢出

#### ARM 架构

- `CPSR`（当前程序状态寄存器）：存储处理器的状态标志，如：
  - `N`（负标志）：结果为负
  - `Z`（零标志）：结果为零
  - `C`（进位标志）：算术运算中有进位
  - `V`（溢出标志）：算术运算中有溢出

### 堆栈寄存器（Stack Registers）

#### x86 架构

- `SP`（16 位）、`ESP`（32 位）、`RSP`（64 位）：存储堆栈的顶部地址

#### ARM 架构

- `R13`（`SP`）：堆栈指针

### 其他专用寄存器

#### x86 架构

- `TR`（任务寄存器）：用于任务切换
- `GDTR`（全局描述符表寄存器）：存储全局描述符表的地址和大小
- `LDTR`（局部描述符表寄存器）：存储局部描述符表的地址和大小
- `IDTR`（中断描述符表寄存器）：存储中断描述符表的地址和大小

#### ARM 架构

- `SCTLR`（系统控制寄存器）：控制处理器的模式和功能
- `TTBR0` 和 `TTBR1`：存储页表的基地址
- `DACR`（域访问控制寄存器）：控制内存访问权限
