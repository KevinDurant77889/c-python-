# -*- coding: utf-8 -*-
"""
Created on Thu Jul 18 15:31:49 2019

@author: 凱文˙杜蘭特
"""
def swap(arr,a,b):
    tmp = arr[a]
    arr[a] = arr[b]
    arr[b] = tmp
    return
    
def partition(arr, front, end):
    pivot = arr[end]
    i = front - 1
    j = front
    while(j < end):
        if arr[j] < pivot:
            i += 1
            swap(arr, i, j)
        j += 1
    i += 1
    swap(arr, i, end)
    return i
        
    
def quick_sort(arr, front, end):
    if front < end:
        pivot = partition(arr, front, end)
        quick_sort(arr, front, pivot - 1)
        quick_sort(arr, pivot+1, end)
    
import time
import random
import sys

num = 100000
sys.setrecursionlimit(1000000)
tStart = time.time()
container = []
for i in range(num):
    container.append(random.randint(1,99))

#test(container)
quick_sort(container,0, num-1)
tEnd = time.time()
print (tEnd - tStart)