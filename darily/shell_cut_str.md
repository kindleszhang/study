> http://c.biancheng.net/view/1120.html

最后，我们对以上 8 种格式做一个汇总，请看下表：
|格式	|说明 |
|:--|:---|
|${string: start :length} |	从 string 字符串的左边第 start 个字符开始，向右截取 length 个字符。
|${string: start}|	从 string 字符串的左边第 start 个字符开始截取，直到最后。
|${string: 0-start :length}	|从 string 字符串的右边第 start 个字符开始，向右截取 length 个字符。
|${string: 0-start}|	从 string 字符串的右边第 start 个字符开始截取，直到最后。
|${string#*chars} |	从 string 字符串第一次出现 *chars 的位置开始，截取 *chars 右边的所有字符。
|${string##*chars}|	从 string 字符串最后一次出现 *chars 的位置开始，截取 *chars 右边的所有字符。
|${string%*chars}|	从 string 字符串第一次出现 *chars 的位置开始，截取 *chars 左边的所有字符。
|${string%%*chars} |	从 string 字符串最后一次出现 *chars 的位置开始，截取 *chars 左边的所有字符。