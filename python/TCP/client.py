import socket

PORT = 8080
BUFFER_SIZE = 1024

def main():
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client_socket.connect(('127.0.0.1', PORT))

    message = b'Hello from client'
    client_socket.sendall(message)

    data = client_socket.recv(BUFFER_SIZE)
    print("Received message:", data.decode())

    client_socket.close()

if __name__ == "__main__":
    main()
