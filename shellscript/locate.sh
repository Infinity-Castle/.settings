read -p "Enter file name: " filename

locate "$filename" 2>/dev/null

echo "finding using find"

find / -name "$filename" 2>/dev/null