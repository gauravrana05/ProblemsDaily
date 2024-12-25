from pprint import pprint 
import psycopg2

def operations(conn):
    cur = conn.cursor()
    query = "select * from student"
    cur.execute(query)
    result = cur.fetchall()
    # pprint(result)
    
    for i in result:
      print(i)
    conn.commit()
    if conn is not None:
      conn.close()
  

def connect_db(dbname, username, password, address, portnum):
  conn = None 
  try:
    conn = psycopg2.connect(database = dbname, user = username, password = password, host= address, port=portnum)
    operations(conn)
    print("Database connected successfully")
    
  except Exception as e:
    print(e)
  finally:
    conn.close()
    
connect_db("dummy", "postgres", "0000", "127.0.0.1", "5432")


    
  
    