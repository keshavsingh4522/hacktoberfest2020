/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package collection;

/**
 *
 * @author Zohaib Hassan Soomro
 */
public class ArrayCollection extends AbstractCollection {

private final int INITIAL_LENGTH = 15;
private int size;
private Object[] a = new Object[INITIAL_LENGTH];

@Override
public boolean add(Object object) {
    if (size == a.length) {
        resizeArray();
    }
    a[size++] = object;
    return true;
}

@Override
public int size() {
    return size;
}

@Override
public Iterator iterator() {
    return new Iterator() {
    private int i = 0;    //index of current element
    private boolean okToRemove = false;

    @Override
    public boolean hasNext() {
        return (i < size);
    }

    @Override
    public Object next() {
        if (i == size) {
            throw new RuntimeException();
        }
        okToRemove = true;
        return a[i++];
    }

    @Override
    public void remove() {
        if (!okToRemove) {
            throw new IllegalStateException();
        }
        a[--i] = a[--size];
        okToRemove = false;
    }
    };
}

public void resizeArray() {
    Object[] aa = a;
    a = new Object[2 * aa.length];
    System.arraycopy(aa, 0, a, 0, size);
}

}
