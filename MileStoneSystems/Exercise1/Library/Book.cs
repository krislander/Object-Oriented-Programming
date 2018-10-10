using System;
using System.Collections.Generic;
using System.Text;

namespace Exercise1.Library
{
    class Book:Item,IDownloadable
    {
        private string author;
        private int pages;

        public Book(string Author, int Pages, string title, string isbn)
        {
            Author = author;
            Pages = pages;
        }

        public string Author
        {
            get { return author; }
            set { author = value; }
        }

        public int Pages
        {
            get { return pages; }
            set { pages = value; }
        }

        public void IsDownloadable(Item item)
        {
            //check if it is downloadable
        }
    }
}
