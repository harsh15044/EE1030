import numpy as np
import matplotlib.pyplot as plt
import os

x = np.linspace(-2 * np.pi, 2 * np.pi, 1000)

y_A = np.sin(x) * np.sign(x)
y_B = np.sin(x)
y_C = np.abs(np.sin(x))
y_D = np.abs(np.cos(x))


figures = [('10a.png', y_A), ('10b.png', y_B), ('10c.png', y_C), ('10d.png', y_D)]

for filename, y in figures:
    plt.figure()
    plt.plot(x, y)
    plt.axhline(0, color='black', linewidth=0.5)
    plt.axvline(0, color='black', linewidth=0.5)
    plt.xticks([-2 * np.pi, -np.pi, 0, np.pi, 2 * np.pi],
               [r'$-2\pi$', r'$-\pi$', '0', r'$\pi$', r'$2\pi$'])
    plt.ylim(-1.5, 1.5) if 'a' in filename or 'b' in filename else plt.ylim(0, 1.2)
    
    output_dir = "../figs"
    
    plt.gca().spines['top'].set_visible(False)
    plt.gca().spines['right'].set_visible(False)
    
    plt.grid(True, linestyle='--', linewidth=0.5)  #grid lines
    plt.savefig(os.path.join(output_dir, filename))



