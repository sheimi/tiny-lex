MyLex - My Tiny Lexical Analyzer
=======================
简介
---
MyLex是一个用C++实现的简单的词法解析器。用户可以通过在一个.mylex文件中，根据相应的格式，定义正则表达式(Regular Expresision)以及相应的Handler处理程序，MyLex就会根据这个文件，生成相应的Scanner的C代码，编译后就可以得到对应程序。

目标
---
用C++实现一个简单的词法解析器，使它可以根据相应的规则生成相应的Sannner，然后对规则所对应的文件进行扫瞄，打印出相应的Token序列。

实现的方法
--------
1. 解析.mylex文件，获取相应的正则表达式，相应的Priority(排列书序)和对应的Handler程序，假设由N个正则表达式。
2. 根据这些正则表达式生成一个包含N个NFA的列表。
3. 把这些NFA组合成一个大的NFA
4. 由NFA生成一个对应的DFA
5. 最小化DFA
6. 由最小化的DFA生成相应的C Code

重要的数据结构的描述
-----------------
1. set，使用的使STL中的set，底层是RB-tree
2. map，使用STL中的map，底层是RB-tree
3. vector，使用STL中的vector
4. stack，使用STL中的stack
5. queue，使用STL中的queue
6. NState，NFA中的状态，[detail](../include/nfa.h)
7. NStateFrag，在组合NFA中的中间的小状态机，[detail](../include/nfa.h)
8. DState，NFA转换为DFA时候的中间的作为中间数据传递的中间状态，[detail](../include/nfa.h)
9. NFA，表示相应的NFA，[detail](../include/nfa.h)
10. DFAState，在DFA中储存的状态，[detail](../include/dfa.h)
11. DFA，表示相应的DFA，[detail](../include/dfa.h)

12. RegexEntry，表示.mylex文件中的一个块，相应的regex，handle，priority，[detail](../include/file_parser.h)



重要算法描述
----------
1. 后缀表达式的转换，使用一个Stack
2. 后缀表达式转换为NFA，算法参考[Regular Expression Matching Can Be Simple And Fast ](http://swtch.com/~rsc/regexp/regexp1.html)，[detail](../src/nfa.cpp)
3. NFA转换为DFA，[detail1](../src/nfa.cpp)，[detail2](../src/dfa.cpp)
4. DFA最小化，[detail](../src/dfa.cpp)

代码相关
-------

### 文件结构
    
    - mylex
        |- src/       相应的源文件
        |- lib/       错误处理的程序
        |- include/   头文件
        |- Makefile

### 编译的注意事项

1. OS: Linux , Unix or Mac OS
2. Compiler: g++ or clang
3. Lib: [Boost](http://www.boost.org/)

### 产生的C程序的编译事项
1. Compiler: gcc or clang
2. OS: Linux , Unix or Mac OS
3. *注意：C使用了C99的语法（'//'注释），没有不支持C99语法的编译器如VC6.0是不可以用的*

### 编译程序

    For Debug
        make DEBUG=1
    
    Not For Debug
        make

### 使用

	./mylex c_lex.mylex > c_lex.c
	make c_lex
	

.mylex文件格式
-------------
*注：由于时间有限，没有按照标准的lex文件格式来解析，于是使用了一个方便的，简单的自己定义的格式，方便解析*

File Format

    [N] the number of entries
    [Entry]
    [Entry]
    ...
    
Entry Format

    [Regex]
    [Handler] with the param (shm_str)
    ========= (at least 4 '=')

* Sample: [../sample/c_lex.mylex](../sample/c_lex.mylex)，C的部分词法
* Sample Input: [../sample/sample.c](../sample/sample.c)
* Sample Output: [../sample/sample.out](../sample/sample.out)

    
参考资料
-------
* NFA构造方法：[Regular Expression Matching Can Be Simple And Fast ](http://swtch.com/~rsc/regexp/regexp1.html)





