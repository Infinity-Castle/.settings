import socket

PORT = 8080
BUFFER_SIZE = 1024

def main():
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind(('127.0.0.1', PORT))
    server_socket.listen(5)

    print("Server listening on port", PORT)

    conn, addr = server_socket.accept()
    print('Connected by', addr)

    while True:
        data = conn.recv(BUFFER_SIZE)
        if not data:
            break
        print("Received message:", data.decode())
        conn.sendall(b'Hello from server')

    conn.close()

if __name__ == "__main__":
    main()
































# Server:
# python
# Copy code
# import socket
# Importing the socket module to create and manage network connections.
# python
# Copy code
# PORT = 8080
# BUFFER_SIZE = 1024
# Defining constants for the server port number and the buffer size for receiving data.
# python
# Copy code
# def main():
# Defining the main function where the server logic will reside.
# python
# Copy code
#     server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
# Creating a new socket object for the server. socket.AF_INET specifies the address family (IPv4), and socket.SOCK_STREAM specifies the socket type (TCP).
# python
# Copy code
#     server_socket.bind(('127.0.0.1', PORT))
# Binding the socket to the localhost (127.0.0.1) and the specified port number.
# python
# Copy code
#     server_socket.listen(5)
# Putting the socket in listening mode to accept incoming connections. The argument 5 specifies the maximum number of queued connections.
# python
# Copy code
#     print("Server listening on port", PORT)
# Printing a message indicating that the server is listening on the specified port.
# python
# Copy code
#     conn, addr = server_socket.accept()
# Accepting a new connection. accept() blocks until a connection is established, then returns a new socket object (conn) representing the connection and the address (addr) of the client.
# python
# Copy code
#     print('Connected by', addr)
# Printing the address of the connected client.
# python
# Copy code
#     while True:
# Starting an infinite loop to continuously receive data from the client.
# python
# Copy code
#         data = conn.recv(BUFFER_SIZE)
# Receiving data from the client. recv() blocks until data is received or the connection is closed. The received data is stored in the data variable.
# python
# Copy code
#         if not data:
#             break
# Checking if the received data is empty. If so, it indicates that the client has closed the connection, so we break out of the loop.
# python
# Copy code
#         print("Received message:", data.decode())
# Printing the received message after decoding it from bytes to a string.
# python
# Copy code
#         conn.sendall(b'Hello from server')
# Sending a response message to the client. sendall() sends the entire message at once. The b prefix before the string indicates that it should be encoded as bytes.
# python
# Copy code
#     conn.close()
# Closing the connection with the client.
# python
# Copy code
# if __name__ == "__main__":
#     main()
# Checking if the script is being run directly as the main program. If so, it calls the main() function to start the server.
# Client:
# python
# Copy code
# import socket
# Importing the socket module.
# python
# Copy code
# PORT = 8080
# BUFFER_SIZE = 1024
# Defining constants for the server port number and the buffer size for receiving data.
# python
# Copy code
# def main():
# Defining the main function where the client logic will reside.
# python
# Copy code
#     client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
# Creating a new socket object for the client, similar to the server.
# python
# Copy code
#     client_socket.connect(('127.0.0.1', PORT))
# Establishing a connection to the server by specifying the server's address (localhost) and port number.
# python
# Copy code
#     message = b'Hello from client'
# Defining the message to be sent to the server. The b prefix indicates that it should be encoded as bytes.
# python
# Copy code
#     client_socket.sendall(message)
# Sending the message to the server using sendall().
# python
# Copy code
#     data = client_socket.recv(BUFFER_SIZE)
# Receiving the response from the server using recv(). This blocks until data is received or the connection is closed. The received data is stored in the data variable.
# python
# Copy code
#     print("Received message:", data.decode())
# Printing the received message after decoding it from bytes to a string.
# python
# Copy code
#     client_socket.close()
# Closing the connection with the server.
# python
# Copy code
# if __name__ == "__main__":
#     main()
# Checking if the script is being run directly as the main program. If so, it calls the main() function to start the client.