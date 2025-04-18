# 脱壳各种方法

### 单步跟踪法

#### 	适用于的壳

​	**UPX壳**：UPX是一种常见的压缩壳，可以通过单步跟踪法找到OEP并脱壳

​	**ASPack壳**：ASPack壳也适用于单步跟踪法，特别是在解压或解密过程中

​	**PECompact壳**：PECompact壳通常可以通过单步跟踪法进行脱壳

​	**FSG壳**：FSG壳在解压或解密过程中也可以通过单步跟踪法找到OEP

​	**加密壳**：部分加密壳（如ASProtect）也可以通过单步跟踪法进行脱壳，但可能需要结合其他方法

#### 	使用步骤

​		**加载程序**
<blockquote style="margin-left: 100px;">
使用调试器（如 OllyDbg、x64dbg 或 IDA Pro）加载加壳程序<br>
确保调试器能够正确识别程序的入口点（EP，Entry Point）
</blockquote>

​		**设置初始断点**
<blockquote style="margin-left: 100px;">
在程序的入口点（EP）处设置断点，确保调试器在程序开始执行时暂停
</blockquote>
​		**单步执行**
<blockquote style="margin-left: 100px;">
从入口点开始，逐条执行指令（通常使用 F7 或 F8 键）<br>
当遇到向上跳转的指令，则跳转到该指令的下一条指令执行<br>
每次执行一条指令后，观察寄存器、内存和程序行为的变化
</blockquote>


​		**识别关键指令**
<blockquote style="margin-left: 100px;">
关注以下关键指令：CALL、JMP 、RET <br>
CALL 指令：壳通常会通过 CALL 跳转到解密或解压函数<br>
JMP 指令：壳可能通过 JMP 跳转到解密后的代码<br>
RET 指令：壳可能通过 RET 返回到解密后的代码
</blockquote>
​		**寻找 OEP**
<blockquote style="margin-left: 100px;">
随着单步跟踪的进行，壳会逐步解密或解压代码<br>
当程序行为开始正常化（例如，出现正常的函数调用或逻辑流程），说明已经接近 OEP<br>
当程序执行到一个 JMP 或 CALL 指令后，程序开始正常运行，此时的跳转目标地址通常就是 OEP
</blockquote>
​		**转储内存**
<blockquote style="margin-left: 100px;">
找到 OEP 后，可以使用调试器的内存转储功能（如 OllyDbg 的 "Dump Debugged Program"）将解密后的程序保存为脱壳后的可执行文件
</blockquote>
#### 注意事项

​		*耐心和细致：*单步跟踪需要逐条执行指令，过程可能非常耗时，需要耐心和细致的观察

​		*避免跑飞：*如果程序突然开始正常运行（即“跑飞”），说明可能跳过了关键的解密逻辑

​		*结合其他方法：*单步跟踪法虽然有效，但效率较低可以结合断点法或特征码扫描法，快速定位关键位置

​		*工具选择：*推荐使用 OllyDbg 或 x64dbg 等调试器，它们支持单步跟踪和内存转储功能

### ESP定律法

#### 适用于的壳

​	**UPX**：UPX是一种常见的压缩壳，ESP定律法可以很方便地找到OEP并完成脱壳

​	**ASPack**：ASPack壳在解压过程中会使用`pushad`和`popad`指令，ESP定律法适用于这种壳

​	**FSG**：FSG变形壳也适用于ESP定律法，通过设置硬件断点可以快速定位到OEP

​	**NSPack**：NSPack壳在解压过程中也会遵循类似的堆栈平衡机制，ESP定律法可以有效找到OEP

​	**ExeStealth**：ExeStealth是一种压缩壳，ESP定律法同样适用于这种壳

​	**WinUpack**：WinUpack壳在解压过程中也会使用类似的机制，ESP定律法可以用于脱壳

​	**其他常见压缩壳**：如BeRoEXEPacker、dePACK、ExeShield Protector、KByS、tElock等，这些壳在解压过程中通常会遵循堆栈平衡机制，因此ESP定律法也适用
#### 	使用步骤

​		**加载程序**
<blockquote style="margin-left: 100px;">
使用调试器（如 OllyDbg、x64dbg 或 IDA Pro）加载加壳程序<br>
确保调试器能够正确识别程序的入口点（EP，Entry Point）
</blockquote>

​		**观察ESP变化**
<blockquote style="margin-left: 100px;">
开始按F8单步执行程序，注意观察寄存器窗口中ESP是否变红（表示ESP值发生变化）
</blockquote>

