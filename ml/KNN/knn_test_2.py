import matplotlib
import matplotlib.pyplot as plt
from numpy import *
import operator

def file2trix(filename):
  fr = open(filename)
  numberOfLines = len(fr.readlines())
  returnMat = zeros((numberOfLines,3))
  classLabelVector = []
  fr = open(filename)
  index = 0
  for line in fr.readlines():
    line = line.strip()
    listFromLine = line.split(',')
    returnMat[index,:] = listFromLine[0:3]
    classLabelVector.append(int(listFromLine[-1]))
    index += 1
  return returnMat,classLabelVector

if __name__ == '__main__':
	datingDataMat,datingLabels = file2trix('test_data_2.txt')
	fig = plt.figure()
	ax = fig.add_subplot(111)
	ax.scatter(datingDataMat[:,1],datingDataMat[:,2],15*array(datingLabels),15*array(datingLabels))#size and color
	plt.show()