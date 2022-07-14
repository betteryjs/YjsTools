import base64


inputs="你好阿公司的公司的告别赛公司的公司的个"
res=base64.b64encode(inputs.encode('utf-8')).decode()
print(res)
print(type(res)) # 5L2g5aW9
