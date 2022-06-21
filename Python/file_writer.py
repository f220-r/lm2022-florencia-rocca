import csv
import numpy as np


data = [0]
for i in range(1,64):
    data.append(data[i-1] + int(3300/64))

with open('Python/sgn.h','x') as f:
    writer = csv.writer(f)
    writer.writerow(data)