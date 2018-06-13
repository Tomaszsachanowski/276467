import matplotlib.pyplot as plt
import csv

x=[]
y= []
z= []
with open('Res_append.txt','r') as csvfile:
    plots=csv.reader(csvfile, delimiter=' ')
    for row in plots:
        y.append(int(row[0]))
        x.append(int(row[1]))
        z.append(int(row[2]))

plt.plot(y,x,label='WEKTOR')
plt.plot(y,z,label='LISTA')

plt.xlabel('x')
plt.ylabel('time[ns]')
plt.title('Res_append')
plt.legend()
plt.show()


x=[]
y= []
z= []
with open('Res_popFirst.txt','r') as csvfile:
    plots=csv.reader(csvfile, delimiter=' ')
    for row in plots:
        y.append(int(row[0]))
        x.append(int(row[1]))
        z.append(int(row[2]))

plt.plot(y,x,label='WEKTOR')
plt.plot(y,z,label='LISTA')

plt.xlabel('x')
plt.ylabel('time[ns]')
plt.title('Res_popFirst')
plt.legend()
plt.show()



x=[]
y= []
z= []
with open('Res_popLast.txt','r') as csvfile:
    plots=csv.reader(csvfile, delimiter=' ')
    for row in plots:
        y.append(int(row[0]))
        x.append(int(row[1]))
        z.append(int(row[2]))

plt.plot(y,x,label='WEKTOR')
plt.plot(y,z,label='LISTA')

plt.xlabel('x')
plt.ylabel('time[ns]')
plt.title('Res_popLast')
plt.legend()
plt.show()


x=[]
y= []
z= []
with open('Res_prepend.txt','r') as csvfile:
    plots=csv.reader(csvfile, delimiter=' ')
    for row in plots:
        y.append(int(row[0]))
        x.append(int(row[1]))
        z.append(int(row[2]))

plt.plot(y,x,label='WEKTOR')
plt.plot(y,z,label='LISTA')

plt.xlabel('x')
plt.ylabel('time[ns]')
plt.title('Res_prepend')
plt.legend()
plt.show()
