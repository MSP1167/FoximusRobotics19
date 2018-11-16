import socket

UDP_IP = "127.0.0.1"
UDP_PORT = 50000
MESSAGE = "Hi Mom!"

print "UDP target IP:", UDP_IP
print "UDP target port:", UDP_PORT
print "message:", MESSAGE

GO = True

while GO == True:

    sock = socket.socket(socket.AF_INET, # Internet
                     socket.SOCK_DGRAM) # UDP
    sock.sendto(MESSAGE, (UDP_IP, UDP_PORT))