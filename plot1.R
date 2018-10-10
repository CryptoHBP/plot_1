library(ggplot2)

result <- read.table("C:\\Users\\mayle\\Documents\\plot_1-master\\Graficos.txt",header = F)
result = unlist(result)

i = j = 1
x = y1 = y2 = rep(0, length(result)/3)

while(i<=length(result)){
  x[j] = result[i]
  y1[j] = result[i+1]
  y2[j] = result[i+2]
  i = i + 3
  j = j + 1
}

dat1 <- data.frame(
  Number = x,
  PQUEUE = y1,
  HEAP = y2
)

p <- qplot(ylab = "Number of comparations", xlab = "Elements") +
  ggtitle("Priority Queue without Heap vs Priority Queue with Heap") + 
  theme(plot.title = element_text(size=18, face="bold",hjust=0.5)) +
  geom_line(data = dat1, aes(x = Number, y = PQUEUE), size = 1, color = '#ce0606') + 
  geom_point(data = dat1, aes(x = Number, y = PQUEUE), size = 2, color = '#ce0606') + 
  geom_line(data = dat1, aes(x = Number, y = HEAP), size = 1, color = '#003366') + 
  geom_point(data = dat1, aes(x = Number, y = HEAP), size = 2, color = '#003366')

print(p)