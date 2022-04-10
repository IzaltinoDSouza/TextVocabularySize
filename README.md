# TextVocabularySize

## Build
```bash
g++ main.cpp -o TextVocabularySize --std=c++20 -lfmt
```
## Dependence
[LibFmt Download](https://fmt.dev/latest/index.html)

```bash
sudo apt install libfmt-dev
```
## To use
```bash
./TextVocabularySize FILENAME.txt
```

#### [How Much Input Do You Need to Learn the Most Frequent 9,000 Words?](https://eric.ed.gov/?id=EJ1044345)

# Examplo : Harry Potter Books(1-7)

```bash
./TextVocabularySize HarryPotter1_7.txt
```

|Tokens|Types|Families|
|-------|----:|----|
|1123249|20642|7564|


| WordFamily  | Tokens |Tokens % | Families  |
| ----------- |:------:| -------:| --------: |
|1000|895418|79.72|993|
|2000|58863|5.24|959|
|3000|21209|1.89|812|
|4000|17695|1.58|717|
|5000|13771|1.23|672|
|6000|8627|0.77|593|
|7000|4393|0.39|489|
|8000|4037|0.36|462|
|9000|4821|0.43|412|
|10000|2918|0.26|352|
|11000|1657|0.15|260|
|12000|1216|0.11|241|
|13000|1107|0.10|163|
|14000|458|0.04|122|
|15000|778|0.07|99|
|16000|200|0.02|63|
|17000|352|0.03|67|
|18000|958|0.09|36|
|19000|73|0.01|28|
|20000|68|0.01|24|

# WordFamily 1000
| Family  | Frequency |
| ------- |:------:   |
|a|23746|
|able|527|
|about|2514|
|above|227|
|absolute|51|
|accept|82|
|across|557|
|act|200|
|actual|151|
|add|338|

# WordFamily 2000
| Family  | Frequency |
| ------- |:------:   |
|accent|2|
|access|12|
|accident|100|
|according|45|
|account|33|
|accuse|46|
|active|21|
|adapt|3|
|admire|55|
|adult|18|

# .
# .
# .


# WordFamily 20000
| Family  | Frequency |
| ------- |:------:   |
|aspidistra|1|
|balderdash|5|
|beribboned|1|
|booger|3|
|budgerigar|2|
|cribbage|1|
|dingbat|1|
|disarrange|1|
|fug|1|
|gobbledegook|4|
