import subprocess
cmd='powershell "gps | where {$_.MainWindowTitle } |select ProcessName'
proc = subprocess.Popen(cmd,shell=True,stdout=subprocess.PIPE)
current_apps=[]
for line in proc.stdout:
    if(line.rstrip()):
        current_apps.append(line.decode().rstrip())

current_apps=current_apps[2:]
