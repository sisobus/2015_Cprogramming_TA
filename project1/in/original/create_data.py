#!/usr/bin/python
#-*- coding:utf-8 -*-
import glob
import sys

if __name__ == '__main__':
    filenames = glob.glob('*.in')
    data_id = 1
    for filename in filenames:
        with open(filename,'r') as fp:
            lines = fp.read().rstrip().split('\n')
        W,H = map(int,lines[0].split())
        N = 0
        boxs = []
        for i in xrange(2,len(lines)):
            n,w,h = map(int,lines[i].split())
            N = N + n
            for j in xrange(n):
                boxs.append((w,h))
        with open('../%d.in'%data_id,'w') as fp:
            fp.write('%d %d %d\n'%(W,H,N))
            for box in boxs:
                fp.write('%d %d\n'%(box[0],box[1]))
        data_id = data_id + 1 
