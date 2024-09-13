import numpy as np
import matplotlib.pyplot as plt

def read_points(output):
    with open(output, 'r') as f:
        line = f.readline().strip()
        line = line.strip("()")
        x, y = map(float, line.split(','))
    return x, y

x, y = read_points('output')


def plot_vector(coordinates):
    x,y = coordinates[0], coordinates[1]


    plt.plot([0, x], [0, y], 'r-', linewidth=2, label=f'Unit Vector')

    #trying to make it look like a vector
    plt.plot(x, y, 'ro')  
    plt.text(x, y, f'({x:.2f}, {y:.2f})', color='red', fontsize=12, verticalalignment='bottom')

    
    plt.xlim(-1, 5)
    plt.ylim(-1, 5)
    

    plt.axis('equal')   
    plt.xlabel('$X$')
    plt.ylabel('$Y$')
    plt.title('Unit vector at $30^{\degree}$ from $x$-axis')
    plt.legend()
    plt.grid(True)

    plt.xticks(np.arange(-1, 6, 1))
    plt.yticks(np.arange(-1, 6, 1))

    plt.savefig('../plots/plot.png', format='png', bbox_inches='tight')
    plt.close()


if __name__ == "__main__":
     #reading coordinates
    vector = read_points("output")
    
    # Plot the vector
    plot_vector(vector)
