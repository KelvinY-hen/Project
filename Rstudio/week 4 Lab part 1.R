v1=1:8
v1
m1=matrix(v1)
m1
m1=matrix(1:8)
m1
m1=matrix(1:8,2,4)
m1
m1=matrix(1:8,2,4,TRUE)
m1
m1=matrix(data = v1,nrow=2,nco=4,byrow=TRUE, dimnames=list(c("r1","r2"),c("c1","c2",'c3',"c4")))
m1

m1=matrix(data=1:24,nrow=3,ncol=8,byrow=TRUE,dimnames=list(c('r1','r2','r3'),c("c1",'c2','c3','c4','c5','c6','c7','c8')))
m1
v1=1:8
m1=matrix(v1,2,4)
m2=matrix(10:17,2,4)
m1
m2
madd=m1+m2
madd
msubtract=m1-m2
msubtract
rbind=rbind(m1,m2)
rbind
cbind=cbind(m1,m2)
cbind

row_name=c("ROW1","ROW2","Row3")
col_name=c("COL1","COL2","COL3","COL4")
dim_name=c("Matrix1","Matrix2")
myarr=array(1:24,dim=c(3,4,2),dimnames=list(row_name,col_name,dim_name))
myarr

myarr[2,,2]
a
a=matrix(-3:5,3,3)
ifelse(x>0,x,0)
