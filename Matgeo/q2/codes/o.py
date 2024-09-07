import matplotlib.pyplot as plt

def read_points(output):
    with open(output, 'r') as file:
        lines = file.readlines()

    line1 = lines[0].strip().strip('()')
    Q_x, Q_y = map(float, line1.split(','))
    
    line2 = lines[1].strip().strip('()')
    R_x, R_y = map(float, line2.split(','))
    
    line3 = lines[2].strip().strip('()')
    P_x, P_y = map(float, line3.split(','))

   

    return [[Q_x, Q_y], [R_x, R_y], [P_x,P_y]]

def plot_coordinates(coordinates):
    Q_x, Q_y = coordinates[0][0], coordinates[0][1]
    R_x, R_y = coordinates[1][0], coordinates[1][1]
    P_x, P_y = coordinates[2][0], coordinates[2][1]

    #making limits for plot
    all_x = [Q_x, R_x, P_x]
    all_y = [Q_y, R_y, P_y]

    Cx=-17
    Cy=-7

    #line plot
    plt.plot([Q_x, R_x], [Q_y, R_y], 'b-', label='Line $QR$')
    plt.plot([P_x, Cx], [P_y, Cy],color='red', linestyle='dashed', label='Perpendicular Bisector'     )

    #Point plot

    plt.plot(Q_x, Q_y, 'bo')  
    plt.text(Q_x, Q_y, f'$Q$ ({Q_x:.2f}, {Q_y:.2f})', color='magenta')
    
    plt.plot(P_x, P_y, 'go')  
    plt.text(P_x, P_y, f'$P$ ({P_x:.2f}, {P_y:.2f})', color='green')
    
    plt.plot(R_x, R_y, 'ro')  
    plt.text(R_x, R_y, f'$R$ ({R_x:.2f}, {R_y:.2f})', color='red')
    plt.axis('equal')
    plt.xlabel('$X$')
    plt.ylabel('$Y$')
    plt.title('Line $QR$ with Point $P$')
    plt.legend()
    plt.grid(True)
    plt.savefig('../plots/plot.png', format='png', bbox_inches='tight')
    plt.close()


if __name__ == "__main__":
    #fetching coordinates from the file
    coordinates = read_points("output")
    
    
    #final plot
    plot_coordinates(coordinates)


    