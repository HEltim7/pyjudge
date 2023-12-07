# pyjudge

> HEltim7自用的简易算法竞赛评测&对拍脚本，使用python编写

## 基础配置&安装

首先，需要确保本地有可用的 python 环境。

pyjudge仅由单个文件 `pyjudge.py` 构成，直接下载至本地即可。

然后使用 `python /path/to/pyjudge.py -v` 检查是否能正确显示版本号。

### 更快捷地使用pyjudge

每次打一长串的 `python xxx/pyjudge.py` 十分地不优雅，我们可以使用shell别名等方式来简化对脚本的调用。

**UNIX-like**

我们可以直接使用 `bash`,`zsh`,`fish` 等 shell 提供的 `alias` 命令来设置别名。编辑对应shell的配置文件也能达到同样的效果。

例如在fish中可以使用以下命令设置 alias：

```shell
alias -s pyjudge="python /path/to/pyjudge.py"
```

**Windows**

在 windows 下会略微有些麻烦。

以普通用户的权限打开 powershell，然后将定义一个 pyjudge function 写入到你的 powershell profile。记得将 `\path\to\pyjudge.py` 修改为正确的路径。

```pwsh
echo "" >> $PROFILE ; echo "function pyjudge { python \path\to\pyjudge.py @Args }" >> $PROFILE
```

或者直接使用记事本编辑。

```pwsh
notepad $PROFILE
# 写入以下内容，记得修改路径
function pyjudge { python \path\to\pyjudge.py @Args }
```

由于 Windows 的默认安全策略会阻止 powershell profile 的工作，所以需要更新安全策略。

```pwsh
# 将当前用户的安全策略更改为 RemoteSigned
Set-ExecutionPolicy RemoteSigned -Scope CurrentUser
```

然后重新打开 powershell 以应用更改。

---

如果配置正确，你应该可直接调用 pyjudge：

```
pyjudge -v
```

## 快速上手&例子

pyjudge 使用子命令的方式来控制工作逻辑。

```shell
pyjudge --help # 查看内置的帮助文档
pyjudge [action] --help # 查看子命令的帮助文档
```

可用的 `action` 有 `judge,run,hack`。

### 通用选项

有些选项是在各子命令中是通用的。

- `-t/--tle 1.5` 将时限设置为 `1.5s`，默认值为 `1s`。
  - 特别的，测试数据生成代码、SPJ 的默认时限为 `60s`，并与指定的 `tle` 取max。
- `-d/--dir test` 将测试数据目录设置为 `./test`，默认值为 `./testcases`。

### judge

顾名思义，judge 用来评测代码，这也是 pyjduge 最初的功能。

```shell
pyjudge judge [通用选项] [--spj SPJ] <要评测的代码>
```

评测 `A.cpp`，测试目录指定为 `test`，时限设定为 `1.5s`。

```shell
pyjudge judge A.cpp --dir test --tle 1.5
```

脚本将重定向测试代码的标准输入为 `test` 目录下的 `.in` 文件，之后将标准输出与同目录下的 `.out` 文件进行对比。标准错误将被直接打印，主要是为了方便调试。

### run

run 是 judge 的一个特例，仅检查代码是否能够正确运行而不检查正确性。主要在仅有输入文件而没有输出文件的情况下使用。

```shell
pyjudge run [通用选项] <要运行的代码>
```

运行 `A.cpp`

```shell
pyjudge run A.cpp
```

运行 `A.cpp` 并保存输出到 `.out` 文件作为答案，如果已有对应的 `.out` 文件，那么将其覆盖。

```shell
pyjudge run A.cpp --save
```

### hack

使用 hack 命令来寻找一组能够 hack 测试代码的数据。

```shell
pyjudge hack [通用选项] --gen <数据生成代码> (--std <标程> | --spj <SPJ>) <要hack的代码> 
```

指定 `gen.py` 为数据生成器，`std.cpp` 为标程，`tset.cpp`为测试代码，暴力搜索一组hack数据。

```shell
pyjudge hack --std std.cpp --gen gen.py test.cpp
```

hack数据将被保存到指定文件夹的 `hack_x.in` 与 `hack_x.out`。

## SPJ

实验性功能，pyjudge 现在可以指定 SPJ 来评测答案的正确性。

### SPJ 协议

pyjudge 将会把输入数据 `xx.in` 与待评测代码的输出数据 `xx.out` 合并成一个文件作为 SPJ 的标准输入。

SPJ 需要先读入全部的输入数据，再读入答案。

> 这样做的目的主要是避免 SPJ 的读文件操作，从而简化 SPJ 的编写。但是在面对多组测试数据的时候会适得其反，因此这种做法还有待改善。

如果答案正确，SPJ 应返回0，否则返回1，其他的返回值会被视为 SPJ RE。SPJ 的标准输出将被作为注释打印在评测结果之后。

### 使用 SPJ

在 judge 中使用

```shell
pyjudge judge test.cpp --spj spj.cpp
```

在 hack 中使用

```shell
pyjudge hack test.py --gen gen.py --spj spj.py
```

## 编译与运行参数

支持 `C/C++,python`。

> 暂未实现修改编译参数的功能。

- C++ 编译器 `'g++'`
- C++ 编译参数 `'-std=c++20','-O2','-DONLINE_JUDGE'`
- C 编译器 `'gcc'`
- C 编译参数 `'-std=c11','-O2','-DONLINE_JUDGE'`
- python 解释器 `'python'`