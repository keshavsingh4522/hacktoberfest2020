def cleanData(text):
    # Here is a list of punctuations and uninteresting to process your text
    punctuations = '''!()-[]{};:'"\,<>./?@#$%^&*_~'''
    uninteresting_words = ["the", "a", "to", "if", "is", "it", "of", "and", "or", "an", "as", "i", "me", "my", "for"\
    "we", "our", "ours", "you", "your", "yours", "he", "she", "him", "his", "her", "hers", "its", "they", "them", \
    "their", "what", "which", "who", "whom", "this", "that", "am", "are", "was", "were", "be", "been", "being", \
    "have", "has", "had", "do", "does", "did", "but", "at", "by", "with", "from", "here", "when", "where", "how", \
    "all", "any", "both", "each", "few", "more", "some", "such", "no", "nor", "too", "very", "can", "will", "just"]

    list_words=text.split()
    new_list=[]

    for content in list_words:
        for i in punctuations:
            if i in content:
                x=content.replace(i,"")
                new_list.append(x)
            else:
                if content not in new_list:
                    new_list.append(content)

    for content in list_words:
        for i in punctuations:
            if i in content:
                new_list.remove(content)

    for word_new in new_list:
        if word_new in uninteresting_words:
            new_list.remove(word_new)

    word_freequency={}
    for word in new_list:
        if word not in word_freequency:
            word_freequency[word]=0
        word_freequency[word]+=1 

    return word_freequency

myText = input("Enter the text: ")
print(cleanData(myText))