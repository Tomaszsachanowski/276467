import matplotlib.pyplot as plt
import csv

x=[]
y= []
z= []
with open('testAppend.txt','r') as csvfile:
    plots=csv.reader(csvfile, delimiter=' ')
    for row in plots:
        y.append(int(row[0]))
        x.append(int(row[1]))
        z.append(int(row[2]))

plt.plot(y,x,label='HASH')
plt.plot(y,z,label='TREE')

plt.xlabel('x')
plt.ylabel('time[ns]')
plt.title('testAppend')
plt.legend()
plt.show()


x=[]
y= []
z= []
with open('testDeleting.txt','r') as csvfile:
    plots=csv.reader(csvfile, delimiter=' ')
    for row in plots:
        y.append(int(row[0]))
        x.append(int(row[1]))
        z.append(int(row[2]))

plt.plot(y,x,label='HASH')
plt.plot(y,z,label='TREE')

plt.xlabel('x')
plt.ylabel('time[ns]')
plt.title('testDeleting')
plt.legend()
plt.show()


