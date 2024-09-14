import sys                                          #for path to external scripts
sys.path.insert(0, '/Users/hanumac/Desktop/github/matgeo/codes/coordgeo')        #path to my scripts
import numpy as np
import numpy.linalg as LA
import matplotlib.pyplot as plt
import matplotlib.image as mpimg

#local imports
from line.funcs import *
from triangle.funcs import *
from conics.funcs import circ_gen


def read_points(output):
    with open(output, 'r') as f:
        line = f.readline().strip()
        line = line.strip("()")
        x, y = map(float, line.split(','))
    return x, y

x, y = read_points('output')


vector = read_points("output")

x,y = vector[0] , vector[1]

A = np.array(([0,0])).reshape(-1,1)
B = np.array(([x,y])).reshape(-1,1)

#generating line of vector
x_BC = line_gen(A,B)

#plotting the vector (line actually)

plt.plot(x_BC[0,:],x_BC[1,:],label='unit vector')

#trying to make it look like a vector
plt.plot(x, y, 'ro')  
plt.text(x, y, r"$( \frac{\sqrt{3}}{2}, \frac{1}{2} )$", color='red', fontsize=12, verticalalignment='bottom')

plt.xlim(-1, 5)
plt.ylim(-1, 5)

plt.xlabel('$X$')
plt.ylabel('$Y$')
plt.legend(loc='best')
plt.grid(True) # minor
plt.axis('equal')
plt.title('Unit vector at $30^{\degree}$ from $x$-axis')

plt.xticks(np.arange(-1, 3, 1))
plt.yticks(np.arange(-1, 3, 1))



plt.savefig('../plots/plot.png', format='png', bbox_inches='tight')
plt.close()
