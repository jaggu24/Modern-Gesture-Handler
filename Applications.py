import subprocess
cmd='powershell "gps | where {$_.MainWindowTitle } |select ProcessName'
proc = subprocess.Popen(cmd,shell=True,stdout=subprocess.PIPE)
for line in proc.stdout:
    if(line.rstrip()):
        print(line.decode().rstrip())
