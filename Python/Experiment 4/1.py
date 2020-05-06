import numpy as np
import numpy.matlib

# create empty array 3X3 (int)
emptyArray = np.empty([3, 3], dtype=int)
print(emptyArray)

# create a 3X3 array contain all 0(int)
zerosArray = np.zeros([3, 3], dtype=int)
print(zerosArray)

# create a 3X3 eye
eyeArray = np.eye(3, dtype=int)
print(eyeArray)

# create a 3X3 array contain all 1(int)
onesArray = np.ones([3, 3], dtype=int)
print(onesArray)

# create a array by a list
byListArray1 = np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]])
print(byListArray1)

l = [1, 2, 3]
byListArray2 = np.asarray(l)
print(byListArray2)

# create array by range
rangeArray = np.arange(5, 15, 2, dtype=float)
print(rangeArray)

#linspace, and the logspace is equality so emit it
linspaceArray = np.linspace(5, 15, 10, dtype=float)
print(linspaceArray)
# and reshape the array
linspaceArray = np.linspace(5, 15, 10, dtype=float).reshape([10,1])
print(linspaceArray)

#slice in rangeArray
s = slice(2, 7, 2)
print(rangeArray[s])
#is equal to this
print(rangeArray[2:7:2])

#index in Ndarray
print(rangeArray[4])
print(byListArray1[2])
print(byListArray1[2][2])

#using ... to index
print(byListArray1[...,2])
print(byListArray1[2,...])

# example of the broadcast in Array add
print(byListArray1+byListArray2)

# create a 3X3 matrix in random element
Matrix = numpy.matlib.rand(3, 3)
print(Matrix)

# calculate the matrix's inv
print(np.linalg.inv(Matrix))

# calculate the average and for axis = 0/1 (column/raw)
print(np.mean(Matrix))
print(np.mean(Matrix, axis=0))
print(np.mean(Matrix, axis=1))

# sort the Ndarray by axis = 0/1(column/raw), and I do not use the dtype of align, so order is not used in there.
# kind is default to use 'quicksort'
print(np.sort(Matrix))
print(np.sort(Matrix, axis=0))
print(np.sort(Matrix, axis=1))

# calculate the DX and sqrt(DX) X = Matrix
# equal to mean(x-x.mean()**2)
print(np.std(Matrix))
print(np.var(Matrix))

# using the package function to create a normal
normal1 = np.random.normal(size=100)
print(normal1)
mu = np.array([1, 5])
sigma = np.array([[10, 5], [5, 5]])
normal2 = np.random.multivariate_normal(mu, sigma, 1000)
print(normal2)

