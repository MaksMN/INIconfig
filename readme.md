Чтение данных из ini файла
```ini
; комментарий
# комментарий 
[Section1]
; комментарий
var1=значение_11 ;комментарий
var2=значение_12
[Section2]
var1=значение_21
```
Использование:
```cpp
auto var = getConfigValue("conf.ini", "Section2", "var1");
```