#!/bin/bash

# Define the named pipe file
FIFO_FILE="/tmp/my_fifo"

# Function to create the named pipe
create_fifo() {
    rm -f "$FIFO_FILE"
    # mkfifo as well
    mknod "$FIFO_FILE" p
    echo "Named pipe created: $FIFO_FILE"
}

# Function for the writer process
writer() {
    echo "Writer process started."
    echo "Hello from the writer!" > "$FIFO_FILE"
    echo "Writer process completed."
}

# Function for the reader process
reader() {
    echo "Reader process started."
    read -r message < "$FIFO_FILE"
    echo "Reader process received: $message"
    echo "Reader process completed."
}

# Create the named pipe
create_fifo

# Run the writer process as a background process
writer &

# Run the reader process
reader

# Clean up the named pipe
rm -f "$FIFO_FILE"
echo "Named pipe removed."