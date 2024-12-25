from pprint import pprint 
import numpy as np

a  = np.array([1,2,3,4,4])

aa = [[11, 12, 13], [21, 22, 23], [31, 32, 33]]
pprint(aa)
A = np.array(aa)
pprint(A.ndim)
pprint(A.shape)
pprint(A.size)
pprint(A[1,2])
pprint(A[1][2])