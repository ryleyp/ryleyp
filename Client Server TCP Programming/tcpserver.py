# This is tcpserver.py file
import socket                                         
import finalproject
import hashlib
import json
import sympy

publickey = []
# create a TCP/IP socket object
serversocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM) 

# get local machine name
host = "localhost"
print(host)

#set port number for this server
port = 12000                                           

# bind to the port
serversocket.bind((host, port))                                  

# Listen for incoming connections, queue up to 5 requests
serversocket.listen(5)                                           

while True:
   # wait for a connection
   print('waiting for a connection on port ' + str(port) + '\n')
   clientsocket,addr = serversocket.accept()
   print("client socket# is:", clientsocket)
   print("address is",  addr)

   print("Got a connection from " + str(addr))

   # Receive the data of 1024 bytes maximum. The received data is binary data.
   privatekey = [2, 3, 6, 13, 27, 52, 105, 209]
   m = 419
   n = 253

   publickey = finalproject.createpublic(privatekey, m, n)
   clientsocket.send(publickey.encode())
   
   #receive last name
   encryptedlast = clientsocket.recv(1024)
   encryptedlast = encryptedlast.decode()
   last = finalproject.knapsackDecrypt(encryptedlast, privatekey, m, n)

   #receive first name
   encryptedfirst = clientsocket.recv(1024)
   encryptedfirst = encryptedfirst.decode()
   first = finalproject.knapsackDecrypt(encryptedfirst, privatekey, m, n)

   #receive major
   encryptedmajor = clientsocket.recv(1024)
   encryptedmajor = encryptedmajor.decode()
   major = finalproject.knapsackDecrypt(encryptedmajor, privatekey, m, n)

   #receive username
   encryptedusername = clientsocket.recv(1024)
   encryptedusername = encryptedusername.decode()
   username = finalproject.knapsackDecrypt(encryptedusername, privatekey, m, n)
   
   #receive hashed password
   encryptedpassword = clientsocket.recv(1024)
   encryptedpassword = encryptedpassword.decode()
   password = finalproject.knapsackDecrypt(encryptedpassword, privatekey, m, n)

   #register person and print info for confirmation
   reg = finalproject.registration(last, first, major, username, password)
   print (reg)

   #write outputted dictionary to json_file
   with open('reg.json', 'w') as json_file:
      json.dump(reg,json_file)

   # Send a reply    
   msg = "regisration confirmed!" + "\n"
   clientsocket.send(msg.encode())

   clientsocket.close()
