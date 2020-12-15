import os
Import("env")

uploader = '$UPLOADER'
#local_dfu = ['dfu-util', 'dfu-util.exe']
#for dfu in local_dfu:
#    if os.path.exists(dfu):
#        uploader = './'+dfu

# DFU util to program the Maple Mini
env.Replace(
    UPLOADER='dfu-util',
    UPLOADCMD=uploader+' -d 1EAF:0003 -a 1 -D $SOURCE -R'
)
