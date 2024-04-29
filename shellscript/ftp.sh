#!/bin/bash

# FTP server URL
ftp_url="ftp://10.10.13.16"

# File to download
file_name="example.txt"

# Check if the file exists on the FTP server
ftp_exists=$(lftp -c "open '$ftp_url'; cls -1 '$file_name'")

if [ -n "$ftp_exists" ]; then
    # File exists, download it
    lftp -c "open '$ftp_url'; get '$file_name'"
    echo "File '$file_name' downloaded successfully."
else
    echo "Error: File '$file_name' does not exist on the FTP server."
fi



























# This line uses the lftp command-line FTP client to check if the file specified by $file_name exists on the FTP server specified by $ftp_url. The lftp command is executed with the -c option, which allows running multiple commands in a single invocation. The commands open '$ftp_url' and cls -1 '$file_name' are executed in sequence. The open command connects to the FTP server, and the cls -1 command lists the specified file (-1 means to return a non-empty output only if the file exists). The output of this command is captured and stored in the ftp_exists variable.

# This is an if statement that checks if the ftp_exists variable is non-empty (using the -n condition). If it is non-empty, it means that the file exists on the FTP server, and the script proceeds to download the file. The lftp command is used again, this time with the get command, which downloads the file specified by $file_name from the FTP server specified by $ftp_url. After the download is complete, a success message is printed using the echo command.
# If the ftp_exists variable is empty, it means that the file does not exist on the FTP server, and an error message is printed using the echo command in the else block.
