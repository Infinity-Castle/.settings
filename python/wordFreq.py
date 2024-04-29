
def count_word_freq(file_name):
    wordFreq={}
    with open(file_name,'r') as file:
        for line in file:
            words=line.split()
            for word in words:
                word=word.lower()

                wordFreq[word]=wordFreq.get(word,0)+1
    return wordFreq

def main():
    file_name=input("Enter the name of the txt file: ")
    wordfreq=count_word_freq(file_name)

    print("word frequencies in the file: ")
    for word,freq in wordfreq.items():
        print(f"{word}: {freq}")

main()