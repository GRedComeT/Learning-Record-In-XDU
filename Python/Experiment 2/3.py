import copy
import inspect
import sys
"""
def Sorted(B, key=None, reverse=True):
    ''' 选择排序 '''
    A = copy.deepcopy(B)
    if key is None:
        if reverse:
            for i in range(0, len(A)):
                for j in range(i+1, len(A)):
                    
                    if A[i] <= A[j]:
                        A[i], A[j] = A[j], A[i]
        else:
            for i in range(0, len(A)):
                for j in range(i+1, len(A)): 
                    if A[i] >= A[j]:
                        A[i], A[j] = A[j], A[i]
    else:
        if reverse:
            for i in range(0, len(A)):
                for j in range(i+1, len(A)):
                    if key(A[i]) <= key(A[j]):
                        A[i], A[j] = A[j], A[i]
        else:
            for i in range(0, len(A)):
                for j in range(i+1, len(A)):
                    if key(A[i]) >= key(A[j]):
                        A[i], A[j] = A[j], A[i]
    return A
"""

def quick_sort(A, start, end, key=None, reverse=True):
    if start >= end:
        return
    left = start
    right = end
    mid = A[left]
    if key is None:
        if reverse is True:
            while left < right:
                while left < right and A[right] >= mid:
                    right -= 1
                A[left] = A[right]
                while left < right and A[left] < mid:
                    left += 1
                A[right] = A[left]
            A[left] = mid
        else:
            while left < right:
                while left < right and A[right] < mid:
                    right -= 1
                A[left] = A[right]
                while left < right and A[left] >= mid:
                    left += 1
                A[right] = A[left]
            A[left] = mid
    elif inspect.isfunction(key):
        if reverse is True:
            while left < right:
                while left < right and key(A[right]) >= key(mid):
                    right -= 1
                A[left] = A[right]
                while left < right and key(A[left]) < key(mid):
                    left += 1
                A[right] = A[left]
            A[left] = mid
        else:
            while left < right:
                while left < right and key(A[right]) < key(mid):
                    right -= 1
                A[left] = A[right]
                while left < right and key(A[left]) >= key(mid):
                    left += 1
                A[right] = A[left]
            A[left] = mid
    else:
        sys.exit("key is not a callable object.")
    quick_sort(A, start, left-1, key, reverse)
    quick_sort(A, left+1, end, key, reverse)



def Sorted(B, key=None, reverse=True):
    '''quickly sort'''
    A = copy.deepcopy(B)
    quick_sort(A, 0, len(A)-1, key, reverse)
    return A

A = [2, 4, 1, 5]
print(Sorted(A, reverse=False))
A = [[2, 3], [5, 4], [4, 2]]
print(Sorted(A, key=lambda x:x[0], reverse=False))
print(Sorted(A, key=lambda x:x[1]))
Sorted(A, key=1)