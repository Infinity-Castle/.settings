#!/bin/bash

read -p "Enter the name of the file: " filename

# Generate the word frequency list
cat "$filename" |
    tr '[:upper:]' '[:lower:]' |
    tr -c '[:alnum:]' '[\n*]' |
    grep -v '^$' |
    sort |
    uniq -c |
    sort -nr |
    awk '{print $2 ": " $1}' |
    head -n 20














#     cat "$filename": Reads the contents of the file specified by the filename variable and outputs it to the standard output.
# tr '\[:upper:\]' '\[:lower:\]': Translates all uppercase letters to lowercase using the tr command.
# tr -c '\[:alnum:\]' '\[\\n\*\]': Replaces all non-alphanumeric characters (except newlines) with spaces using tr. This effectively separates words by spaces.
# grep -v '^$': Removes any empty lines from the output using grep -v (invert match).
# sort: Sorts the lines in alphabetical order.
# uniq -c: Counts the occurrences of each unique line and prefixes the count to each line.
# sort -nr: Sorts the lines numerically in reverse order, putting the most frequent words first.
# awk '{print $2 ": " $1}': Using awk, it prints the second field (the word) followed by a colon and the first field (the count).
# head -n 20: Prints only the first 20 lines of the output, showing the top 20 most frequent words in the file.