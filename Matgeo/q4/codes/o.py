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


def read_altitudes(path):
    with open(path, 'r') as file:
        data = file.readlines()
        altitude1 = float(data[0].strip())
        altitude2 = float(data[1].strip())
    return altitude1, altitude2


def main():
    path = 'output.txt'

    altitude1, altitude2 = read_altitudes(path)
    tri_plot(altitude1,altitude2)

if __name__ == "__main__":
    main()
