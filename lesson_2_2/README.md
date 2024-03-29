# Семинар 2-2

- [Семинар 2-2](#семинар-2-2)
    - [Контрольные вопросы](#контрольные-вопросы)
        - [Зачем нужны интеллектуальные указатели?](#зачем-нужны-интеллектуальные-указатели)
        - [Категории итераторов и их отличия](#категории-итераторов-и-их-отличия)
    - [Duration, timepoint, часы](#duration-timepoint-часы)

### Контрольные вопросы

##### Зачем нужны интеллектуальные указатели?

**Умный указатель** - это класс(обёртка над стандартным указателем), который упрощает работу с динамически выделенной памятью. 

Например, при генерации исключения достаточно сложно освободить всю память *ручками*, поэтому использование обычных указателей в сложных программах черевато утечками памяти. 

Умные указатели *освобождают динамически выделенную память автоматически*. Память будет очищена при вызове деструктора объекта класса умного указателя. 

Заключение:
    - Выделяя динамическую память при помощи статических объектов класса умного указателя получаем гарантию очистки памяти при выходе объекта умного указателя за область видимости

##### Категории итераторов и их отличия

Различия категорий итераторов отлично демонстрирует таблица, взятая из [статьи на хабр](https://habr.com/ru/post/122283/):

<table>
<tbody><tr>
<th colspan="4">Категория итератора</th>
<th>Характеристика</th>
<th>Валидное выражение</th>
</tr>
<tr>
<td colspan="4" rowspan="2">все категории</td>
<td>Может быть скопирован и создан по образу и подобию</td>
<td>X b(a);<br>
b = a;</td>
</tr>
<tr>
<td>Может быть увеличен на единицу</td>
<td>++a<br>
a++<br>
*a++</td>
</tr>
<tr>
<td rowspan="9">Random Access</td>
<td rowspan="5">Bidirectional</td>
<td rowspan="4">Forward</td>
<td rowspan="2">Input</td>
<td>Поддерживает сравнение на равенство/неравенство</td>
<td>a == b<br>
a != b</td>
</tr>
<tr>
<td>Может быть разыменован как <i>rvalue</i> только для <i>получения</i> значения</td>
<td>*a<br>
a-&gt;m</td>
</tr>
<tr>
<td>Output</td>
<td>Может быть разыменован как <i>lvalue</i> для использования слева от знака присваивания</td>
<td>*a = t<br>
*a++ = t</td>
</tr>
<tr>
<td></td>
<td>Может быть скопирован и использован для повторного обхода</td>
<td>X a(b);<br>
++a == ++b</td>
</tr>
<tr>
<td colspan="2"></td>
<td>Может быть уменьшен на единицу</td>
<td>--a<br>
a--<br>
*a--</td>
</tr>
<tr>
<td colspan="3" rowspan="4"></td>
<td>Поддерживает арифметические операции + и -</td>
<td>a + n<br>
n + a<br>
a — n<br>
a — b</td>
</tr>
<tr>
<td>Поддерживает сравнения (&lt;, &gt;, &lt;= and &gt;=) между итераторами </td>
<td>a &lt; b<br>
a &gt; b<br>
a &lt;= b<br>
a &gt;= b</td>
</tr>
<tr>
<td>Поддерживает операции увеличения += и уменьшения -=</td>
<td>a += n<br>
a -= n</td>
</tr>
<tr>
<td>Поддерживает разыменование по индексу ([])</td>
<tbody><tr>
<th colspan="4">Категория итератора</th>
<th>Характеристика</th>
<th>Валидное выражение</th>
</tr>
<tr>
<td colspan="4" rowspan="2">все категории</td>
<td>Может быть скопирован и создан по образу и подобию</td>
<td>X b(a);<br>
b = a;</td>
</tr>
<tr>
<td>Может быть увеличен на единицу</td>
<td>++a<br>
a++<br>
*a++</td>
</tr>
<tr>
<td rowspan="9">Random Access</td>
<td rowspan="5">Bidirectional</td>
<td rowspan="4">Forward</td>
<td rowspan="2">Input</td>
<td>Поддерживает сравнение на равенство/неравенство</td>
<td>a == b<br>
a != b</td>
</tr>
<tr>
<td>Может быть разыменован как <i>rvalue</i> только для <i>получения</i> значения</td>
<td>*a<br>
a-&gt;m</td>
</tr>
<tr>
<td>Output</td>
<td>Может быть разыменован как <i>lvalue</i> для использования слева от знака присваивания</td>
<td>*a = t<br>
*a++ = t</td>
</tr>
<tr>
<td></td>
<td>Может быть скопирован и использован для повторного обхода</td>
<td>X a(b);<br>
++a == ++b</td>
</tr>
<tr>
<td colspan="2"></td>
<td>Может быть уменьшен на единицу</td>
<td>--a<br>
a--<br>
*a--</td>
</tr>
<tr>
<td colspan="3" rowspan="4"></td>
<td>Поддерживает арифметические операции + и -</td>
<td>a + n<br>
n + a<br>
a — n<br>
a — b</td>
</tr>
<tr>
<td>Поддерживает сравнения (&lt;, &gt;, &lt;= and &gt;=) между итераторами </td>
<td>a &lt; b<br>
a &gt; b<br>
a &lt;= b<br>
a &gt;= b</td>
</tr>
<tr>
<td>Поддерживает операции увеличения += и уменьшения -=</td>
<td>a += n<br>
a -= n</td>
</tr>
<tr>
<td>Поддерживает разыменование по индексу ([])</td>
<td>a[n]</td>
</tr>
</tbody>
<td>a[n]</td>
</tr>
</tbody>
</table>

Такое разделение появилось неслучайно, и базируется на внутреннем устройстве итерируемых контейнеров. 

Например, для `vector` используется `Random Acess` итератор. Ведь мы можем получать любой элемент контейнера за одну операцию.

Для двусвзяного списка используется `Bidirectional` итератор, для односвязного - `Forward`.

### Duration, timepoint, часы

**Duration** - интервалы времени, **time_point** - моменты времени, **clock** - часы(например системные часы - настоящее время).

Duration есть разность между двумя time_point'ами. time_point - некоторый сохраненный момент времени(переменная, некогда принявшая значение настоящего времни)

