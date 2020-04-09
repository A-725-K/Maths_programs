import matplotlib.pyplot as plt


DATASET = 'dataset.txt'
HULL = 'hull.txt'


def readPoints(filename):
    with open(filename, 'r') as f:
        lst = []
        line = f.readline()
        while line:
            s = line.split(' ')
            lst.append((int(s[0]), int(s[1][:-1])))
            line = f.readline()

    return lst


dataset = readPoints(DATASET)
hull = readPoints(HULL)

xs = list(map(lambda x: x[0], dataset))
ys = list(map(lambda x: x[1], dataset))

n = len(hull)-1

colors = []
for p in dataset:
    if p in hull:
        colors += ['green']
    else:
        colors += ['blue']

plt.figure()
plt.scatter(xs, ys, c=colors)
for i in range(n):
    plt.plot([hull[i][0], hull[i+1][0]], [hull[i][1], hull[i+1][1]], color='red')
plt.plot([hull[0][0], hull[n][0]], [hull[0][1], hull[n][1]], color='red') # last line
plt.show()
