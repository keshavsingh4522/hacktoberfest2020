    public static int[] BubbleSort(int[] arrayOfValues)
    {
        var swapOccurred = false;
        for (var i = 0; i < arrayOfValues.Length; i++)
        {
            if (i == arrayOfValues.Length - 1)
                continue;
            if (arrayOfValues[i] > arrayOfValues[i + 1])
            {
                var current = arrayOfValues[i];
                var next = arrayOfValues[i + 1];
                arrayOfValues[i] = next;
                arrayOfValues[i + 1] = current;
                swapOccurred = true;
            }
        }
        if (swapOccurred)
        {
            BubbleSort(arrayOfValues);
        }

        return arrayOfValues;
    }
