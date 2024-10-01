import MySQLdb

db = MySQLdb.connect(host= input("> Input the your host adress here: "),    
                     user=input("> Input your username here: "),         
                     passwd=input("> Input your password here"),  
                     db=input("> Input the name of your Database here: "))    
print("connection successful")

cur = db.cursor()

cur.execute(input("> Input the file you want to open in your Database"))

for row in cur.fetchall():
    print(row[0])
    