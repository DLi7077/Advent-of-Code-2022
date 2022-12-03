import string 
def common(s1,s2,s3):
    z=0
    for char in s3:
        if(s2.count(char)>0 and s1.count(char)>0):
            if(ord(char)>=97 and ord(char)<=122):
                z = (ord(char)-96)
            elif(ord(char)>=65 and ord(char)<=90):
                z = (ord(char)-38)
            return z

with open('./input.txt','r') as f:
    lines = f.readlines()
    sum1,sum2,i,s=0,0,0,''
    for line in lines:
        s1 = list(string.ascii_uppercase) + list(string.ascii_lowercase)
        s2,s3 = line[:int(len(line)/2)],line[int(len(line)/2):]
        sum1 += common(s1,s2,s3) #Part-1
    for i in range(0,int(len(lines)/3)):
        l = lines[(3*i):(3*(i+1))]
        sum2 += common(l[0],l[1],l[2]) #Part-2
print(sum1,sum2)