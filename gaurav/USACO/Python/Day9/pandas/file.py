from pprint import pprint
import pandas as pd

'''
filename = "https://cf-courses-data.s3.us.cloud-object-storage.appdomain.cloud/IBMDeveloperSkillsNetwork-PY0101EN-SkillsNetwork/labs/Module%204/data/TopSellingAlbums.csv"
df.to_csv(output_csv_path, index=False)

xlsx_path = 'https://cf-courses-data.s3.us.cloud-object-storage.appdomain.cloud/IBMDeveloperSkillsNetwork-PY0101EN-SkillsNetwork/jupyterlite/files/Module%205/data/TopSellingAlbums.xlsx'
df.to_excel(output_xlsx_path, index=False, engine='openpyxl')
'''
xlsx_path = 'TopSellingAlbums.xlsx'
csv_path = 'TopSellingAlbums.csv'

csv = pd.read_csv(csv_path)
xlsx = pd.read_excel(xlsx_path)

x = xlsx[['Artist', 'Length', 'Genre']]
y = xlsx['Rating']
print(xlsx)
print(xlsx.loc[0,'Rating'])
print(xlsx.iloc[2:6, 4:7])
print(xlsx.loc[0:2, 'Artist':'Released'])