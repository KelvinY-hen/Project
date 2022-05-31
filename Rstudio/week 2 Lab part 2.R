# Practice Questions


# Create a new R script as follows: Go to File->New File->R Script.

#Try variable assigning:
# i.  Define a new variable, "weeks", then assign 4 to it using the operator (<-).
      weeks<-4
      weeks
      
# ii. Define a new variable, "hoursPerWeek", then assign 40 to it using the operator (=).
      hoursperweek=40
      hoursperweek
      
# iii.Define a new variable, "hourlyRate", then assign 50 to it using assign function.
      assign ("hourlyrate",50)
      hourlyrate
      
# iv. Remove the variable "hourlyRate" and update with "HOURLYRATE"
      HOURLYRATE=hourlyrate
      rm (hourlyrate)
      
# v.  Convert weeks to datatype integer
      as.integer(weeks)
      
# vi. "bonuse" as integer and assign 1000 to it.
      bonuse=1000L
      
# vii. "tax" as numeric and assign 0.2 to it.
        tax=0.2
      
# viii. Calculate the gross salary(W X HPW X HR) and net salary(grossSal X (1-tax))
        gross_salary=weeks*hoursperweek*HOURLYRATE
        gross_salary        
        
        net_salary= gross_salary*(1-tax)        
        net_salary        
        