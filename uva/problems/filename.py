import os
import re


directory = "/home/shen/Core/ACM/uva/problems/"

def process_directory(root):
    for item in os.listdir(root):
        if os.path.isdir(item):
            print("is directory", item)
            process_directory(item)
        else:
            print(item, end=" ---> ")
            new_name = re.sub(r"UVa*", "", item)
            if(new_name != item):
                print(new_name)
                os.rename(item, new_name)
process_directory(directory)
