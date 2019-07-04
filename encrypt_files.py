"""
This script encrypts (using the Caesar Cypher) the content of all the files in a 
directory (it includes its subdirectories) and saves the encrypted files
in a destination directory. It needs two parameters:
- The original directory from which it has to read the files
- The destination directory, where the original directory will be "copied".

author: Andrea Esposito
"""

import os
import sys
from colorama import init, Fore, Style


def encrypt(original_text, encryption_key):
    result = ""
    for i in range(len(original_text)):
        result += chr(ord(original_text[i]) + encryption_key)
    return result


init()
if len(sys.argv) < 2:
    print(Fore.RED + "ERROR: two parameters required!" +
          Style.RESET_ALL + " Read the documentation:")
    print(__doc__.strip())
else:
    root = sys.argv[1]
    dest = sys.argv[2]
    key = 5

    for path, subdirectories, files in os.walk(root):
        for name in files:
            data = open(os.path.join(path, name), "r")
            text = data.readlines()
            text = [x.strip() for x in text]
            if not os.path.exists(os.path.join(dest, os.path.join(path))):
                os.makedirs(os.path.join(dest, os.path.join(path)))
            encrypted = open(os.path.join(dest, os.path.join(path, name)), "w")
            for line in text[:-1]:
                encrypted.write(encrypt(line, key) + "\n")
            encrypted.write(encrypt(text[-1], key))
            encrypted.close()
