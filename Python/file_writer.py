import csv
import numpy as np


data = []
data = np.random.randint(0,3300,size=64)
data.sort()

with open('Python/sgn.h','x') as f:
    writer = csv.writer(f)
    writer.writerow(data)