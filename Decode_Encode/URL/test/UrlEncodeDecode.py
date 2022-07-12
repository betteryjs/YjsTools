from urllib import parse
import requests

# requests.utils.quote(url)




a= "你好"
res=parse.quote(a)
print(res)
res2=a.encode("utf-8")
print(res2)
print(res2.__len__())
for i in res2:
    print(i,"  ",hex(i))
