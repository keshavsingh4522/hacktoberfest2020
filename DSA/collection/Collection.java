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
public interface Collection {
    public boolean add(Object object);
    public void clear();
    public boolean contains(Object object);
    public boolean isEmpty();
    public Iterator iterator();
    public boolean remove(Object object);
    public int size();
}
