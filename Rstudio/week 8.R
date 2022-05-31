install.packages("dplyr")
a=read.csv("C:\\Users\\kelvin\\Downloads\\first.csv")
b=read.csv("C:\\Users\\kelvin\\Downloads\\second.csv")
a
subset(a,SCORE>50)
class(a)
subset(a,SCORE>50,select=c(NAME,SEM))
sema1=subset(a,SEM==1)
sema2=subset(b,SEM==1)
c=rbind(sema1,sema2)
c
write.csv(c,"C:\\Users\\kelvin\\Downloads\\third.csv")

sample_n(a,3)
sample_frac(a,1)
sample_frac(a,.5)
sample_frac(a,.1)

select(a,"NAME")
subset(a,name)
select(a,-"NAME")

filter(a,SEM==1 & SCORE>50)
summarize(a,a)
summarise(a,total=sum(SCORE))
summarise(a,total=sum(SCORE),AVG=mean(SCORE))
mutate(a,SCORE=SCORE*7%)
mutate(a,grace_mark=SCORE+5)
mutate(a,total_grace_mark=SCORE+SCORE*0,10)


arrange(a,desc(NAME))

sample_frac(a,0.5) %>% select("SCORE") #50%
sample_frac(a,1) %>% select("SCORE")        
sample_frac(a,0.5) %>% select("SCORE")

sample_frac(a,0.5) %>% select("SCORE") %>% summarise(sum(SCORE))
sample_frac(a,1) %>% select(SEM,SCORE) %>% group_by(SEM) %>% summarise(sum(SCORE))
