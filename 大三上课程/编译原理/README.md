# 编译原理课程资料

本目录收录编译原理课程的课件、课后作业与参考答案、历年试题及课程实验。主要内容涵盖编译器结构、编程语言基础、词法分析、语法分析、语义规则、中间代码生成、运行时环境和机器无关优化。

## 目录概览

```text
编译原理/
├── 课件/                  # 课程讲义，共 9 份 PDF 和 1 份 PPTX
├── 作业及参考答案/         # 课堂练习、6 次书面作业及综合参考答案
├── 往年试题/
│   ├── 期中试题/           # 不同学年的期中试题
│   └── 期末试题/           # 不同学年的期末试题与整理文档
└── 课程实验/
    ├── Course Projects.pdf
    └── project/
        ├── XL_Scanner/     # C++ 词法分析器
        └── LR_1_based_Parser/ # C++ LR(1) 语法分析器
```

## 课件

| 文件 | 主要内容 |
| --- | --- |
| [Chapter0.pdf](<课件/Chapter0.pdf>) | 课程导论、教学安排与参考资料 |
| [chapter1.pdf](<课件/chapter1.pdf>) | 编译器概述，包括编译器的作用、结构与基本工作流程 |
| [chapter2.pdf](<课件/chapter2.pdf>) | 编程语言基础，包括静态与动态概念、作用域、运行环境和参数传递 |
| [chapter3.pptx](<课件/chapter3.pptx>) | 词法分析基础，包括 Token、模式、词素及词法错误 |
| [CP3-2.pdf](<课件/CP3-2.pdf>) | 词法分析器的原理与实现 |
| [chapter4.pdf](<课件/chapter4.pdf>) | 语法分析及语法分析器的作用 |
| [CP5-1.pdf](<课件/CP5-1.pdf>) | 语义规则、语法制导定义与属性计算 |
| [CP5-2.pdf](<课件/CP5-2.pdf>) | 中间代码生成 |
| [CP6.pdf](<课件/CP6.pdf>) | 运行时环境、过程活动与数据对象管理 |
| [CP7.pdf](<课件/CP7.pdf>) | 机器无关代码优化 |

## 作业及参考答案

该目录包含两组课后练习、六次书面作业和一份综合参考答案：

- [1.exercises after first class.pdf](<作业及参考答案/1.exercises after first class.pdf>)
- [Exercises after class-2.pdf](<作业及参考答案/Exercises after class-2.pdf>)
- [Written assignment 1.pdf](<作业及参考答案/Written assignment 1.pdf>)
- [Written assignment 2.pdf](<作业及参考答案/Written assignment 2.pdf>)
- [Written assignment 3.pdf](<作业及参考答案/Written assignment 3.pdf>)
- [Written assignment 4.pdf](<作业及参考答案/Written assignment 4.pdf>)
- [Written assignment 5.pdf](<作业及参考答案/Written assignment 5.pdf>)
- [Written assignment 6.pdf](<作业及参考答案/Written assignment 6.pdf>)
- [编译原理参考答案.pdf](<作业及参考答案/编译原理参考答案.pdf>)

## 课程实验

[Course Projects.pdf](<课程实验/Course Projects.pdf>) 说明了两项课程实验：词法分析器实现和语法分析器实现。目录中保存了以下两个 C++ 项目。

### XL_Scanner

基于 C++ 实现的词法分析器，可识别关键字、标识符、整数、运算符和分隔符，并输出相应的 Token 信息。

| 文件 | 内容 |
| --- | --- |
| [LexicalAnalyzer.cpp](<课程实验/project/XL_Scanner/LexicalAnalyzer.cpp>) | 词法分析器源代码 |
| [实验报告](<课程实验/project/XL_Scanner/71122135-Pengyu Xie-XL_Scanner-Report.pdf>) | XL_Scanner 的设计、实现与测试说明 |
| `test1.txt`—`test4.txt` | 4 组测试输入 |
| `result1.txt`—`result4.txt` | 对应的 4 组分析结果 |

### LR_1_based_Parser

基于 C++ 实现的 LR(1) 语法分析器，通过 ACTION、GOTO 表和文法产生式完成移进、归约与接受过程。

