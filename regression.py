import numpy as np 
import matplotlib.pyplot as plt 
def estimate_coef(x, y): 
	# number of observations/points 
	n = np.size(x) 
	# mean of x and y vector 
	m_x, m_y = np.mean(x), np.mean(y) 
	# calculating cross-deviation and deviation about x 
	SS_xy = np.sum(y*x) - n*m_y*m_x 
	SS_xx = np.sum(x*x) - n*m_x*m_x 
	# calculating regression coefficients 
	b_1 = SS_xy / SS_xx 
	b_0 = m_y - b_1*m_x 
	return(b_0, b_1) 
def plot_regression_line(x, y, b): 
	# plotting the actual points as scatter plot 
	plt.scatter(x, y, color = "m", 
			marker = "o", s = 30) 
	# predicted response vector 
	y_pred = b[0] + b[1]*x 
	# plotting the regression line 
	plt.plot(x, y_pred, color = "g") 
	# putting labels 
	plt.xlabel('x') 
	plt.ylabel('y') 
	# function to show plot 
	plt.show() 
 # observations
import pandas as pd
e=[3, 3, 3, 4, 5, 3, 2, 1, 3,3] 
da=pd.DataFrame(e)
w=list(da.quantile([0.75])[0])
w1=list(da.quantile([0.25])[0])
q=(w[0]+1.5*(w[0]-w1[0]))
q=float(q)
q1=(w1[0]-1.5*(w[0]-w1[0]))
q1=float(q1)
g1=[i for i in e if(i>=q1 and i<=q)]
x1=np.array(list(range(1,len(g1)+1)))
#for i in g:
#    if i in e:
#        e.pop(e.index(i))
x = np.array(g1)
f=[1, 3, 2, 5, 7, 8, 8, 9, 10, 62] 
da=pd.DataFrame(f)
w=list(da.quantile([0.75])[0])
w1=list(da.quantile([0.25])[0])
q=w[0]+1.5*(w[0]-w1[0])
q1=w1[0]-1.5*(w[0]-w1[0])
g=[i for i in f if(i>q1 and i<q)]
#for i in g:
#    if i in f:
#        f.pop(f.index(i))
y = np.array(g) 
y1=np.array(list(range(1,len(g)+1)))
# estimating coefficients 
b = estimate_coef(y1, y)
c = estimate_coef(x1, x) 
print("Estimated coefficients: 2 is slope ",b[0], b[1]) 
print("Estimated coefficients: 2 is slope ",c[0], c[1]) 
# plotting regression line 
plot_regression_line(y1, y, b)  
plot_regression_line(x1, x, c) 
if c[1]<1.225 and c[1]>-1.225:
    print("constant")
if c[1]>=1.225:
    print("Backward")
if c[1]<-1.225:
    print("Forward")
#a1=[i for i in g if(i<np.median(ar)+2*np.std(ar))]
#a1=[i for i in v if(i>(da.quantile([0.75])+da.quantile([0.75]+1.5*(da.quantile([0.75]-da.quantile([0.25]))))))]