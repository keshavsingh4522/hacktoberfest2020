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
public class LinkedCollection extends AbstractCollection {

private int size;
private Node head = new Node();

@Override
public boolean add(Object object) {
    head.previous = head.previous.next = new Node(object, head.previous, head);
    size++;
    return true;
}

class Node {

private Object object;
private Node previous, next;

public Node() {
    previous = this;
    next = this;
}

public Node(Object object, Node previous, Node next) {
    this.object = object;
    this.previous = previous;
    this.next = next;
}
}

@Override

public Iterator iterator() {

    return new Iterator() {
    private boolean okToRemove = false;
    Node cursor = head.next;

    @Override
    public boolean hasNext() {
        return (cursor != head);
    }

    @Override
    public Object next() {
        if (cursor == head) {
            throw new RuntimeException();
        }
        okToRemove = true;
        Object obj = cursor.object;
        cursor = cursor.next;
        return obj;
    }

    @Override
    public void remove() {
        if (!okToRemove) {
            throw new IllegalStateException();
        }
        cursor.previous = cursor.previous.previous;
        cursor.previous.next = cursor;
        size--;
        okToRemove = false;
    }
    };
}

@Override
public int size() {
    return size;
}

}
