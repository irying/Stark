#this is make file
#destination:compose of files
ptree_main.out:ptree.o ptree_main.c
	gcc ptree.o ptree_main.c -o ptree_main.out
ptree.o:ptree.c
	gcc -c ptree.c
我们一般在领域层定义仓储接口，在基础设施层实现仓储，以隔离领域模型和数据模型。