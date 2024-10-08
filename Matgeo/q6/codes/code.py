import sys  # for path to external scripts
sys.path.insert(0, '/Users/hanumac/Desktop/github/matgeo/codes/coordgeo')  # path to my scripts
import numpy as np
import numpy.linalg as LA
import matplotlib.pyplot as plt

# local imports
from line.funcs import *
from triangle.funcs import *
from conics.funcs import circ_gen

# Load the points from the text file generated by the C code
points = np.loadtxt("points.txt", delimiter=',')

# Extract the x and y coordinates
x = points[:, 0]
y = points[:, 1]


#line parameters
A = np.array([-2,0]).reshape(-1,1)
B = np.array([1,0]).reshape(-1,1)
m = np.array([0,1]).reshape(-1,1)

#POI
P = np.array([-2,4]).reshape(-1,1)
Q = np.array([1,1]).reshape(-1,1)

x_A = line_dir_pt(m,A,-1,10)
x_B = line_dir_pt(m,B, -1,10)

#plot starts
plt.figure()

# Plot the parabola
plt.plot(x, y, label=r'$y = x^2$', color='green', linewidth=1)

plt.gca().set_aspect('auto', adjustable='box')

#line
plt.plot(x_A[0, :], x_A[1, :], label="$x = -2$", color="purple", linestyle="--")
plt.plot(x_B[0, :], x_B[1, :], label="$x = 1$", color="red", linestyle="--")


#shading
x_fill = np.linspace(-2,1,500)
y_fill = x_fill ** 2

plt.fill_between(x_fill,y_fill, color = 'blue', alpha = 0.4, label = 'Required Region')


#labeling
tri_coords = np.block([[A,B,P,Q]])
plt.scatter(tri_coords[0, :], tri_coords[1, :], color='black')  # Plot points
vert_labels = ['$A$', '$B$', '$P$', '$Q$']

# Annotate the points using the provided syntax
for i, txt in enumerate(vert_labels):
    plt.annotate(f'{txt}\n({tri_coords[0,i]:.0f}, {tri_coords[1,i]:.0f})',
                 (tri_coords[0,i], tri_coords[1,i]),  # point to label
                 textcoords="offset points",  # position of text
                 xytext=(0, 10),  # distance from text to points (x,y)
                 ha='center')  # horizontal alignment

# Label the axes
plt.xlabel("x")
plt.ylabel("y")
plt.title("Parabola $y = x^2$ with shaded region")
plt.grid(True)
plt.legend()
plt.savefig("../plots/plot.png", format='png', bbox_inches='tight')
plt.show()


