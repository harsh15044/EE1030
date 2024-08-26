import sys
sys.path.insert(0, '/Users/hanumac/Desktop/github/matgeo/codes/CoordGeo')
import numpy as np
import numpy.linalg as LA
import matplotlib.pyplot as plt
import matplotlib.image as mpimg


from line.funcs import *
#from triangle.funcs import *
#


#Given Points
A = np.array(([-4,0])).reshape(-1,1)
B = np.array(([0,6])).reshape(-1,1)

#ratio
n = 3

#point 
R = (A + n*B)/(1+n)

#Generating all lines
x_AB = line_gen(A,B)

#Plotting all lines
plt.plot(x_AB[0,:],x_AB[1,:], label='$AB$')


#labelling the coordinates
tri_coords = np.block([A,B,R])
plt.scatter(tri_coords[0,:], tri_coords[1,:])
vert_labels = ['A', 'B', 'R']
for i, txt in enumerate(vert_labels):
    plt.annotate(f'{txt}\n({tri_coords[0,i]:.1f}, {tri_coords[1,i]:.1f})',
                 (tri_coords[0,i], tri_coords[1,i]),
                 textcoords="offset points",
                 xytext=(20,-10),
                 ha='center')

plt.xlabel('$x$')
plt.xlabel('$y$')
plt.legend(loc='best')
plt.grid()
plt.axis('equal')


plt.savefig('/Users/hanumac/Desktop/Matrix_Theory/Gate_assgn_1/figs/fig.png')
