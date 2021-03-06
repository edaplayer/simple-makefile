#!/usr/bin/env python3
# -*- coding: UTF-8 -*-
# File: config.py
# Function: 同步两个内核配置文件
# Version: v1.0
# Author: Edward.Tang

import sys
import os
import re
import collections

def get_config(file):
    keymap = collections.OrderedDict()
    comment = collections.OrderedDict()
    text = collections.OrderedDict()

    try:
        with open(file, 'r', encoding='utf8', errors='ignore') as f:
            lines = f.readlines()
    except FileNotFoundError as e :
        print('Error: ' + file + "不存在")
        exit(1)

    for line in lines:
        data = line.strip()

        if len(data) <= 0:
            continue

        if data[0] != '#': # 键值项
            if '=' in data:
                item = data.split('=')
                key = item[0].strip()
                keymap[key] = item[1].strip()
        else: # 注释项
            if 'is not' in data:
                item = data.strip('#').split('is not')
                key = item[0].strip()
                comment[key] = item[1].strip()

        text[key] = line

    return keymap, comment, text

def sync_config_fast(src, dst):
    k1, c1, t1 = get_config(src)
    k2, c2, t2 = get_config(dst)

    with open(dst, 'r') as f:
        kernelconfig = f.read()
        tempdata = kernelconfig

    for key in k1:
        if not key in k2 and not key in c2:
            tempdata += key + '=' + k1[key] +'\n'
        elif (key in k2 and k1[key] != k2[key]) or (key in c2) :
            tempdata = tempdata.replace(t2[key], key + '=' + k1[key] + '\n')

    #  注释键值
    for key in c1:
        if key in k2:
            tempdata = tempdata.replace(t2[key], t1[key].strip() + '\n')

    if tempdata != kernelconfig:
        with open(dst, 'w') as f:
            f.write(tempdata)

def main():
    if len(sys.argv) == 3:
        newconfig = sys.argv[1] #新配置
        oldconfig = sys.argv[2]    #原始配置文件路径
        sync_config_fast(newconfig, oldconfig)
    else:
        print("Need two arguments, please check arguments.")

if __name__ == '__main__':
    main()

