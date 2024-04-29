import socket

# Create a UDP socket
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

server_address = ('localhost', 12345)
message = 'Hello, server!'

try:
    # Send data
    sent = sock.sendto(message.encode(), server_address)

    # Receive response
    data, server = sock.recvfrom(4096)
    print(f'Received {len(data)} bytes from {server}: {data.decode()}')

finally:
    print('Closing socket')
    sock.close()
