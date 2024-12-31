from pprint import pprint 
import numpy as np
import pandas as pd
s = pd.Series([1,3,4,5,np.nan, 5])
# pprint(s)

dates = pd.date_range("20240916", periods= 6)
# pprint(dates)
df = pd.DataFrame(np.random.randn(6, 4),index = dates, columns = list("ABCD"))
# pprint(df)

dict_ = {
        "A": [1.0, 2.0, 3.0, 4.0, 2.0],
        "B": pd.Timestamp("20130102"),
        "C": pd.Series(1, index=list(range(5)), dtype="float32"),
        "D": np.array([3] * 5, dtype="int32"),
        "E": pd.Categorical(["test", "tim", "train", "test", "train"]),
        "F": "foo",
    }


# df = pd.DataFrame(dict_)
# df.sort_index(ascending=False)
# df.sort_values(by="A")

# pprint(df.loc[1:3 , ['A', 'B']])
# pprint(df[ df["A"] > 2])
# pprint(df[df > 0])
df2 = df.copy()

df2['E'] = ['one', 'two', 'three', 'four', 'five' , 'six']
# pprint(df2)
# pprint(df2[df2['E'].isin(["two", "three", "ten"])])

s1 = pd.Series([1,2,3,4,5,6], index = pd.date_range("20240916", periods= 6))
df["F"] = s1
df.at[dates[0], "A"] = 0
df.iat[0,1] = 1

df.loc[:, "D"] = np.array([5] * len(df))
# pprint(df)
df2 = df.copy()
df2[df2 <0] = -df2
# pprint(df2)

df1 = df.reindex(index=dates[0:4], columns=list(df.columns) + ["E"])
df1.loc[dates[0]: dates[1], "E"] = 1
# pprint(df1)
# pprint(pd.isna(df))
# pprint(df.mean(axis = 1))
# pprint(df)
s = pd.Series([1, 3, 5, np.nan, 6, 8], index=dates).shift(-2)

# pprint(df)
# df = df.sub(s, axis= "index")
# pprint(df)
# pprint(df.agg(lambda x: np.mean(x) * 5.6, axis= 1))
# pprint(df.transform(lambda x: x * 45))

s = pd.Series(np.random.randint(0, 7, size = 10))
# pprint(s.value_counts())
s = pd.Series(["A", "B", "23", "Aaba", "Baca", np.nan, "CABA", "dog", "cat"])
# pprint(s.str.lower())


# --Merge--
df = pd.DataFrame(np.random.randn(10, 4))
# pprint(df)
pieces = [df[:3], df[3:7], df[7:9]]
# pprint(pd.concat(pieces))

left = pd.DataFrame({"key": ['foo', 'foo'], "lval" :[1, 2]})
right = pd.DataFrame({"key" : ["foo", "foo"] , "rval" : [3, 4]})
# pprint(left)
# pprint(right)
# pprint(pd.merge(left, right, on = "key"))
df = pd.DataFrame(
    {
        "A": ["foo", "bar", "foo", "bar", "foo", "bar", "foo", "foo"],
        "B": ["one", "one", "two", "three", "two", "two", "one", "three"],
        "C": np.random.randn(8),
        "D": np.random.randn(8),
    }
)
pprint(df)