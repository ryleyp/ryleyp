# This is tcpclient.py file

import socket
import hashlib
import finalproject

# create a socket object
clientsocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM) 

# get local machine name
host = "localhost"

# set destination port
port = 12000

# connection to hostname on the port.
clientsocket.connect((host, port))

# send message. The string needs to be converted to bytes.
publickey = clientsocket.recv(1024)
publickey = publickey.decode()

#input and send last name
last = input('input last name: ')
encryptedlast = finalproject.knapsackEncrypt(last, publickey)
clientsocket.send(encryptedlast.encode())

#input and send first name
first = input('input first name: ')
encryptedfirst = finalproject.knapsackEncrypt(first, publickey)
clientsocket.send(encryptedfirst.encode())

#input and send major
major = input('input major name: ')
encryptedmajor = finalproject.knapsackEncrypt(major, publickey)
clientsocket.send(encryptedmajor.encode())

#input and send username
username = input('input username: ')
encryptedusername = finalproject.knapsackEncrypt(username, publickey)
clientsocket.send(encryptedusername.encode())

#input password, hash, and send 
password = input('input password: ')
password = password.encode('utf8')
hash_obj = hashlib.sha256(password)
password_hash = hash_obj.hexdigest()
encryptedpassword = finalproject.knapsackEncrypt(password_hash, publickey)
clientsocket.send(encryptedpassword.encode())

publickey = clientsocket.recv(1024)
publickey = publickey.decode()


# Receive no more than 1024 bytes
msg = clientsocket.recv(1024)
print("received: " + msg.decode())

# Close connection
clientsocket.close()

