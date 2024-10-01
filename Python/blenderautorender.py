import subprocess
#import main as bar
import time
import sys

def checkLine(temp):
    temp = temp.decode("utf-8")
    if "Saved: '" in temp:
        
        return True
    else:
        return False

def display_time(seconds, granularity=2):
    result = []
    intervals = (
        ('days', 86400),    # 60 * 60 * 24
        ('hours', 3600),    # 60 * 60
        ('minutes', 60),
        ('seconds', 1),
    )
    for name, count in intervals:
        value = seconds // count
        if value:
            seconds -= value * count
            if value == 1:
                name = name.rstrip('s')
            result.append("{} {}".format(value, name))
    return ', '.join(result[:granularity])


def ArenderCommand(outputFolder, filenameX, start, end):
    #print("Rendering with parms (Output Folder: {}, Blender File: {}, Frame Start: {}, Frame End: {}".format(outputFolder, filenameX, start, end))
    #bar.updateStatus("Wating For Render To Start")
    print("YEEEETAAA")
    time.sleep(2)
    print("YEEEET")
    #bar.updateStatus("Starting Render")


def renderCommand(outputFolder, filenameX, start, end):
    t0 = time.time()
    print(outputFolder.replace("/", "\\") + "render_#####")
    #blenderLocation = bar.recallBlenderProgram
    proc = subprocess.Popen(['G:/main_gaming/steamapps/common/Blender/blender.exe','-b',filenameX,'-s',start,'-e',end, '-o', outputFolder.replace("/", "\\") + "\\render_#####", '-a'],stdout=subprocess.PIPE)
    imagesSaved = 0
    print("RENDERING FILE")
    for line in iter(proc.stdout.readline,''):
        #print(line.rstrip())
        callback = checkLine(line.rstrip())
        if callback == True:
            imagesSaved += 1
            progressPercent = int(imagesSaved)/int(end)
            print("PE|" + str(progressPercent))
            comms = "{}/{} images saved. ".format(imagesSaved, str(int(end)-(int(start)-1)))
            print("SM|" + "Rendering: {}".format(comms))
        #print('Saved:' in line.rstrip())
        if line.rstrip() == b'Blender quit':
            t1 = time.time()
            totalrendertime = "Total Render Time: " + str(t1-t0)
            print("SM|" + "Render Finished - " + display_time(t1-t0))
            return
            
            
        #if "Saved: '" in line.rstrip():
        #    imagesSaved += 1
        #    print(imagesSaved)
        #    print(end)

outputFolder = sys.argv[1]
filename = sys.argv[2]
startFile = sys.argv[3]
endFile = sys.argv[4]


renderCommand(outputFolder, filename, startFile, endFile)