​		**设置硬件断点**
<blockquote style="margin-left: 100px;">
在命令行中输入dd [ESP地址]（例如dd 0012FF6C），按回车<br>
选中该地址，右键选择“断点 -> 硬件访问 -> Word”
</blockquote>

​		**运行程序**
<blockquote style="margin-left: 100px;">
按F9运行程序，触发断点后程序会停在接近OEP的位置
</blockquote>

​		**找到OEP**
<blockquote style="margin-left: 100px;">
按F8单步跟踪，找到程序的原始入口点（OEP）
</blockquote>
#### 		**注意事项**

​			*选择正确的ESP值：*选择正确的ESP值

​			*硬件断点类型：*通常选择“Word”或“DWORD”硬件断点，以确保触发断点

​			*避免跑飞：*如果程序运行后没有触发断点，可能是硬件断点设置错误，需重新检查ESP值

​			*工具选择：*推荐使用 OllyDbg 或 x64dbg 等调试器，它们支持单步跟踪和内存转储功能



### 内存镜像法（二次断点法）

#### 适用于的壳

​	**UPX**：UPX是一种常见的压缩壳，ESP定律法可以很方便地找到OEP并完成脱壳

​	**FSG**：FSG变形壳也适用于ESP定律法，通过设置硬件断点可以快速定位到OEP

​	**PECompact**：PECompact壳在解压过程中同样会先访问资源段，内存镜像法可以用于找到OEP

​	**其他常见压缩壳**：如BeRoEXEPacker、dePACK、ExeShield Protector、KByS、tElock等，这些壳在解压过程中通常会遵循堆栈平衡机制，因此ESP定律法也适用

#### 使用步骤

​		**加载程序**
<blockquote style="margin-left: 100px;">
使用调试器（如 OllyDbg、x64dbg 或 IDA Pro）加载加壳程序<br>
确保调试器能够正确识别程序的入口点（EP，Entry Point）
</blockquote>

​		**设置第一个断点**
<blockquote style="margin-left: 100px;">
按Alt+M打开内存镜像窗口<br>
找到程序的第一个.rsrc（资源段），按F2设置断点
</blockquote>

​		**运行程序**
<blockquote style="margin-left: 100px;">
按Shift+F9或F9运行程序，直到触发第一个断点
</blockquote>

​		**设置第二个断点**
<blockquote style="margin-left: 100px;">
再次按Alt+M打开内存镜像窗口<br>
找到程序的第一个.text（代码段），按F2设置断点
</blockquote>

​		**再次运行程序**
<blockquote style="margin-left: 100px;">
按Shift+F9或F9运行程序，程序将停在OEP处
</blockquote>
#### 注意事项

​		*忽略异常：*在调试选项中，确保勾选“忽略所有异常”，以避免程序因异常而中断

​		*断点顺序：*必须先在.rsrc段设置断点，再在.text段设置断点，顺序不能颠倒

​		*断点类型：*使用一次性断点，以确保程序在触发断点后不会继续运行

​		*避免跑飞：*如果程序运行后没有触发断点，可能是断点设置错误，需重新检查内存段

​		*工具选择：*推荐使用 OllyDbg 或 x64dbg 等调试器，它们支持单步跟踪和内存转储功能

### 最后一次异常法

#### 适用于的壳

​	**UPX**：UPX是一种流行的压缩壳，其在脱壳过程中可能会触发异常。通过最后一次异常法，可以在程序自解压或自解密过程中，定位到最后一次异常的位置，从而接近程序真正的入口点，实现脱壳。

​	**ASPack**：ASPack也是一种常见的压缩壳，它在解压过程中可能会产生异常。利用最后一次异常法，可以尝试找到解压完成后的程序入口点，进而完成脱壳。

​	**PECompact**：PECompact作为压缩壳的一种，其解压过程也可能涉及异常。通过这种方法，可以定位到解压后的关键位置，帮助脱壳。

​	**ASProtect**：ASProtect是一种加密壳，它在解密过程中可能会产生异常。最后一次异常法可以帮助定位到解密完成后的程序入口点，从而实现脱壳。

​	**Armadillo**：Armadillo加密壳在解密过程中也可能触发异常。通过这种方法，可以找到解密后的程序入口点，进而完成脱壳

#### 使用步骤：

​		**设置调试器选项**
<blockquote style="margin-left: 100px;">
在调试器（如 Ollydbg）中，打开“选项->调试选项->异常”菜单，取消勾选所有异常的忽略选项
</blockquote>

