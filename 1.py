# nums=input().split()
# a=float(nums[0])
# b=float(nums[1])
# c=a/b
# print("%d/%.1f=%d"%(a ,c ,b))

#
# a=int(input())
# if a>=90 and a<=100:
#     print("gong xi ni kao le %d fen!"%a)
# elif (a>=0 and  a<90):
#     print("kao le X fen bie xie qi!!"%a)
# n = int(input())
# grades_m = []
# grades_f = []
# for i in range(n):
#     tmp = input().split()
#     if int(tmp[0]) == 1:
#         grades_m.append(int(tmp[1]))
#     elif int(tmp[0]) == 0:
#         grades_f.append(int(tmp[1]))
# # 在一行中依次输出全班的平均成绩、男生的平均成绩、女生的平均成绩。
# avg = str(round((sum(grades_f) + sum(grades_m)) / (len(grades_m) + len(grades_f)),1))
# avg_f = "X"
# avg_m = "X"
# if len(grades_m) != 0:
#     avg_m = str(round(sum(grades_m) / len(grades_m),1))
# if len(grades_f) != 0:
#     avg_f = str(round(sum(grades_f) / len(grades_f),1))
# print("%s %s %s"%(avg,avg_m,avg_f))



# input=input().split()
# a=float(input[0])
# b=float(input[1])
# c=str(a+b)
# c=c.split(".")[0]
# for i in range(len(c)):
#     print(c[i]+"\n")

#
# a=input().split()
# n=int(a[0])
# p=int(a[1])
# b=input().split()
# nums=[int(i) for i in b]
# nums.sort()
# i=0
# count=0
# j=len(nums)-1
# for i in range(len(nums)):
#     for j in range(0,i):
#         if(nums[i]+nums[j]>p and nums[i]+p>nums[j] and nums[j]+p>nums[i]):
#             count+=1
# print(count)


# int
# count = 0;
#
# int
# ans = 1;
#
# for (i=n;i >= 2;i--)
#     {
#         ans *= i;
# while (ans % 10 == 0) // 消除末尾的0
#     {
#         ans /= 10;
#
#     count + +;
#     }
#     if (ans >= 100000) // 只需保存末尾5位数字即可
#         ans %= 100000;
# }
#
# while (ans % 10 == 0) // 消除末尾的0
#     {
#         ans /= 10;
#
#     count + +;
#     }
# x=input().split()
# a=int(x[0])
# b=int(x[1])
# count=0
# ans=1
# for i in range(a,1,1):
#     ans*=i
#     while(ans%10==0):
#         ans//=100
#         count+=1
#     if(ans>100000):
#         ans%=100000
# while ans%10==0:
#     pass
#
#
# nums=[]
# nums.insert()
# nums.pop()
nums=[1,2,3,4,5,6,7]
k=3
n = len(nums)
k = k % n

for i in range(k):
    tmp = nums[-1]
    nums.pop(-1)
    nums.insert(0, tmp)
print(nums)
enumerate