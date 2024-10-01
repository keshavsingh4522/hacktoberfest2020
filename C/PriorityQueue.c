Algorithm Insert(data)
{
    if(itemCount != MAX)
    {
        if(itemCount ==0)
        {
            priority[itemCount++] = data
        }
        else
        {
            for(i= temCount-1;i>=0;i--)
            {
              if(data > priority[i])
                  `priority[i+1] = priority[i];
              else
                break;
            }
            priority[i+1] = data;
            itemCount++;
        }
    }
}

Algorithm remove()
{
    if(itemCount == 0)
        return -1
    else
        return priority[--itemCount];
}
