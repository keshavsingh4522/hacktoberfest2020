import sys
import subprocess
import shutil


if len(sys.argv) > 1:
    s3path = sys.argv[1]
else:
    print("Please Provide S3 Path for Dir to zip")
    sys.exit()

if s3path.endswith("/"):
    dir_name = s3path.split("/")[-2]
else:
    dir_name = s3path.split("/")[-1]

download_dir = f"/bin/aws s3 cp {s3path} ./{dir_name} --recursive"
print(download_dir)
proc = subprocess.Popen(download_dir, shell=True, stdout=subprocess.PIPE)
script_response = proc.stdout.read()

out_name = dir_name+"_zp"
shutil.make_archive(out_name, 'zip', f"./{dir_name}")

if s3path.endswith("/"):
    upload_zp = f"aws s3 cp ./{out_name}.zip {s3path}{out_name}.zip"
    print(upload_zp)
    proc = subprocess.Popen(upload_zp, shell=True, stdout=subprocess.PIPE)
    script_response = proc.stdout.read()
else:
    upload_zp = f"aws s3 cp ./{out_name}.zip {s3path}/{out_name}.zip"
    print(upload_zp)
    proc = subprocess.Popen(upload_zp, shell=True, stdout=subprocess.PIPE)
    script_response = proc.stdout.read()

# Try to remove tree
try:
    shutil.rmtree(f"./{dir_name}")
except OSError as e:
    print ("Error: %s - %s." % (e.filename, e.strerror))