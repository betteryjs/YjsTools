import base64

res=base64.b64encode("你好".encode('utf-8')).decode()
print(res)
print(type(res))