| 文件 | 内容 |
| --- | --- |
| [SyntaxParser.cpp](<课程实验/project/LR_1_based_Parser/SyntaxParser.cpp>) | LR(1) 语法分析器源代码 |
| [实验报告](<课程实验/project/LR_1_based_Parser/71122135-Pengyu Xie-LR_1_based_Parser-Report.pdf>) | 语法分析器的设计、实现与测试说明 |
| `test1.txt`—`test2.txt` | 2 组测试输入 |
| `result1.txt`—`result2.txt` | 对应的 2 组分析结果 |

## 往年试题与复习资料

### 复习材料

- [编译原理复习资料_基本概念.pdf](<往年试题/编译原理复习资料_基本概念.pdf>)：基本概念汇总。
- [2014《编译原理》期末复习资料（完整版）.pdf](<往年试题/2014《编译原理》期末复习资料(完整版).pdf>)：期末复习资料。
- [UCB-2024-CS164_FA24_final_sol.pdf](<往年试题/UCB-2024-CS164_FA24_final_sol.pdf>)：UC Berkeley CS 164 课程 2024 年秋季期末试题及解答，可用于拓展练习。

### 期中试题

共 10 份，包括 2007—2008、2015—2020 等学年的试题及 2024 年测试题：

- [test_mid_2024.pdf](<往年试题/期中试题/test_mid_2024.pdf>)
- [期中-19-20.pdf](<往年试题/期中试题/期中-19-20.pdf>)
- [期中-18-19.pdf](<往年试题/期中试题/期中-18-19.pdf>)
- [期中-17-18.pdf](<往年试题/期中试题/期中-17-18.pdf>)
- [期中-16-17.pdf](<往年试题/期中试题/期中-16-17.pdf>)
- [期中-15-16.pdf](<往年试题/期中试题/期中-15-16.pdf>)
- [期中-07-08-软件.pdf](<往年试题/期中试题/期中-07-08-软件.pdf>)
- [期中-07-08-计科.pdf](<往年试题/期中试题/期中-07-08-计科.pdf>)
- [期中-不知哪一年.pdf](<往年试题/期中试题/期中-不知哪一年.pdf>)
- [期中-不知哪一年2.pdf](<往年试题/期中试题/期中-不知哪一年2.pdf>)

### 期末试题

共 8 份，包含软件工程和计算机科学与技术专业的历年试题，以及按题型整合的复习文档：

- [31-71（按题型整合）.docx](<往年试题/期末试题/31-71（按题型整合）.docx>)
- [17-18-软件.pdf](<往年试题/期末试题/17-18-软件.pdf>)
- [16-17-2期末.pdf](<往年试题/期末试题/16-17-2期末.pdf>)
- [16-17-2-软件.doc](<往年试题/期末试题/16-17-2-软件.doc>)
- [13-14-2-计科.pdf](<往年试题/期末试题/13-14-2-计科.pdf>)
- [11-12-计科.pdf](<往年试题/期末试题/11-12-计科.pdf>)
- [08-09-2-软件.doc](<往年试题/期末试题/08-09-2-软件.doc>)
- [08-09-2-计科.doc](<往年试题/期末试题/08-09-2-计科.doc>)

## 建议

1. 阅读 `Chapter0`—`chapter2`，理解编译器结构和编程语言基础。
2. 学习 `chapter3` 与 `CP3-2`，随后完成或阅读 `XL_Scanner` 词法分析实验。
3. 学习 `chapter4`，随后完成或阅读 `LR_1_based_Parser` 语法分析实验。
4. 继续学习 `CP5-1`、`CP5-2`、`CP6` 和 `CP7`，掌握编译器后续阶段。
5. 结合书面作业巩固各章内容，再使用历年期中、期末试题进行综合练习。
6. 需要注意的是，期中期末这些固定题型在 25-26 已经发生了变化，据了解 26-27 再次变化，建议在刷题基础上多加复习课本知识，以及 LL(1) 和 LR(1) 这些考试时大概率没有平时作业那种二三十个状态那么多，但是要注意一些细节部分。
