# Z++

## Questions

1.

```
function subtract($x, $y)
{
    $x <- add($x, -$y);
    print ($x);
}

```

2.

```
function multiply($x, $y)
{
    $multi <- 0;
    while (not($y < 1))
    {
        $multi <- add($multi, $x);
        $y <- subtract($y, 1);
    }
    print($multi);
}


```

3.

```
function multiply($x, $y)
{
    $multi <- 0;
    $multi <- add($multi, $x);
    $y <- subtract($y, 1);
    if (not($y < 1))
    {
        multiply($x, $y);
    }
    else
    {
        return $multi;
    }
    print($multi);
}


```

## Debrief

1. NA

2. 25 min