​		**载入程序并记录异常次数**
<blockquote style="margin-left: 100px;">
载入目标程序后，按 `Shift+F9` 运行程序，直到程序正常运行。记录按下 `Shift+F9` 的次数 `m`，这是程序触发的异常总次数
</blockquote>

​		**重新载入程序并忽略部分异常**
<blockquote style="margin-left: 100px;">
重新载入程序后，按 `Shift+F9` `m-1` 次，忽略前 `m-1` 次异常
</blockquote>

​		**查看异常处理程序地址**
<blockquote style="margin-left: 100px;">
在调试器的右下角查看“SE句柄”地址
</blockquote>

​		**设置断点并运行**
<blockquote style="margin-left: 100px;">
在“SE句柄”地址处设置断点（按 `Ctrl+G` 输入地址，然后按 `F2` 设置断点），按 `Shift+F9` 运行程序，直到触发断点
</blockquote>

​		**单步跟踪到 OEP**
<blockquote style="margin-left: 100px;">
触发断点后，使用单步跟踪（如 `F8`）找到程序的原始入口点（OEP）
</blockquote>
#### 注意事项

​		*异常次数的准确性：*确保在第一次运行时准确记录异常次数 m，否则可能导致定位错误

​		*调试器设置：*在调试器中正确设置异常选项，避免忽略关键异常

​		*断点的正确性：*在“SE句柄”地址处设置断点时，确保地址正确，否则可能无法触发断点

​		*单步跟踪的耐心：*在单步跟踪到 OEP 的过程中，可能需要跳过一些无关的指令，注意观察汇编代码的逻辑

​		*工具辅助：*可以结合 ImportREC 等工具修复程序的导入表（IAT），以确保脱壳后的程序能够正常运行



### 模拟跟踪法
#### 	适用于的壳

​	**UPX**：UPX是一种常见的压缩壳，其解压过程可以通过模拟跟踪法找到OEP。

​	**ASPack**：ASPack的解压过程也可以通过模拟跟踪法找到OEP。

​	**PECompact**：PECompact的解压过程适用于模拟跟踪法。

​	**Armadillo**：Armadillo的解密过程可以通过模拟跟踪法找到OEP。

#### 	使用步骤

​		**设置初始断点**
<blockquote style="margin-left: 100px;">
在Ollydbg中，使用条件断点（如tc或toc命令）来跟踪EIP的变化<br>
例如，输入tc eip < 0x4F1000，让调试器跟踪EIP是否小于某个地址
</blockquote>

​		**运行程序并跟踪**
<blockquote style="margin-left: 100px;">
载入目标程序后，按Shift+F9运行程序，直到EIP满足条件<br>
如果程序中途暂停，可以继续使用tc命令进行跟踪
</blockquote>

​		**找到OEP**
<blockquote style="margin-left: 100px;">
当EIP进入目标代码段时，程序通常已经接近OEP
</blockquote>



#### 注意事项

​		*条件设置的准确性：*确保条件断点的设置正确，否则可能导致跟踪失败

​		*耐心跟踪：*模拟跟踪法可能会比较耗时，需要耐心跟踪每条指令

​		*结合其他方法：*可以结合其他脱壳方法（如单步跟踪法）来提高效率




### "SFX"法
#### 	适用于的壳

​	**UPX壳**：UPX是一种常见的压缩壳，可以通过单步跟踪法找到OEP并脱壳

​	**ASPack壳**：ASPack壳也适用于单步跟踪法，特别是在解压或解密过程中

​	**PECompact壳**：PECompact壳通常可以通过单步跟踪法进行脱壳

#### 	使用步骤

​		**启用SFX功能**
<blockquote style="margin-left: 100px;">
在Ollydbg中，打开“选项->调试选项”，启用SFX功能
</blockquote>


​		**选择跟踪方式**
<blockquote style="margin-left: 100px;">
SFX法分为块方式跟踪和字节方式跟踪:<br>
1.块方式跟踪：速度较快，但准确性稍差<br>
2.字节方式跟踪：速度较慢，但准确性更高
</blockquote>

​		**运行程序**
<blockquote style="margin-left: 100px;">
载入目标程序后，按Shift+F9运行程序，直到调试器停止在OEP处
</blockquote>


#### 注意事项

​		*跟踪方式的选择：*根据实际需求选择适合的跟踪方式，块方式适合快速定位，字节方式适合精确定位

​		*调试器设置：*确保调试器的SFX功能正确启用，否则可能导致跟踪失败

​		*结合其他方法：*SFX法可以与其他脱壳方法结合使用，以提高脱壳效率
