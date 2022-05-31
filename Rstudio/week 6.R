
sample_data=read.csv("C:\\Users\\kelvin\\Downloads\\IRIS.csv",header=FALSE)
sample_data

#naminng colum
names(sample_data)=c("LEN_SEPAL","WID_SEPAL","LEN_PETAL","WID_PETAL","SPECIES")
sample_data

#view column
names(sample_data)

#how data stored
class(sample_data)

#view row of colum
sample_data$LEN_SEPAL


view(sample_data)

length(sample_data)
ncol(sample_data)
nrow(sample_data)

iris_species = factor(sample_data$SPECIES)

iris_species

nlevels(iris_species)

sample_data$WID_SEPAL
max(sample_data$WID_SEPAL)
min(sample_data$WID_SEPAL)
summary(sample_data$WID_SEPAL)

summary(sample_data)

sample_data[2,3] 2nd row and 3rd column value
sample_data[142,]
sample_data[48:64,]

#from colum
sample_data[sample_data$SPECIES=="Iris-versicolor",]
sample_data[sample_data$SPECIES>1.5,]

#from row
subset(sample_data,SPECIES=="Iris-virginica")[1:5,]

sample_data[sample_data$WID_SEPAL>4,]
nrow(sample_data[sample_data$WID_SEPAL>4,])
sample_data[(sample_data$WID_SEPAL>4) & (sample_data$WID_PETAL>0.3),]
