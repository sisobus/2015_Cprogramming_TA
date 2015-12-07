#!/usr/bin/python
#-*- coding:utf-8 -*-
with open('input','r') as fp:
    lines = fp.read().rstrip().split('\n')
a = []
for line in lines:
    a.append(int(line))
a = set(a)
print len(a)

with open('class_2','r') as fp:
    lines = fp.read().rstrip().split('\n')
b = []
for line in lines:
    if int(line) in a:
        b.append(int(line))
b.sort()
print len(b)
for bb in b:
    print bb
