import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
from matplotlib.ticker import MultipleLocator

# plot the sin ans cos
x = np.arange(-3*np.pi, 3*np.pi, 0.1)
y = np.sin(x)
plt.plot(x, y)
plt.title('sinx')
plt.show()
y = np.cos(x)
plt.plot(x, y)
plt.title('cosx')
plt.show()

# plot ob 
x = np.random.randint(20, size=20)
y = np.random.randint(20, size=20)
plt.scatter(x, y)
plt.show()

# plot histogram
x = np.random.uniform(0, 1, 20)
plt.pie(x)
plt.show()

# plot bar
x = np.random.randint(20, size=20)
y = np.random.randint(20, size=20)
plt.bar(x, y, align='center')
plt.show()

# plot more in single figure
x = np.arange(-3*np.pi, 3*np.pi, 0.1)
y_sinx = np.sin(x)
plt.subplot(2, 1, 1)
plt.plot(x, y_sinx)
plt.title('sinx')
y_cosx = np.cos(x)
plt.subplot(2, 1, 2)
plt.plot(x, y_cosx)
plt.title('cosx')
plt.show()

# plot more figure e.g
x = np.arange(-3*np.pi, 3*np.pi, 0.1)
y_sinx = np.sin(x)
plt.plot(x, y_sinx)
y_cosx = np.cos(x)
plt.plot(x, y_cosx)
plt.show()

# plot 3d
from mpl_toolkits.mplot3d import axes3d
plt.rcParams['font.sans-serif'] = ['SimHei']  # 步骤一（替换sans-serif字体）
plt.rcParams['axes.unicode_minus'] = False  # 解决坐标轴负号的显示问题
n = 1000
x, y = np.meshgrid(np.linspace(-3, 3, n),
                   np.linspace(-3, 3, n))
z = (1 - x / 2 + x ** 5 + y ** 3) * np.exp(-x ** 2 - y ** 2)

plt.figure('三维平面图', facecolor='lightgray')
plt.title('三维平面图', fontsize=18)
plt.grid(linestyle=':')

ax = plt.gca(projection='3d')
ax.set_xlabel('X', fontsize=12)
ax.set_ylabel('Y', fontsize=12)
ax.set_zlabel('Z', fontsize=12)
plt.tick_params(labelsize=8)

# value of v is to set color of figure
v = np.sqrt(x ** 2 + y ** 2 + z ** 2)
ax.plot_surface(x, y, z, rstride=30, cstride=30, cmap='jet')

plt.show()