import matplotlib.pyplot as plt

def read_coordinates(output):
    with open(output, 'r') as file:
        lines = file.readlines()
    
    # Read and clean the coordinates from the file
    coordinates = []
    for line in lines:
        # Strip parentheses and split by commas
        line = line.strip().strip('()')
        x, y = map(float, line.split(','))
        coordinates.append((x, y))
    
    return coordinates

def plot_coordinates(coordinates):
    if len(coordinates) < 3:
        raise ValueError("Not enough points to plot. Expected at least 3 points.")
    
    # Extract B, A, and R
    B = coordinates[0]
    A = coordinates[1]
    R = coordinates[2]
    
    # Calculate limits for the plot
    all_x = [x for x, y in coordinates]
    all_y = [y for x, y in coordinates]
    
    margin = 1  # Add some margin around the plot
    plt.xlim(min(all_x) - margin, max(all_x) + margin)
    plt.ylim(min(all_y) - margin, max(all_y) + margin)
    
    # Plot the line AB
    plt.plot([B[0], A[0]], [B[1], A[1]], 'b-', label='Line AB')
    
    # Plot the points and add labels
    plt.plot(*B, 'bo')  # Point B
    plt.text(B[0], B[1], f'B ({B[0]:.2f}, {B[1]:.2f})', fontsize=12, color='blue', verticalalignment='bottom')
    
    plt.plot(*A, 'go')  # Point A
    plt.text(A[0], A[1], f'A ({A[0]:.2f}, {A[1]:.2f})', fontsize=12, color='green', verticalalignment='bottom')
    
    plt.plot(*R, 'ro')  # Point R
    plt.text(R[0], R[1], f'R ({R[0]:.2f}, {R[1]:.2f})', fontsize=12, color='red', verticalalignment='bottom')

    # Add labels and title
    plt.xlabel('X')
    plt.ylabel('Y')
    plt.title('Line AB with Point R')
    plt.legend()
    plt.grid(True)
    plt.savefig('../plots/plot.png', format='png', bbox_inches='tight')
    plt.close()

if __name__ == "__main__":
    # Read coordinates from the file
    coordinates = read_coordinates("output")
    
    # Plot the coordinates
    plot_coordinates(coordinates)

