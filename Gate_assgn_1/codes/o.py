import matplotlib.pyplot as plt

def read_points(output):
    with open(output, 'r') as file:
        lines = file.readlines()



#Reading the coordinates of the points from the files
    line1 = lines[0].strip().strip('()')
    B_x, B_y = map(float, line1.split(','))

    line2 = lines[1].strip().strip('()')
    A_x, A_y = map(float, line2.split(','))

    line3 = lines[2].strip().strip('()')
    R_x, R_y = map(float, line3.split(','))

    return [[B_x, B_y], [A_x, A_y], [R_x, R_y]]

def plot_coordinates(coordinates):
    B_x, B_y = coordinates[0][0], coordinates[0][1]
    A_x, A_y = coordinates[1][0], coordinates[1][1]
    R_x, R_y = coordinates[2][0], coordinates[2][1]

    #making limits for the plot
    all_x = [B_x, A_x, R_x]
    all_y = [B_y, A_y, R_y]

    margin =1 

    #line plot
    plt.plot([B_x, A_x], [B_y, A_y], 'b-', label='Line $AB$')

    
    #Points plot
    plt.plot(B_x, B_y, 'bo')  
    plt.text(B_x, B_y, f'$B$ ({B_x:.2f}, {B_y:.2f})', color='magenta')
    
    plt.plot(A_x, A_y, 'go')  
    plt.text(A_x, A_y, f'$A$ ({A_x:.2f}, {A_y:.2f})', color='green')
    
    plt.plot(R_x, R_y, 'ro')  
    plt.text(R_x, R_y, f'$R$ ({R_x:.2f}, {R_y:.2f})', color='red')


    plt.xlabel('$X$')
    plt.ylabel('$Y$')
    plt.title('Line $AB$ with Point $R$')
    plt.legend()
    plt.grid(True)
    plt.savefig('../plots/plot.png', format='png', bbox_inches='tight')
    plt.close()

if __name__ == "__main__":
    #fetching coordinates from the file
    coordinates = read_points("output")
    
    
    #final plot
    plot_coordinates(coordinates)

