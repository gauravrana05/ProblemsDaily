import numpy as np

a = np.array([1, 2, 3, 4])
arr_2d = np.array([[1, 2, 3],
                    [4, 5, 6]])
print(a, a.ndim)
print(arr_2d, arr_2d.ndim)
zeros = np.zeros((2, 3))

arr = np.arange(0, 10, .2)
print(arr)
lspc = np.linspace(0,100, 20)
print(lspc)

arr = np.arange(200)
arr = arr.reshape(2,100)

arr = np.array([[1,2,3], [4,5,6], [7,8,9]])
print(arr)
print(arr[:1, 1:])
print(arr[1,:])
print(arr[:, 1])