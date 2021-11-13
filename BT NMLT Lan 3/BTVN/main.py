import os
import shutil

origin='F:\\1 - Hoc tap\\BT NMLT Lan 3\\BTVN'

os.chdir(origin)

list=os.listdir()
if ('21127334' in list):
    shutil.rmtree('21127334')
os.mkdir('21127334')

if ('21127334.zip' in list):
    os.remove('21127334.zip')

list=os.listdir()
for x in list:
    if x!='21127334' and x!='main.py':
        string1= './'+x+'/main.cpp'
        string2='./21127334/'+x+'.cpp'
        shutil.copyfile(string1,string2)

shutil.make_archive('./21127334', 'zip', './','21127334')