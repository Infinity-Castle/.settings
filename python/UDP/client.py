import socket

# Create a UDP socket
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# Bind the socket to a specific address and port
server_address = ('localhost', 12345)
sock.bind(server_address)

print('Server started. Waiting for messages...')

while True:
    data, address = sock.recvfrom(4096)  # Receive data from client
    print(f'Received {len(data)} bytes from {address}: {data.decode()}')
    
    if data:
        sent = sock.sendto(data, address)  # Send the same data back to the client
        print(f'Sent {sent} bytes back to {address}')
























# Now, let's briefly explain each part of the code:

# Server Side:
# The server creates a UDP socket using socket.socket().
# It binds the socket to a specific address and port using sock.bind().
# It enters an infinite loop to continuously receive messages from clients using sock.recvfrom().
# Upon receiving a message, it prints out the message and sends the same message back to the client using sock.sendto().
# Client Side:
# The client creates a UDP socket using socket.socket().
# It specifies the server address and the message to send.
# It sends the message to the server using sock.sendto().
# It waits to receive a response from the server using sock.recvfrom().
# Upon receiving the response, it prints out the message.
# Both the server and client use the socket.AF_INET address family for IPv4 and the socket.SOCK_DGRAM socket type for UDP communication. They communicate over the loopback interface (localhost) on port 12345.