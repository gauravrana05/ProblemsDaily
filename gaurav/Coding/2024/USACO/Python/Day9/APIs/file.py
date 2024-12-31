import pandas as pd
from pprint import pprint
import matplotlib.pyplot as plt
dict_={'a':[11,21,31],'b':[12,22,32]}
df = pd.DataFrame(dict_)
print(df)
pprint(df.mean())