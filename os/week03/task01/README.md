Попробуйте решить задачу в общем случае. В первой строке вам дается число задач **N**.
В следующей строке идет описание задач, для каждой задачи вам дана ее продолжительность - `T_i`
(где `i` - это номер задачи, от `0` до `N−1` не включительно).

На выход вам требуется вывести номера задач (задачи нумеруются с `0`)
в порядке, который минимизирует среднее время ожидания завершения задачи, как это было объяснено ранее.

Гарантируется, что `0 < N ≤ 10000` и `0 < T_i ≤ 10000` и все числа целые.

### Sample Input:

```
3
9 7 3
```

### Sample Output:

```
2 1 0
```