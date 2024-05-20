#This function generates key
def generateKey(text, keyword):
    key = keyword
    while (len(key) < len(text)):
        key += keyword
    return key

#This function encrypts text
#using a key
def encrypt(cypher_text, keyword):
    key = generateKey(cypher_text, keyword)
    encr_text = ""
    for i in range(len(cypher_text)):
        symbol = ord(cypher_text[i]) + (ord(key[i]) - 32)
        if symbol > 126:
            symbol -= 126
            symbol += 31
        encr_text += chr(symbol)
    return encr_text

#This function decrypts text
#using a key
def decrypt(decr_text, keyword):
    key = generateKey(decr_text, keyword)
    orig_text = ""
    for i in range(len(decr_text)):
        symbol = ord(decr_text[i]) - (ord(key[i]) - 32)
        if symbol < 32:
            symbol -= 31
            symbol *= -1
            symbol -= 126
            symbol *= -1
        orig_text += chr(symbol)
    return orig_text


if __name__ == "__main__":
    print("Choose the variant:")
    print("(1) Encrypt text")
    print("(2) Decrypt text")
    option = int(input())
    if option == 1:
        print(f'Write a text to be encrypted:')
        orig_text = input()
        print(f'Write your key:')
        keyword = input()
        print(encrypt(orig_text, keyword))
    else:
        print(f'Write a text to be decrypted:')
        text = input()
        print(f'Write a key:')
        keyword = input()
        print(decrypt(text, keyword))