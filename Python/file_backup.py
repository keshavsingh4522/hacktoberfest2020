import os
import shutil
import datetime
import schedule
import time

source_dir = r''
destination_dir = r''

def copy_folder_to_directory(source, dest):
    today = datetime.date.today()
    dest_dir = os.path.join(dest,str(today))

    try:
        shutil.copytree(source, dest_dir)
        print(f'Folder Copied To: {dest_dir}')
    except FileExistsError:
        print(f'Folder Already exists in: {dest}')
    except Exception as e:
        print(f'Error copying folder: {e}')

schedule.every().day.at("10:30").do(lambda: copy_folder_to_directory, source_dir, destination_dir)

while True:
    schedule.run_pending()
    time.sleep(60)