### UrlDecode UrlEncode 原理



编码的原理可以表述为：
将需要转码的字符，按指定编码方式（默认使用UTF-8编码）转化为字节流，每个字节按16进制表示，并添加%组成一个percent编码。
例如：汉字 “你好”

- UTF-8字节流打印为：-28 -67 -96 -27 -91 -67
- 对应的16进制表示为：E4 BD A0 E5 A5 BD
- URLEncode编译后为：%E4%BD%A0%E5%A5%BD

```python
from urllib import parse
a= "你好"
res=parse.quote(a)
print(res)
res2=a.encode("utf-8")
print(res2)
print(res2.__len__())
for i in res2:
    print(i,"  ",hex(i))

```
```text
%E4%BD%A0%E5%A5%BD
b'\xe4\xbd\xa0\xe5\xa5\xbd'
6
228    0xe4
189    0xbd
160    0xa0
229    0xe5
165    0xa5
189    0xbd
```
