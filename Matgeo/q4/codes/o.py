import sys                                          #for path to external scripts
sys.path.insert(0, '/Users/hanumac/Desktop/github/matgeo/codes/coordgeo')        #path to my scripts
import numpy as np
import numpy.linalg as LA
import matplotlib.pyplot as plt

#local imports
from line.funcs import *
from triangle.funcs import *
from conics.funcs import circ_gen

#For reading the values, defining a function
def read_values(filename):
    data = np.loadtxt(filename, delimiter=':', dtype=str)
    AB = float(data[0])
    BC = float(data[1])
    angleB = float(data[2])
    return AB, BC, angleB

#calling the function o read the values
AB, BC, angleB = read_values('output.txt')

#angle degrees to radians
angleB_rad = np.radians(angleB)

#assuming B to be origin
B = np.array([0,0])

#assuming BC to be on the x-axis
C = np.array([BC,0])

#finding A using trigonometry
A = np.array([AB * np.cos(angleB_rad), AB * np.sin(angleB_rad)])

#finding length of sides
a = LA.norm(B - C)  #BC
b = LA.norm(C - A)  #CA
c = LA.norm(A - B)  #AB


#start the plot
plt.figure()

#generating the lines
x_AB = line_gen(A,B)
x_BC = line_gen(B,C)
x_CA = line_gen(C,A)

#plotting lines
plt.plot(x_AB[0], x_AB[1], label='$AB$')
plt.plot(x_BC[0], x_BC[1], label='$BC$')
plt.plot(x_CA[0], x_CA[1], label='$CA$')

# Label the coordinates
plt.scatter([A[0], B[0], C[0]], [A[1], B[1], C[1]], color='red')
plt.text(A[0], A[1], 'A', fontsize=12, ha='right')
plt.text(B[0], B[1], 'B', fontsize=12, ha='right')
plt.text(C[0], C[1], 'C', fontsize=12, ha='right')


#making a legend
plt.legend([
    f'Side AB = {c:.2f} cm',  # Length AB
    f'Side BC = {a:.2f} cm',  # Length BC
    f'Side AC = {b:.2f} cm'   # Length AC
], loc='upper right')

# Labels and grid
plt.xlabel('$x$')
plt.ylabel('$y$')
plt.grid(True)
plt.axis('equal')

plt.savefig('../plots/plot.png', format='png', bbox_inches='tight')
plt.show()


