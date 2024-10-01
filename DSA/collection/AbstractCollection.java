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
public abstract class AbstractCollection implements Collection {

protected AbstractCollection() {
}

@Override
public abstract boolean add(Object object);

@Override
public boolean isEmpty() {
    return (size() == 0);
}

@Override
public abstract Iterator iterator();

public boolean remove(Object object) {
    Iterator it = iterator();
    if (object == null) {
        while (it.hasNext()) {
            if (it.next() == null) {
                it.remove();
                return true;
            }
        }
    } else {
        while (it.hasNext()) {
            if (object.equals(it.next())) {
                it.remove();
                return true;
            }
        }
    }
    return false;
}

@Override
public abstract int size();

@Override
public boolean contains(Object object) {
    Iterator it = iterator();
    if (object == null) {
        while (it.hasNext()) {
            if (it.next() == null) {
                return true;
            }
        }
    } else {
        while (it.hasNext()) {
            if (object.equals(it.next())) {
                return true;
            }
        }
    }
    return false;
}

@Override
public String toString() {
    if (isEmpty()) {
        return "[ ]";
    }
    Iterator it = iterator();
    StringBuffer buffer = new StringBuffer("[" + it.next());
    while (it.hasNext()) {
        buffer.append("," + it.next());
    }
    return (buffer + "]");
}

@Override
public void clear() {
    for (Iterator it = iterator(); it.hasNext();) {
        it.next();
        it.remove();
    }
}

}
