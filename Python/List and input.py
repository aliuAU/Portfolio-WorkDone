lst=[]
def fun1(x):
    global lst
    if x==0:
        return
    else:
        lst=[x%10] + lst
        fun1(x//10)
        
        
def fun2(lst,y):
    if len(lst)%2==0:
     if mx in lst:
        a=lst.index(mx)
        lst[a]=y
        fun2(lst,y)
     else:
        print(lst)
    else:
        lst=[y]*len(lst)+lst
        print(lst)

a,b=eval(input("Enter a number and a digit:"))
fun1(a)
print("List is ", lst)
mx=max(lst)
fun2(lst,b)
