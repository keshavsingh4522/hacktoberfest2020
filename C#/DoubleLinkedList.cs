using System;
using System.Text;

namespace DoubleLinkedList
{
    public class DoubleLink
    {
        public string Title { get; set; }
        public DoubleLink PreviousLink { get; set; }
        public DoubleLink NextLink { get; set; }

        public DoubleLink(string title)
        {
            Title = title;
        }

        public override string ToString()
        {
            return Title;
        }
    }

    public class DoubleLinkedList
    {
        private DoubleLink _first;

        public bool IsEmpty
        {
            get { return _first == null; }
        }

        public DoubleLinkedList()
        {
            _first = null;
        }

        public DoubleLink Insert(string title)
        {
            // Creates a link, sets its link to the first item and then makes this the first item in the list.
            DoubleLink link = new DoubleLink(title);
            link.NextLink = _first;
            if (_first != null)
                _first.PreviousLink = link;
            _first = link;
            return link;
        }

        public DoubleLink Delete()
        {
            // Gets the first item, and sets it to be the one it is linked to
            DoubleLink temp = _first;
            if (_first != null)
            {
                _first = _first.NextLink;
                if (_first != null)
                    _first.PreviousLink = null;
            }

            return temp;
        }

        public override string ToString()
        {
            DoubleLink currentLink = _first;
            StringBuilder builder = new StringBuilder();
            while (currentLink != null)
            {
                builder.Append(currentLink);
                currentLink = currentLink.NextLink;
            }

            return builder.ToString();
        }

        public void InsertAfter(DoubleLink link, string title)
        {
            if (link == null || string.IsNullOrEmpty(title))
                return;
            DoubleLink newLink = new DoubleLink(title);
            newLink.PreviousLink = link;
            // Update the 'after' link's next reference, so its previous points to the new one
            if (link.NextLink != null)
                link.NextLink.PreviousLink = newLink;
            // Steal the next link of the node, and set the after so it links to our new one
            newLink.NextLink = link.NextLink;
            link.NextLink = newLink;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            DoubleLinkedList list = new DoubleLinkedList();
            list.Insert("1");
            list.Insert("2");
            list.Insert("3");

            DoubleLink link4 = list.Insert("4");
            list.Insert("5");
            Console.WriteLine("List: " + list);

            list.InsertAfter(link4, "[4a]");
            Console.WriteLine("List: " + list);
            Console.Read();
        }
    }
}
