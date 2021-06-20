#!/bin/bash
#########################################################################
# File Name: build.sh
# Author: Edward.Tang
# mail:   @163.com
# Created Time: Mon 02 Nov 2020 08:19:32 AM UTC
#########################################################################

# 题目：求基站信号强度
# 第一行输入两个整数，表示矩阵长和宽
# 第二行输入基站数量，接下来依次输入基站坐标
# 第六行输入命令数量，借来下依次输入命令序列
# 增加基站命令：add x y， 往该位置放入一个基站，若该位置已有基站，不做任何操作。
# 减少基站命令：del x y， 该位置上下左右、对角的基站全部拆除。
# 基站信号，该基站位置上下左右、对角的信号强度为1（不包含基站位置本身），不同基站之间的信号可叠加
# 某个矩阵布局如下：
# 0 1 0 0 0 0
# 0 1 0 0 0 0
# 0 0 0 0 0 0
# 0 0 0 0 0 0
# 则信号总强度为11：
# 2 0 2 0 0 0
# 2 0 2 0 0 0
# 1 1 1 0 0 0
# 0 0 0 0 0 0

make && ./main <<EOF
4 6
3
2 2
3 3
4 4
3
del 3 5
add 1 2
del 4 4
EOF
