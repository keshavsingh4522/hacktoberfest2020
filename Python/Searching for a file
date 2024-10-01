from pathlib import Path
 
file_name = input("Filename: ")
folder = "."
folder_answer = input("Folder path (leave empty for the current folder): ")
if folder_answer:
    folder = folder_answer
 
for path in Path(folder).rglob(file_name):
    print(path.absolute())
