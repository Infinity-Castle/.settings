def display_pyramid(lines):
    terminal_width = 80  # Assume terminal width is 80 characters
    max_width = lines * 2 - 1  # Calculate maximum width of the pyramid
    padding = (terminal_width - max_width) // 2  # Calculate padding to center horizontally
    for i in range(1, lines + 1):
        spaces = " " * ((max_width - (2 * i - 1)) // 2)  # Calculate spaces to center the pyramid horizontally
        print(" " * padding + spaces + "*" * (2 * i - 1))

def main():
    lines = int(input("Enter the number of lines for the pyramid: "))
    display_pyramid(lines)

if __name__ == "__main__":
    main()
