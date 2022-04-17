import socket

HOST = ""
PORT = 7070

print("server")
    
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind((HOST, PORT))
    s.listen(1)
    conn, addr = s.accept()

    with conn:
        print("connect", addr)
        while True:
            a
            
            